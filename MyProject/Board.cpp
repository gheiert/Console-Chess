#include "Board.h"
#include "utils.h"

Board::Board()
{
    board[0][0] = Piece(PieceType::Rook, Color::Black, 0, "bR1");
    board[0][1] = Piece(PieceType::Knight, Color::Black, 0, "bN1");
    board[0][2] = Piece(PieceType::Bishop, Color::Black, 0, "bB1");
    board[0][3] = Piece(PieceType::Queen, Color::Black, 0, "bQ1");
    board[0][4] = Piece(PieceType::King, Color::Black, 0, "bK");
    board[0][5] = Piece(PieceType::Bishop, Color::Black, 1, "bB2");
    board[0][6] = Piece(PieceType::Knight, Color::Black, 1, "bN2");
    board[0][7] = Piece(PieceType::Rook, Color::Black, 1, "bR2");

    for (int j = 0; j < 8; j++)
    {
        board[1][j] = Piece(PieceType::Pawn, Color::Black, j, "bP" + std::to_string(j));
    }

    for (int i = 2; i < 6; i++) 
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = Piece();
        }
    }

    for (int j = 0; j < 8; j++)
    {
        board[6][j] = Piece(PieceType::Pawn, Color::White, j, "wP" + std::to_string(j));
    }

    board[7][0] = Piece(PieceType::Rook, Color::White, 0, "wR1");
    board[7][1] = Piece(PieceType::Knight, Color::White, 0, "wN1");
    board[7][2] = Piece(PieceType::Bishop, Color::White, 0, "wB1");
    board[7][3] = Piece(PieceType::Queen, Color::White, 0, "wQ1");
    board[7][4] = Piece(PieceType::King, Color::White, 0, "wK");
    board[7][5] = Piece(PieceType::Bishop, Color::White, 1, "wB2");
    board[7][6] = Piece(PieceType::Knight, Color::White, 1, "wN2");
    board[7][7] = Piece(PieceType::Rook, Color::White, 1, "wR2");
}

Board::~Board()
{
}

void Board::printBoard()
{
    std::string colLabels = "   a   b   c   d   e   f   g   h";
    std::cout << colLabels << '\n';
    std::cout << " +---+---+---+---+---+---+---+---+\n";
    std::cout << " |   |   |   |   |   |   |   |   |\n";
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0 && i > 0)
        {
            std::cout << " |   |   |   |   |   |   |   |   |\n";
        }
        if (i % 2 == 1)
        {
            std::cout << " |   |   |   |   |   |   |   |   |\n";
        }
        std::cout << 8 - i << "|";
        for (int j = 0; j < 8; j++)
        {
            Piece p = board[i][j];
            if (p.m_type == PieceType::Empty)
            {
                std::cout << " . |";
            }
            else
            {
                char c = '?';
                switch (p.m_type)
                {
                case PieceType::King:
                    c = 'K';
                    break;
                case PieceType::Queen:
                    c = 'Q';
                    break;
                case PieceType::Rook:
                    c = 'R';
                    break;
                case PieceType::Knight:
                    c = 'N';
                    break;
                case PieceType::Bishop:
                    c = 'B';
                    break;
                case PieceType::Pawn:
                    c = 'P';
                    break;
                default:
                    std::cout << "This is a bug!";
                    break;
                }

                if (p.m_color == Color::Black)
                {
                    c = static_cast<char>(std::tolower(c));
                }
                std::cout << " " << c << " |";
            }
        }
        std::cout << " " << 8 - i << "\n";
        std::cout << " |___|___|___|___|___|___|___|___|\n";
    }
    std::cout << " +---+---+---+---+---+---+---+---+\n";
    std::cout << colLabels << "\n";
}

