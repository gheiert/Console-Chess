#pragma once
#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

enum class PieceType {Empty, Pawn, Knight, Bishop, Rook, Queen, King};
enum class Color {None, White, Black};


struct Piece
{
    // Member Variables
    PieceType m_type;
    Color m_color;
    int m_id;
    std::string m_name;
    bool m_captured;
    
    // Constructor
    Piece(PieceType t = PieceType::Empty, Color c = Color::None, int i = -1, std::string n = "", bool captured = false)
        : m_type(t), m_color(c), m_id(i), m_name(std::move(n)), m_captured(captured)
    {

    }

};

struct Move
{
    int fromRow;
    int fromCol;
    int toRow;
    int toCol;
};


class Board
{
private:
    Piece board[8][8];
    Color currentTurn = Color::White;
    std::vector<Move> validComputerMoves;
    std::vector<Move> validPlayerMoves;
    Piece capturedWhitePieces[15];
    Piece capturedBlackPieces[15];
    int whiteIndex = 0;
    int blackIndex = 0;
    bool isPlayersTurn = false;

public:
    // Constructor and destructor
    Board();
    ~Board();

    void printBoard();
    void displayCapturedPieces(Color color);

    // getter and setters
    const Piece(&getBoard() const)[8][8];
    const std::vector<Move>(&getValidComputerMoves() const);
    const std::vector<Move>(&getValidPlayerMoves() const);
    void setComputersTurn();

    Color getCurrentTurn() const;
    void switchTurn();

    bool isHorizPathClear(int startCol, int endCol, int row, const Piece(&board)[8][8]);
    bool isVertPathClear(int startRow, int endRow, int col, const Piece(&board)[8][8]);
    bool isDiagPathClear(int startRow, int endRow, int startCol, int endCol, const Piece(&board)[8][8]);

    bool simulateMove(const Piece(&board)[8][8], Piece(&tempBoard)[8][8], const Move& move);
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& piece, const Piece(&board)[8][8]);
    bool isValidPawnMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& pawn, const Piece& destination);
    bool isValidRookMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& rook, const Piece& destination, const Piece(&board)[8][8]);
    bool isValidKnightMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& knight, const Piece& destination);
    bool isValidBishopMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& bishop, const Piece& destination, const Piece(&board)[8][8]);
    bool isValidQueenMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& queen, const Piece& destination, const Piece(&board)[8][8]);
    bool isValidKingMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& king, const Piece& destination);

    bool readPlayerMove(int fromRow, int fromCol, int toRow, int toCol);
    void setPossibleMoves(Color color, std::vector<Move>& moves);
    Move selectRandomMove(const std::vector<Move>& moves);
    void makeMove(int fromRow, int fromCol, int toRow, int toCol);

    bool isPlayerInCheck(Color color, const std::vector<Move>& opponentMoves, const Piece(&board)[8][8]);
    bool isCheckmate(Color color);
    bool isStalemate(Color color);

};

