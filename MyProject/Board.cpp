#include "Board.h"
//#include "Board.h"
//#include "utils.h"
//
//Board::Board()
//{
//    board[0][0] = Piece(PieceType::Rook, Color::Black, 0, "bR1");
//    board[0][1] = Piece(PieceType::Knight, Color::Black, 0, "bN1");
//    board[0][2] = Piece(PieceType::Bishop, Color::Black, 0, "bB1");
//    board[0][3] = Piece(PieceType::Queen, Color::Black, 0, "bQ1");
//    board[0][4] = Piece(PieceType::King, Color::Black, 0, "bK");
//    board[0][5] = Piece(PieceType::Bishop, Color::Black, 1, "bB2");
//    board[0][6] = Piece(PieceType::Knight, Color::Black, 1, "bN2");
//    board[0][7] = Piece(PieceType::Rook, Color::Black, 1, "bR2");
//
//    for (int j = 0; j < 8; j++)
//    {
//        board[1][j] = Piece(PieceType::Pawn, Color::Black, j, "bP" + std::to_string(j));
//    }
//
//    for (int i = 2; i < 6; i++) 
//    {
//        for (int j = 0; j < 8; j++)
//        {
//            board[i][j] = Piece();
//        }
//    }
//
//    for (int j = 0; j < 8; j++)
//    {
//        board[6][j] = Piece(PieceType::Pawn, Color::White, j, "wP" + std::to_string(j));
//    }
//
//    board[7][0] = Piece(PieceType::Rook, Color::White, 0, "wR1");
//    board[7][1] = Piece(PieceType::Knight, Color::White, 0, "wN1");
//    board[7][2] = Piece(PieceType::Bishop, Color::White, 0, "wB1");
//    board[7][3] = Piece(PieceType::Queen, Color::White, 0, "wQ1");
//    board[7][4] = Piece(PieceType::King, Color::White, 0, "wK");
//    board[7][5] = Piece(PieceType::Bishop, Color::White, 1, "wB2");
//    board[7][6] = Piece(PieceType::Knight, Color::White, 1, "wN2");
//    board[7][7] = Piece(PieceType::Rook, Color::White, 1, "wR2");
//}
//
//Board::~Board()
//{
//}
//
//void Board::printBoard()
//{
//    std::string colLabels = "   a   b   c   d   e   f   g   h";
//    std::cout << colLabels << '\n';
//    std::cout << " +---+---+---+---+---+---+---+---+\n";
//    std::cout << " |   |   |   |   |   |   |   |   |\n";
//    for (int i = 0; i < 8; i++)
//    {
//        if (i % 2 == 0 && i > 0)
//        {
//            std::cout << " |   |   |   |   |   |   |   |   |\n";
//        }
//        if (i % 2 == 1)
//        {
//            std::cout << " |   |   |   |   |   |   |   |   |\n";
//        }
//        std::cout << 8 - i << "|";
//        for (int j = 0; j < 8; j++)
//        {
//            Piece p = board[i][j];
//            if (p.m_type == PieceType::Empty)
//            {
//                std::cout << " . |";
//            }
//            else
//            {
//                char c = '?';
//                switch (p.m_type)
//                {
//                case PieceType::King:
//                    c = 'K';
//                    break;
//                case PieceType::Queen:
//                    c = 'Q';
//                    break;
//                case PieceType::Rook:
//                    c = 'R';
//                    break;
//                case PieceType::Knight:
//                    c = 'N';
//                    break;
//                case PieceType::Bishop:
//                    c = 'B';
//                    break;
//                case PieceType::Pawn:
//                    c = 'P';
//                    break;
//                default:
//                    std::cout << "This is a bug!";
//                    break;
//                }
//
//                if (p.m_color == Color::Black)
//                {
//                    c = static_cast<char>(std::tolower(c));
//                }
//                std::cout << " " << c << " |";
//            }
//        }
//        std::cout << " " << 8 - i << "\n";
//        std::cout << " |___|___|___|___|___|___|___|___|\n";
//    }
//    std::cout << " +---+---+---+---+---+---+---+---+\n";
//    std::cout << colLabels << "\n";
//}
//
//void Board::displayCapturedPieces(Color color)
//{
//    if (color == Color::White)
//    {
//        std::cout << std::setw(100) << std::right << "Black has captured the following white pieces: " << std::endl;
//        for (int i = 0; i < whiteIndex; i++)
//        {
//            std::cout << std::setw(100) << std::right << capturedWhitePieces[i].m_name << ", ";
//        }
//    }
//    else
//    {
//        std::cout << std::setw(100) << std::right << "White has captured the following black pieces: " << std::endl;
//        for (int i = 0; i < blackIndex; i++)
//        {
//            std::cout << std::setw(100) << std::right << capturedBlackPieces[i].m_name << ", ";
//        }
//    }
//    std::cout << std::endl;
//}
//
//const Piece(&Board::getBoard() const)[8][8]
//{
//    return board;
//}
//
//const std::vector<Move>(& Board::getValidComputerMoves() const)
//{
//    return validComputerMoves;
//}
//
//const std::vector<Move>(&Board::getValidPlayerMoves() const)
//{
//    return validPlayerMoves;
//}
//
//void Board::setComputersTurn()
//{
//    isPlayersTurn = false;
//}
//
//Color Board::getCurrentTurn() const
//{
//    return currentTurn;
//}
//
//void Board::switchTurn()
//{
//    currentTurn = (currentTurn == Color::White) ? Color::Black : Color::White;
//}
//
//void Board::simulateMove(const Piece(&board)[8][8], Piece(&tempBoard)[8][8], const Move& move)
//{
//    std::memcpy(tempBoard, board, sizeof(Piece) * 64);
//
//    // Simulate the move on the temporary board
//    tempBoard[move.toRow][move.toCol] = tempBoard[move.fromRow][move.fromCol];
//    tempBoard[move.fromRow][move.fromCol] = Piece(); // Clear the original position !!!
//
//}
//
//bool Board::isValidMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& piece, const Piece(&board)[8][8])
//{
//    const Piece& destination = board[toRow][toCol];
//
//    // Checks if requested move is on the board
//    if (toRow < 0 || toRow > 7
//        || toCol < 0 || toCol > 7)
//    {
//        return false;
//    }
//    // Checks if the requested move is different from starting position
//    if (fromRow == toRow
//        && fromCol == toCol)
//    {
//        return false;
//    }
//    // Checks that the request is moving the correct color of piece
//    if (piece.m_color != currentTurn)
//    {
//        //std::cout << "Players may not move their opponent's pieces.\n";
//        return false;
//    }
//    
//    // Validate specific piece move
//    bool isValidPieceMove = false;
//    switch (piece.m_type)
//    {
//    case PieceType::Pawn:
//        isValidPieceMove = isValidPawnMove(fromRow, fromCol, toRow, toCol, piece, destination);
//        break;
//
//    case PieceType::Rook:
//        isValidPieceMove = isValidRookMove(fromRow, fromCol, toRow, toCol, piece, destination, board);
//        break;
//
//    case PieceType::Knight:
//        isValidPieceMove = isValidKnightMove(fromRow, fromCol, toRow, toCol, piece, destination);
//        break;
//
//    case PieceType::Bishop:
//        isValidPieceMove = isValidBishopMove(fromRow, fromCol, toRow, toCol, piece, destination, board);
//        break;
//
//    case PieceType::Queen:
//        isValidPieceMove = isValidQueenMove(fromRow, fromCol, toRow, toCol, piece, destination, board);
//        break;
//
//    case PieceType::King:
//        isValidPieceMove = isValidKingMove(fromRow, fromCol, toRow, toCol, piece, destination);
//        break;
//
//    default:
//        std::cout << "No piece at this location";
//        return false;
//    }
//
//    if (!isValidPieceMove) {
//        return false;
//    }
//}
//
//bool Board::isMoveSafe(int fromRow, int fromCol, int toRow, int toCol, const Piece(&board)[8][8], Color currentColor)
//{
//    Piece tempBoard[8][8];
//    Move move = { fromRow, fromCol, toRow, toCol };
//    simulateMove(board, tempBoard, move);
//
//    // Create and populate opponentMovesCurrent vector based off the current (non-simulated) board state
//    std::vector<Move> opponentMovesCurrent;
//    setPossibleTemporaryMoves(currentColor == Color::White ? Color::Black : Color::White, opponentMovesCurrent, board);
//
//    // Create and populate opponentMovesSimulated vector based off of simulated move
//    std::vector<Move> opponentMovesSimulated;
//    setPossibleTemporaryMoves(currentColor == Color::White ? Color::Black : Color::White, opponentMovesSimulated, tempBoard);
//
//    // Checks if the currentColor's king position is in the opponentMoves vector
//    if (isPlayerInCheck(currentColor, opponentMovesSimulated, tempBoard)) 
//    {
//        std::cout << "Illegal move, this move would put you in check!" << std::endl;
//        return false;
//    }
//
//    // Check if the move takes the player out of check
//    if (isPlayersTurn) 
//    {
//        // If the player is currently in check and the simulated move takes them out of check
//        if (isPlayerInCheck(currentColor, opponentMovesCurrent, board) && !isPlayerInCheck(currentColor, opponentMovesSimulated, tempBoard)) 
//        {
//            return true; // The move takes the player out of check
//        }
//    }
//    else 
//    {
//        // If the CPU is currently in check and the simulated move takes them out of check
//        if (isPlayerInCheck(currentColor, opponentMovesCurrent, board) && !isPlayerInCheck(currentColor, opponentMovesSimulated, tempBoard))
//        {
//            return true; // The move takes the computer out of check
//        }
//    }
//
//    return true;
//}
//
//bool Board::isValidPawnMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& pawn, const Piece& destination)
//{
//    int m_dir = (pawn.m_color == Color::White) ? -1 : 1;
//    int startRow = (pawn.m_color == Color::White) ? 6 : 1;
//
//    // Standard movement by 1
//    if (toCol == fromCol
//        && toRow == (fromRow + m_dir)
//        && destination.m_type == PieceType::Empty)
//    {
//        return true;
//    }
//
//    // Initial movement by two
//    if (fromRow == startRow
//        && toCol == fromCol
//        && toRow == (fromRow + 2 * m_dir)
//        && destination.m_type == PieceType::Empty)
//    {
//        return true;
//    }
//
//    // Capturing a piece
//    if (abs(toCol - fromCol == 1)
//        && toRow == (fromRow + m_dir)
//        && destination.m_type != PieceType::Empty
//        && destination.m_color != pawn.m_color)
//    {
//        return true;
//    }
//
//    return false;
//}
//
//bool Board::isValidBishopMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& bishop, const Piece& destination, const Piece(&board)[8][8])
//{
//    // Diagonal Move or Capture
//    if (isDiagPathClear(fromRow, toRow, fromCol, toCol, board))
//    { 
//        if (destination.m_type == PieceType::Empty || destination.m_color != bishop.m_color)
//        {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//bool Board::isValidQueenMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& queen, const Piece& destination, const Piece(&board)[8][8])
//{
//    // Horizontal Move or Capture
//    if (toRow == fromRow && isHorizPathClear(fromCol, toCol, fromRow, board))
//    { 
//        if (destination.m_type == PieceType::Empty || destination.m_color != queen.m_color)
//        {
//            return true;
//        }
//    }
//
//    // Vertical Move or Capture
//    if (toCol == fromCol && isVertPathClear(fromRow, toRow, fromCol, board))
//    { 
//        if (destination.m_type == PieceType::Empty || destination.m_color != queen.m_color)
//        {
//            return true;
//        }
//    }
//
//    // Diagonal Move or Capture
//    if (isDiagPathClear(fromRow, toRow, fromCol, toCol, board))
//    { 
//        if (destination.m_type == PieceType::Empty || destination.m_color != queen.m_color)
//        {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//bool Board::isValidKingMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& king, const Piece& destination)
//{
//    // Vertical Move or Capture
//    if (fromCol == toCol && (fromRow - 1 == toRow || fromRow + 1 == toRow))
//    {
//        if (destination.m_type == PieceType::Empty || destination.m_color != king.m_color)
//        {
//            return true;
//        }
//    }
//
//    // Horizontal Move or Capture
//    if (fromRow == toRow && (fromCol - 1 == toCol || fromCol + 1 == toCol))
//    {
//        if (destination.m_type == PieceType::Empty || destination.m_color != king.m_color)
//        {
//            return true;
//        }
//    }
//
//    // Diagonal Move or Capture
//    if ((fromRow - 1 == toRow && fromCol + 1 == toCol) ||
//        (fromRow + 1 == toRow && fromCol + 1 == toCol) ||
//        (fromRow + 1 == toRow && fromCol - 1 == toCol) ||
//        (fromRow - 1 == toRow && fromCol - 1 == toCol))
//    {
//        if (destination.m_type == PieceType::Empty || destination.m_color != king.m_color)
//        {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//bool Board::readPlayerMove(int fromRow, int fromCol, int toRow, int toCol)
//{
//    isPlayersTurn = true;
//    Piece piece = board[fromRow][fromCol];
//    if (!isValidMove(fromRow, fromCol, toRow, toCol, piece, board) || !isMoveSafe(fromRow, fromCol, toRow, toCol, board, piece.m_color))
//    {
//        std::cout << "Invalid move!\n";
//        return false;
//    }
//
//    return true;
//}
//
//void Board::setPossibleMoves(Color color, std::vector<Move>& moves, const Piece(&board)[8][8])
//{
//    moves.clear();
//    // Debugging
//    std::cout << "Checking the current moves of " << (color == Color::White ? "White" : "Black") << std::endl;
//    for (int r1 = 0; r1 < 8; r1++)
//    {
//        for (int c1 = 0; c1 < 8; c1++)
//        {
//            const Piece& piece = board[r1][c1];
//
//            if (piece.m_color == color)
//            {
//                for (int r2 = 0; r2 < 8; r2++)
//                {
//                    for (int c2 = 0; c2 < 8; c2++)
//                    {
//                        if (isValidMove(r1, c1, r2, c2, piece, board)
//                            && isMoveSafe(r1, c1, r2, c2, board, color))
//                        {
//                            moves.push_back({ r1, c1, r2, c2 });
//                            // Debugging
//                            std::cout << "Move added: from (" << r1 << ", " << c1 << ") to (" << r2 << ", " << c2 << ")" << std::endl;
//                        }
//                    }
//                }
//            }
//        }
//    }
//    // Debugging
//    std::cout << "Total possible moves for " << (color == Color::White ? "White" : "Black") << ": " << moves.size() << std::endl;
//}
//
//void Board::setPossibleTemporaryMoves(Color color, std::vector<Move>& moves, const Piece(&tempBoard)[8][8])
//{
//    moves.clear();
//    // Debugging
//    std::cout << "Checking the future moves of " << (color == Color::White ? "White" : "Black") << std::endl;
//    for (int r1 = 0; r1 < 8; r1++)
//    {
//        for (int c1 = 0; c1 < 8; c1++)
//        {
//            const Piece& piece = board[r1][c1];
//
//            if (piece.m_color == color)
//            {
//                for (int r2 = 0; r2 < 8; r2++)
//                {
//                    for (int c2 = 0; c2 < 8; c2++)
//                    {
//                        if (isValidMove(r1, c1, r2, c2, piece, board))
//                        {
//                            moves.push_back({ r1, c1, r2, c2 });
//                            std::cout << "Move added: from (" << r1 << ", " << c1 << ") to (" << r2 << ", " << c2 << ")" << std::endl;
//                        }
//                    }
//                }
//            }
//        }
//    }
//    std::cout << "Total possible moves for " << (color == Color::White ? "White" : "Black") << ": " << moves.size() << std::endl;
//}
//
//Move Board::selectRandomMove(const std::vector<Move>& moves)
//{
//    std::srand(std::time(nullptr)); // Seed the random number generator
//    int randomIndex = abs(std::rand()) % moves.size();
//    return moves[randomIndex];
//}
//
//void Board::makeMove(int fromRow, int fromCol, int toRow, int toCol)
//{
//    Piece piece = board[fromRow][fromCol];
//    Piece& destination = board[toRow][toCol];
//
//    // Bounds checking
//    if (fromRow < 0 || fromRow >= 8 || fromCol < 0 || fromCol >= 8 ||
//        toRow < 0 || toRow >= 8 || toCol < 0 || toCol >= 8)
//    {
//        std::cerr << "Error: Index out of bounds during move." << std::endl;
//        return;
//    }
//
//    if (destination.m_type != PieceType::Empty && destination.m_color != piece.m_color)
//    {
//        destination.m_captured = true;
//        std::cout << std::setw(100) << std::right << colorToString(destination.m_color) + pieceTypeToString(destination.m_type) + " was captured by "
//            + colorToString(piece.m_color) + pieceTypeToString(piece.m_type) + "!" << std::endl;
//
//        if (destination.m_color == Color::White)
//        {
//            capturedWhitePieces[whiteIndex++] = destination;
//        }
//        else
//        {
//            capturedBlackPieces[blackIndex++] = destination;
//        }
//    }
//    board[toRow][toCol] = piece;
//    board[fromRow][fromCol] = Piece();
//
//    switchTurn();
//}
//
//bool Board::isPlayerInCheck(Color color, const std::vector<Move>& opponentMoves, const Piece(&board)[8][8])
//{
//    int kingRow = -1, kingCol = -1;
//
//    for (int i = 0; i < 8; ++i)
//    {
//        for (int j = 0; j < 8; ++j)
//        {
//            if (board[i][j].m_type == PieceType::King && board[i][j].m_color == color)
//            {
//                kingRow = i;
//                kingCol = j;
//                break;
//            }
//        }
//    }
//
//    if (kingRow == -1 || kingCol == -1)
//    {
//        throw std::runtime_error("King not found on the board.");
//    }
//
//    for (const Move& move : opponentMoves)
//    {
//        if (move.toRow == kingRow && move.toCol == kingCol)
//        {
//            std::cout << colorToString(color) << " is in check!" << std::endl;
//            return true;
//        }
//    }
//
//    return false;
//}
//
//bool Board::isCheckmate(Color color)
//{
//    if (isPlayersTurn)
//    {
//        if (!isPlayerInCheck(color, validComputerMoves, board))
//        {
//            return false;
//        }
//    }
//    else
//    {
//        if (!isPlayerInCheck(color, validPlayerMoves, board))
//        {
//            return false;
//        }
//    }
//
//    // Generate all possible moves for the player
//    std::vector<Move> playerMoves;
//    setPossibleMoves(color, playerMoves, board);
//
//    // Check if any move can get the player out of check
//    // for each move in the set of moves
//    for (const Move& move : playerMoves) {
//        Piece tempBoard[8][8];
//        simulateMove(board, tempBoard, move);
//
//        // If the move gets the player out of check, it’s not checkmate
//        std::vector<Move> opponentMoves;
//        Color opponentColor = (color == Color::White) ? Color::Black : Color::White;
//        setPossibleMoves(opponentColor, opponentMoves, tempBoard);
//
//        if (!isPlayerInCheck(color, opponentMoves, tempBoard)) {
//            return false;
//        }
//    }
//
//    std::cout << "Checkmate! " << colorToString(color) << " has no legal moves. " << (color == Color::White ? "Black" : "White") << " wins!" << std::endl;
//    return true; // No legal move gets the player out of check, checkmate
//}
//
//bool Board::isStalemate(Color color)
//{
//    if (isPlayersTurn)
//    {
//        if (!isPlayerInCheck(color, validComputerMoves, board))
//        {
//            return false;
//        }
//    }
//    else
//    {
//        if (!isPlayerInCheck(color, validPlayerMoves, board))
//        {
//            return false;
//        }
//    }
//
//    // Generate all possible moves for the player
//    std::vector<Move> playerMoves;
//    setPossibleMoves(color, playerMoves, board);
//
//    if (playerMoves.empty()) // No legal moves available, stalemate
//    {
//        std::cout << colorToString(color) << " has no legal moves, but they are not in check. Stalemate!" << std::endl;
//        return true;
//    }
//
//    return false;
//}