void Board::displayCapturedPieces(Color color)
{
    if (color == Color::White)
    {
        std::cout << std::setw(100) << std::right << "Black has captured the following white pieces: " << std::endl;
        for (int i = 0; i < whiteIndex; i++)
        {
            std::cout << std::setw(100) << std::right << capturedWhitePieces[i].m_name << ", ";
        }
    }
    else
    {
        std::cout << std::setw(100) << std::right << "White has captured the following black pieces: " << std::endl;
        for (int i = 0; i < blackIndex; i++)
        {
            std::cout << std::setw(100) << std::right << capturedBlackPieces[i].m_name << ", ";
        }
    }
    std::cout << std::endl;
}

const Piece(&Board::getBoard() const)[8][8]
{
    return board;
}

const std::vector<Move>(& Board::getValidComputerMoves() const)
{
    return validComputerMoves;
}

const std::vector<Move>(&Board::getValidPlayerMoves() const)
{
    return validPlayerMoves;
}

void Board::setComputersTurn()
{
    isPlayersTurn = false;
}

Color Board::getCurrentTurn() const
{
    return currentTurn;
}

void Board::switchTurn()
{
    currentTurn = (currentTurn == Color::White) ? Color::Black : Color::White;
}

bool Board::isHorizPathClear(int startCol, int endCol, int row, const Piece(&board)[8][8])
{
    if (startCol < endCol)
    {
        for (int col = startCol + 1; col < endCol; col++)
        {
            if (board[row][col].m_type != PieceType::Empty)
            {
                return false;
            }
        }
    }
    else if (startCol > endCol)
    {
        for (int col = startCol - 1; col > endCol; col--)
        {
            if (board[row][col].m_type != PieceType::Empty)
            {
                return false;
            }
        }
    }

    return true;
}

bool Board::isVertPathClear(int startRow, int endRow, int col, const Piece(&board)[8][8])
{
    // Down
    if (startRow < endRow)
    {
        for (int row = startRow + 1; row < endRow; row++)
        {
            if (board[row][col].m_type != PieceType::Empty)
            {
                return false;
            }
        }
    }
    // Up
    else if (startRow > endRow)
    {
        for (int row = startRow - 1; row > endRow; row--)
        {
            if (board[row][col].m_type != PieceType::Empty)
            {
                return false;
            }
        }
    }

    return true;
}

bool Board::isDiagPathClear(int startRow, int endRow, int startCol, int endCol, const Piece(&board)[8][8])
{
    int rowDelta = (startRow < endRow) ? 1 : -1; // Determine if moving up (-1) or down (+1)
    int colDelta = (startCol < endCol) ? 1 : -1; // Determine if moving left (-1) or right (+1)

    int row = startRow + rowDelta;
    int col = startCol + colDelta;

    // Loop through the path excluding endpoints
    while (row != endRow || col != endCol)
    {
        if (board[row][col].m_type != PieceType::Empty)
        {
            return false;
        }
        row += rowDelta;
        col += colDelta;
    }

    return true;
}

bool Board::simulateMove(const Piece(&board)[8][8], Piece(&tempBoard)[8][8], const Move& move)
{
    std::memcpy(tempBoard, board, sizeof(Piece) * 64);

    // Simulate the move on the temporary board
    tempBoard[move.toRow][move.toCol] = tempBoard[move.fromRow][move.fromCol];
    tempBoard[move.fromRow][move.fromCol] = Piece(); // Clear the original position !!!

    return true;
}

