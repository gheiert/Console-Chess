// ******************************************
// Include of External Package Specifications
// ******************************************
#include "Board.h"
#include "utils.h"

// ******************************************
// Include of system header files
// ******************************************
#include <iomanip>
#include <string>
#include <random>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";

enum class PlayerColor { White, Black };

// Function prototype(s)
bool isPlayerEntryValid(Board& gameBoard, const Piece(&b)[8][8], Piece& pieceH, int& fromRow, int& fromCol, int& toRow, int& toCol);
void assignPlayerColors(PlayerColor& yourColor, PlayerColor& cpuColor);

int main() 
{
    PlayerColor yourColor;
    PlayerColor cpuColor;
    assignPlayerColors(yourColor, cpuColor);

    std::cout << std::setw(92) << std::right << "You are " <<
        (yourColor == PlayerColor::White ? "White" : "Black") << " this game." << std::endl;;


    Board gameBoard;
    bool isGameOver = false;
    const Piece(&b)[8][8] = gameBoard.getBoard();
    std::vector<Move> validComputerMoves = gameBoard.getValidComputerMoves();
    std::vector<Move> validPlayerMoves = gameBoard.getValidPlayerMoves();
    int fromRow, fromCol, toRow, toCol;
    Piece pieceH;
    
    // Initial print if the player is white
    if (yourColor == PlayerColor::White)
    {
        gameBoard.printBoard();
    }

    while (!isGameOver) // Simulate Turns
    {
        //isTurnOver = false;
        
        if (yourColor == PlayerColor::White)
        {
            // ------------------------------------------------- Player ---------------------------------------------------

            if (gameBoard.isCheckmate(Color::White) 
                || gameBoard.isStalemate(Color::White))
            {
                isGameOver = true;
                continue;
            }

            isPlayerEntryValid(gameBoard, b, pieceH, fromRow, fromCol, toRow, toCol);

            gameBoard.makeMove(fromRow, fromCol, toRow, toCol);
            gameBoard.printBoard();
            setTextColor(GREEN);
            std::cout << std::setw(100) << std::right << colorToString(pieceH.m_color) << " " << pieceTypeToString(pieceH.m_type) <<
                " was moved from " << numberToLetter(fromCol) << formatWhiteRow(fromRow) << " to " << numberToLetter(toCol) << formatWhiteRow(toRow) << std::endl;
            resetTextColor();

            // Generate the player's possible moves to check if the player has put the computer into check
            gameBoard.setPossibleMoves(Color::White, validPlayerMoves, b);
            gameBoard.setComputersTurn(); // This is simply a flag to determine which player should be evaluated for checkmates or stalemates

            // ------------------------------------------------- Computer -------------------------------------------------

            if (gameBoard.isCheckmate(Color::Black)
                || gameBoard.isStalemate(Color::Black))
            {
                isGameOver = true;
                continue;
            }

            std::cout << std::setw(80) << std::right <<
                (gameBoard.getCurrentTurn() == Color::White ? "White" : "Black") << "'s move:" << std::endl;

            gameBoard.setPossibleMoves(Color::Black, validComputerMoves, b);
            const std::vector<Move> validMoves = gameBoard.getValidComputerMoves();
            Move randomMove = gameBoard.selectRandomMove(validMoves);
            Piece pieceCPU = b[randomMove.fromRow][randomMove.fromCol];
            gameBoard.makeMove(randomMove.fromRow, randomMove.fromCol, randomMove.toRow, randomMove.toCol);
            gameBoard.printBoard();
            setTextColor(RED);
            std::cout << std::setw(100) << std::right <<
                colorToString(pieceCPU.m_color) + " " + pieceTypeToString(pieceCPU.m_type) + " was moved from "
                + numberToLetter(randomMove.fromCol) + std::to_string(randomMove.fromRow)
                + " to " + numberToLetter(randomMove.toCol) + std::to_string(randomMove.toRow) << std::endl;
            resetTextColor();

            //while (!isTurnOver && !isGameOver)
            //{
            //    // ------------------------------------------------- Player ------------------------------------------------------
            //    
            //    /*std::cout << std::setw(80) << std::right <<
            //        (gameBoard.getCurrentTurn() == Color::White ? "White" : "Black") << "'s move (e.g. , e2 , e4 , etc.): ";
            //    std::cin >> from >> to;*/

            //    isPlayerEntryValid(gameBoard, b, pieceH, fromRow, fromCol, toRow, toCol);

            //    /*int fromCol = from[0] - 'a';
            //    int fromRow = 8 - (from[1] - '0');
            //    int toCol = to[0] - 'a';
            //    int toRow = 8 - (to[1] - '0');
            //    Piece pieceH = b[fromRow][fromCol];*/

            //    if (gameBoard.readPlayerMove(fromRow, fromCol, toRow, toCol))
            //    {
            //        gameBoard.makeMove(fromRow, fromCol, toRow, toCol);
            //        gameBoard.printBoard();
            //        setTextColor(GREEN);
            //        std::cout << std::setw(100) << std::right << colorToString(pieceH.m_color) << " " << pieceTypeToString(pieceH.m_type) <<
            //            " was moved from " << fromCol << fromRow << " to " << toRow << toCol << std::endl;
            //        resetTextColor();
            //        
            //        // Generate the player's possible moves to check if the player has put the computer into check
            //        gameBoard.setPossibleMoves(Color::White, validPlayerMoves);
            //        gameBoard.setComputersTurn();

            //        // ------------------------------------------------- Computer -------------------------------------------------

            //        std::cout << std::setw(80) << std::right <<
            //            (gameBoard.getCurrentTurn() == Color::White ? "White" : "Black") << "'s move:" << std::endl;

            //        gameBoard.setPossibleMoves(Color::Black, validComputerMoves);
            //        const std::vector<Move> validMoves = gameBoard.getValidComputerMoves();
            //        Move randomMove = gameBoard.selectRandomMove(validMoves);
            //        Piece pieceCPU = b[randomMove.fromRow][randomMove.fromCol];
            //        gameBoard.makeMove(randomMove.fromRow, randomMove.fromCol, randomMove.toRow, randomMove.toCol);
            //        gameBoard.printBoard();
            //        setTextColor(RED);
            //        std::cout << std::setw(100) << std::right <<
            //            colorToString(pieceCPU.m_color) + " " + pieceTypeToString(pieceCPU.m_type) + " was moved from "
            //            + numberToLetter(randomMove.fromCol) + formatCPUMove(randomMove.fromRow)
            //            + " to " + numberToLetter(randomMove.toCol) + formatCPUMove(randomMove.toRow) << std::endl;
            //        resetTextColor();

            //        //gameBoard.displayCapturedPieces(pieceCPU.m_color);
            //        isTurnOver = true;
            //    }

            //    //gameBoard.displayCapturedPieces(pieceH.m_color);

            //} 
        }
        
        else //Computer = White, Player = Black
        {
            // ------------------------------------------------- Computer -------------------------------------------------

            if (gameBoard.isCheckmate(Color::White)
                || gameBoard.isStalemate(Color::White))
            {
                isGameOver = true;
                continue;
            }

            std::cout << std::setw(80) << std::right <<
                (gameBoard.getCurrentTurn() == Color::White ? "White" : "Black") << "'s move:" << std::endl;

            gameBoard.setPossibleMoves(Color::White, validComputerMoves, b);
            Move randomMove = gameBoard.selectRandomMove(validComputerMoves);
            Piece pieceCPU = b[randomMove.fromRow][randomMove.fromCol];
            gameBoard.makeMove(randomMove.fromRow, randomMove.fromCol, randomMove.toRow, randomMove.toCol);
            gameBoard.printBoard();
            setTextColor(RED);
            std::cout << std::setw(100) << std::right <<
                colorToString(pieceCPU.m_color) + " " + pieceTypeToString(pieceCPU.m_type) + " was moved from "
                + numberToLetter(randomMove.fromCol) + formatWhiteRow(randomMove.fromRow)
                + " to " + numberToLetter(randomMove.toCol) + formatWhiteRow(randomMove.toRow) << std::endl;
            resetTextColor();

            // ------------------------------------------------- Player ---------------------------------------------------

            if (gameBoard.isCheckmate(Color::Black)
                || gameBoard.isStalemate(Color::Black))
            {
                isGameOver = true;
                continue;
            }

            isPlayerEntryValid(gameBoard, b, pieceH, fromRow, fromCol, toRow, toCol);

            gameBoard.makeMove(fromRow, fromCol, toRow, toCol);
            gameBoard.printBoard();
            setTextColor(GREEN);
            std::cout << std::setw(100) << std::right << colorToString(pieceH.m_color) << " " << pieceTypeToString(pieceH.m_type) <<
                " was moved from " << fromCol << fromRow << " to " << toRow << toCol << std::endl;
            resetTextColor();

            // Generate the player's possible moves to check if the player has put the computer into check
            gameBoard.setPossibleMoves(Color::White, validPlayerMoves, b);
            gameBoard.setComputersTurn();

            //while (!isTurnOver && !isGameOver)
            {
                // ------------------------------------------------- Player -----------------------------------------------
                //std::cout << std::setw(80) << std::right <<
                //    (gameBoard.getCurrentTurn() == Color::White ? "White" : "Black") << "'s move (e.g. , e2 , e4 , etc.): ";
                //std::cin >> from >> to;

                //int fromCol = from[0] - 'a';
                //int fromRow = 8 - (from[1] - '0');
                //int toCol = to[0] - 'a';
                //int toRow = 8 - (to[1] - '0');
                //Piece pieceH = b[fromRow][fromCol];

                //if (gameBoard.readPlayerMove(fromRow, fromCol, toRow, toCol))
                //{
                //    gameBoard.makeMove(fromRow, fromCol, toRow, toCol);
                //    gameBoard.printBoard();
                //    setTextColor(GREEN);
                //    std::cout << std::setw(100) << std::right << colorToString(pieceH.m_color) << " " << pieceTypeToString(pieceH.m_type) <<
                //        " was moved from " << fromCol << fromRow << " to " << toRow << toCol << std::endl;
                //    resetTextColor();

                //    // Generate the player's possible moves to check if the player has put the computer into check
                //    gameBoard.setPossibleMoves(Color::Black, validPlayerMoves);
                //    gameBoard.setComputersTurn();
                //    isTurnOver = true;
                //}

                //gameBoard.displayCapturedPieces(pieceCPU.m_color);
                //gameBoard.displayCapturedPieces(pieceH.m_color);

            } 
        }
    }
    
    return 0;
}