Board::Board()
{
    // Initialize board with nullptr for empty squares initially
    for (int i = 2; i < 6; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    board[i][j] = nullptr;
                }
            }
    // Initialize other pieces as needed
}

Board::~Board()
{
}

bool Board::isValidCoordinate(int row, int col) const
{
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

const Piece* Board::getPieceAt(int row, int col) const
{
    if (isValidCoordinate(row,col)) 
    {
        return board[row][col].get();
    }
   
    return nullptr;
}

bool Board::isHorizPathClear(int startRow, int startCol, int endRow, int endCol) const
{
    if (startRow != endRow 
        || !isValidCoordinate(startRow, startCol) 
        || !isValidCoordinate(endRow, endCol))
    {
        return false; // Ensure it's a horizontal path and a valid coordinate
    }

    int step = (endCol > startCol) ? 1 : -1;
    for (int col = startCol + step; col != endCol; col += step) {
        if (getPieceAt(startRow, col) != nullptr
            || !isValidCoordinate(startRow, col)) 
        {
            return false;
        }
    }
    return true;
}

bool Board::isVertPathClear(int startRow, int startCol, int endRow, int endCol) const
{
    if (startCol != endCol
        || !isValidCoordinate(startRow, startCol)
        || !isValidCoordinate(endRow, endCol))
    {
        return false; // Ensure it's a vertical path and a valid coordinate
    }

    int step = (endRow > startRow) ? 1 : -1;
    for (int row = startRow + step; row != endRow; row += step) {
        if (getPieceAt(row, startCol) != nullptr
            || !isValidCoordinate(row, startCol))
        {
            return false;
        }
    }
    return true;
}

bool Board::isDiagPathClear(int startRow, int startCol, int endRow, int endCol) const
{
    if (std::abs(startRow - endRow) != std::abs(startCol - endCol)
        || !isValidCoordinate(startRow, startCol)
        || !isValidCoordinate(endRow, endCol))
    {
        return false; // Ensure it's a diagonal path and a valid coordinate
    }

    int rowDelta = (startRow < endRow) ? 1 : -1; // Determine if moving up (-1) or down (+1)
    int colDelta = (startCol < endCol) ? 1 : -1; // Determine if moving left (-1) or right (+1)
    int row = startRow + rowDelta;
    int col = startCol + colDelta;

    while (row != endRow && col != endCol) {
        if (getPieceAt(row, col) != nullptr
            || !isValidCoordinate(row, col)) 
        { 
            return false;
        }
        row += rowDelta;
        col += colDelta;
    }

    return true;
}

std::vector<std::pair<int, int>> Board::getValidMoves(const Piece& piece, const std::vector<std::pair<int, int>>& possibleMoves, int startRow, int startCol) const
{
	std::vector<std::pair<int, int>> validMoves;

    for (const auto& move : possibleMoves)
    {
        int endRow = move.first;
        int endCol = move.second;

        if (piece.isValidMove(startRow, startCol, endRow, endCol, *this))
        {
            const Piece* target = getPieceAt(endRow, endCol);
            if (!target || target->getColor() != piece.getColor()) // If the square is empty or occupied by an enemy piece
            {
                validMoves.emplace_back(endRow, endCol);
            }
        }
    }

    return validMoves;
}

bool Board::isMoveSafeForKing(const Piece& piece, int startRow, int startCol, int endRow, int endCol) const
{
	return false;
}

std::pair<int, int> Board::getKingPosition(Piece::Color color) const
{
    return (color == Piece::Color::White) ? whiteKingPos : blackKingPos;
}

std::vector<std::pair<int, int>> Board::getThreatenedSquares(Piece::Color color) const
{
	return std::vector<std::pair<int, int>>();
}