bool Board::isValidMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& piece, const Piece(&board)[8][8])
{
    const Piece& destination = board[toRow][toCol];

    // Checks if requested move is on the board
    if (toRow < 0 || toRow > 7
        || toCol < 0 || toCol > 7)
    {
        return false;
    }
    // Checks if the requested move is different from starting position
    if (fromRow == toRow
        && fromCol == toCol)
    {
        return false;
    }
    // Checks that the request is moving the correct color of piece
    if (piece.m_color != currentTurn)
    {
        //std::cout << "Players may not move their opponent's pieces.\n";
        return false;
    }
    
    // Validate specific piece move
    bool isValidPieceMove = false;
    switch (piece.m_type)
    {
    case PieceType::Pawn:
        isValidPieceMove = isValidPawnMove(fromRow, fromCol, toRow, toCol, piece, destination);
        break;

    case PieceType::Rook:
        isValidPieceMove = isValidRookMove(fromRow, fromCol, toRow, toCol, piece, destination, board);
        break;

    case PieceType::Knight:
        isValidPieceMove = isValidKnightMove(fromRow, fromCol, toRow, toCol, piece, destination);
        break;

    case PieceType::Bishop:
        isValidPieceMove = isValidBishopMove(fromRow, fromCol, toRow, toCol, piece, destination, board);
        break;

    case PieceType::Queen:
        isValidPieceMove = isValidQueenMove(fromRow, fromCol, toRow, toCol, piece, destination, board);
        break;

    case PieceType::King:
        isValidPieceMove = isValidKingMove(fromRow, fromCol, toRow, toCol, piece, destination);
        break;

    default:
        std::cout << "No piece at this location";
        return false;
    }

    if (!isValidPieceMove) {
        return false;
    }

    // Check if the move leaves the player in check by simulating the move on a temporary board
    Piece tempBoard[8][8];
    Move move = { fromRow,fromCol,toRow,toCol };
    simulateMove(board, tempBoard, move);

    // Generate opponents moves based on simulated board state
    std::vector<Move> tempMoves;
    if (currentTurn == Color::White) {
        setPossibleMoves(Color::Black, tempMoves);
    }
    else
    {
        setPossibleMoves(Color::White, tempMoves);
    }

    // Check if the player is still in check after the move
    if (isPlayerInCheck(currentTurn, tempMoves, tempBoard)) {
        std::cout << "Illegal move, this move would leave you in check!" << std::endl;
        return false; // Illegal move, leaves the player in check
    }

    // Check if the player is currently in check and the move resolves this
    if (isPlayersTurn == true)
    {
        if (isPlayerInCheck(currentTurn, validComputerMoves, board) && !isPlayerInCheck(currentTurn, tempMoves, tempBoard)) {
            return true; // The move takes the player out of check
        }
    }
    else
    {
        if (isPlayerInCheck(currentTurn, validPlayerMoves, board) && !isPlayerInCheck(currentTurn, tempMoves, tempBoard)) {
            return true; // The move takes the computer out of check
        }
    }

    return true;
}

bool Board::isValidPawnMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& pawn, const Piece& destination)
{
    int m_dir = (pawn.m_color == Color::White) ? -1 : 1;
    int startRow = (pawn.m_color == Color::White) ? 6 : 1;

    // Standard movement by 1
    if (toCol == fromCol
        && toRow == (fromRow + m_dir)
        && destination.m_type == PieceType::Empty)
    {
        return true;
    }

    // Initial movement by two
    if (fromRow == startRow
        && toCol == fromCol
        && toRow == (fromRow + 2 * m_dir)
        && destination.m_type == PieceType::Empty)
    {
        return true;
    }

    // Capturing a piece
    if (abs(toCol - fromCol == 1)
        && toRow == (fromRow + m_dir)
        && destination.m_type != PieceType::Empty
        && destination.m_color != pawn.m_color)
    {
        return true;
    }

    return false;
}

bool Board::isValidRookMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& rook, const Piece& destination, const Piece(&board)[8][8])
{
    // Horizontal Move or Capture
    if (toRow == fromRow && isHorizPathClear(fromCol, toCol, fromRow, board))
    { 
        if (destination.m_type == PieceType::Empty || destination.m_color != rook.m_color)
        {
            return true;
        }
    }

    // Vertical Move or Capture
    if (toCol == fromCol && isVertPathClear(fromRow, toRow, fromCol, board))
    { 
        if (destination.m_type == PieceType::Empty || destination.m_color != rook.m_color)
        {
            return true;
        }
    }

    return false;
}