// Function implementation(s)
bool isPlayerEntryValid(Board& gameBoard, const Piece(&b)[8][8], Piece& pieceH, int& fromRow, int& fromCol, int& toRow, int& toCol)
{
    std::string from, to;
    std::cout << std::setw(80) << std::right <<
        (gameBoard.getCurrentTurn() == Color::White ? "White" : "Black") << "'s move (e.g. , e2 , e4 , etc.): ";
    std::cin >> from >> to;

    while (true)
    {
        if (from.length() != 2 || to.length() != 2) 
        {
            std::cout << std::setw(80) << std::right <<
                "Invalid input format. Please use the format 'e2 e4'." << std::endl;
            std::cout << std::setw(80) << std::right << "Please re-enter your move (e.g. , e2 , e4 , etc.): ";
            std::cin >> from >> to;
            continue;
        }

        fromCol = from[0] - 'a';
        fromRow = 8 - (from[1] - '0');
        toCol = to[0] - 'a';
        toRow = 8 - (to[1] - '0');
        pieceH = b[fromRow][fromCol];

        if (gameBoard.readPlayerMove(fromRow, fromCol, toRow, toCol))
        {
            return true;
        }
    }

    return false; // Safety return
}

void assignPlayerColors(PlayerColor& yourColor, PlayerColor& cpuColor) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 100);

    int playerNum = distr(gen);
    int cpuNum = distr(gen);

    // Assign players to White and Black based on random numbers
    if (playerNum > cpuNum) {
        yourColor = PlayerColor::White;
        cpuColor = PlayerColor::Black;
    }
    else if (cpuNum >= playerNum) {
        yourColor = PlayerColor::Black;
        cpuColor = PlayerColor::White;
    }
}