bool Board::isValidKnightMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& knight, const Piece& destination)
{
    // Up 'L' Move or Capture
    if (toRow == (fromRow - 2) && (toCol == (fromCol + 1) || toCol == (fromCol - 1)))
    {
        if (destination.m_type == PieceType::Empty || destination.m_color != knight.m_color)
        {
            return true;
        }
    }

    // Down 'L' Move or Capture
    if (toRow == (fromRow + 2) && (toCol == (fromCol + 1) || toCol == (fromCol - 1)))
    { 
        if (destination.m_type == PieceType::Empty || destination.m_color != knight.m_color)
        {
            return true;
        }
    }

    // Right 'L' Move or Capture
    if (toCol == (fromCol + 2) && (toRow == (fromRow + 1) || toRow == (fromRow - 1)))
    {
        if (destination.m_type == PieceType::Empty || destination.m_color != knight.m_color)
        {
            return true;
        }
    }

    // Left 'L' Move or Capture
    if (toCol == (fromCol - 2) && (toRow == (fromRow + 1) || toRow == (fromRow - 1)))
    { 
        if (destination.m_type == PieceType::Empty || destination.m_color != knight.m_color)
        {
            return true;
        }
    }

    return false;
}

bool Board::isValidBishopMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& bishop, const Piece& destination, const Piece(&board)[8][8])
{
    // Diagonal Move or Capture
    if (isDiagPathClear(fromRow, toRow, fromCol, toCol, board))
    { 
        if (destination.m_type == PieceType::Empty || destination.m_color != bishop.m_color)
        {
            return true;
        }
    }

    return false;
}

bool Board::isValidQueenMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& queen, const Piece& destination, const Piece(&board)[8][8])
{
    // Horizontal Move or Capture
    if (toRow == fromRow && isHorizPathClear(fromCol, toCol, fromRow, board))
    { 
        if (destination.m_type == PieceType::Empty || destination.m_color != queen.m_color)
        {
            return true;
        }
    }

    // Vertical Move or Capture
    if (toCol == fromCol && isVertPathClear(fromRow, toRow, fromCol, board))
    { 
        if (destination.m_type == PieceType::Empty || destination.m_color != queen.m_color)
        {
            return true;
        }
    }

    // Diagonal Move or Capture
    if (isDiagPathClear(fromRow, toRow, fromCol, toCol, board))
    { 
        if (destination.m_type == PieceType::Empty || destination.m_color != queen.m_color)
        {
            return true;
        }
    }

    return false;
}

bool Board::isValidKingMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& king, const Piece& destination)
{
    // Vertical Move or Capture
    if (fromCol == toCol && (fromRow - 1 == toRow || fromRow + 1 == toRow))
    {
        if (destination.m_type == PieceType::Empty || destination.m_color != king.m_color)
        {
            return true;
        }
    }

    // Horizontal Move or Capture
    if (fromRow == toRow && (fromCol - 1 == toCol || fromCol + 1 == toCol))
    {
        if (destination.m_type == PieceType::Empty || destination.m_color != king.m_color)
        {
            return true;
        }
    }

    // Diagonal Move or Capture
    if ((fromRow - 1 == toRow && fromCol + 1 == toCol) ||
        (fromRow + 1 == toRow && fromCol + 1 == toCol) ||
        (fromRow + 1 == toRow && fromCol - 1 == toCol) ||
        (fromRow - 1 == toRow && fromCol - 1 == toCol))
    {
        if (destination.m_type == PieceType::Empty || destination.m_color != king.m_color)
        {
            return true;
        }
    }

    return false;
}

bool Board::readPlayerMove(int fromRow, int fromCol, int toRow, int toCol)
{
    isPlayersTurn = true;
    Piece piece = board[fromRow][fromCol];
    if (!isValidMove(fromRow, fromCol, toRow, toCol, piece, board))
    {
        std::cout << "Invalid move!\n";
        return false;
    }

    return true;
}

void Board::setPossibleMoves(Color color, std::vector<Move>& moves)
{
    moves.clear();

    for (int r1 = 0; r1 < 8; r1++)
    {
        for (int c1 = 0; c1 < 8; c1++)
        {
            const Piece& piece = board[r1][c1];

            if (piece.m_color == color)
            {
                for (int r2 = 0; r2 < 8; r2++)
                {
                    for (int c2 = 0; c2 < 8; c2++)
                    {
                        if (isValidMove(r1, c1, r2, c2, piece, board))
                        {
                            moves.push_back({ r1, c1, r2, c2 });
                        }
                    }
                }
            }
        }
    }
}

Move Board::selectRandomMove(const std::vector<Move>& moves)
{
    std::srand(std::time(nullptr)); // Seed the random number generator
    int randomIndex = abs(std::rand()) % moves.size();
    return moves[randomIndex];
}

void Board::makeMove(int fromRow, int fromCol, int toRow, int toCol)
{
    Piece piece = board[fromRow][fromCol];
    Piece& destination = board[toRow][toCol];

    // Bounds checking
    if (fromRow < 0 || fromRow >= 8 || fromCol < 0 || fromCol >= 8 ||
        toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8)
    {
        std::cerr << "Error: Index out of bounds during move." << std::endl;
        return;
    }

    if (destination.m_type != PieceType::Empty && destination.m_color != piece.m_color)
    {
        destination.m_captured = true;
        std::cout << std::setw(100) << std::right << colorToString(destination.m_color) + pieceTypeToString(destination.m_type) + " was captured by "
            + colorToString(piece.m_color) + pieceTypeToString(piece.m_type) + "!" << std::endl;

        if (destination.m_color == Color::White)
        {
            capturedWhitePieces[whiteIndex++] = destination;
        }
        else
        {
            capturedBlackPieces[blackIndex++] = destination;
        }
    }
    board[toRow][toCol] = piece;
    board[fromRow][fromCol] = Piece();

    switchTurn();
}

bool Board::isPlayerInCheck(Color color, const std::vector<Move>& opponentMoves, const Piece(&board)[8][8])
{
    int kingRow = -1, kingCol = -1;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j].m_type == PieceType::King && board[i][j].m_color == color)
            {
                kingRow = i;
                kingCol = j;
                break;
            }
        }
    }

    if (kingRow == -1 || kingCol == -1)
    {
        throw std::runtime_error("King not found on the board.");
    }

    for (const Move& move : opponentMoves)
    {
        if (move.toRow == kingRow && move.toCol == kingCol)
        {
            std::cout << colorToString(color) << " is in check!" << std::endl;
            return true;
        }
    }

    return false;
}

bool Board::isCheckmate(Color color)
{
    if (isPlayersTurn)
    {
        if (!isPlayerInCheck(color, validComputerMoves, board))
        {
            return false;
        }
    }
    else
    {
        if (!isPlayerInCheck(color, validPlayerMoves, board))
        {
            return false;
        }
    }

    // Generate all possible moves for the player
    std::vector<Move> playerMoves;
    setPossibleMoves(color, playerMoves);

    // Check if any move can get the player out of check
    // for each move in the set of moves
    for (const Move& move : playerMoves) {
        Piece tempBoard[8][8];
        simulateMove(board, tempBoard, move);

        // If the move gets the player out of check, it’s not checkmate
        std::vector<Move> opponentMoves;
        Color opponentColor = (color == Color::White) ? Color::Black : Color::White;
        setPossibleMoves(opponentColor, opponentMoves);

        if (!isPlayerInCheck(color, opponentMoves, tempBoard)) {
            return false;
        }
    }

    std::cout << "Checkmate! " << colorToString(color) << " has no legal moves. " << (color == Color::White ? "Black" : "White") << " wins!" << std::endl;
    return true; // No legal move gets the player out of check, checkmate
}

bool Board::isStalemate(Color color)
{
    if (isPlayersTurn)
    {
        if (!isPlayerInCheck(color, validComputerMoves, board))
        {
            return false;
        }
    }
    else
    {
        if (!isPlayerInCheck(color, validPlayerMoves, board))
        {
            return false;
        }
    }

    // Generate all possible moves for the player
    std::vector<Move> playerMoves;
    setPossibleMoves(color, playerMoves);

    if (playerMoves.empty()) // No legal moves available, stalemate
    {
        std::cout << colorToString(color) << " has no legal moves, but they are not in check. Stalemate!" << std::endl;
        return true;
    }

    return false;
}
