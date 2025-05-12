#pragma once
#include "Piece.h"
#include <memory>
#include <array>
#include <vector>

class Board {
public:
    Board();
    ~Board();

    bool isValidCoordinate(int row, int col) const;
    const Piece* getPieceAt(int row, int col) const;
    bool isHorizPathClear(int startRow, int startCol, int endRow, int endCol) const;
    bool isVertPathClear(int startRow, int startCol, int endRow, int endCol) const;
    bool isDiagPathClear(int startRow, int startCol, int endRow, int endCol) const;

    std::vector<std::pair<int, int>> getValidMoves(const Piece& piece, const std::vector<std::pair<int, int>>& possibleMoves, int startRow, int startCol) const;
    bool isMoveSafeForKing(const Piece& piece, int startRow, int startCol, int endRow, int endCol) const;

    std::pair<int, int> getKingPosition(Piece::Color color) const;
    std::vector<std::pair<int, int>> getThreatenedSquares(Piece::Color color) const;

private:
    std::array<std::array<std::unique_ptr<Piece>, 8>, 8> board;
    Piece::Color currentTurn = Piece::Color::White;
    std::pair<int, int> whiteKingPos;
    std::pair<int, int> blackKingPos;
};

struct Move
{
    int fromRow;
    int fromCol;
    int toRow;
    int toCol;
};


//class Board
//{
//private:
//    Piece board[8][8];
//    Color currentTurn = Color::White;
//    std::vector<Move> validComputerMoves;
//    std::vector<Move> validPlayerMoves;
//    Piece capturedWhitePieces[15];
//    Piece capturedBlackPieces[15];
//    int whiteIndex = 0;
//    int blackIndex = 0;
//    bool isPlayersTurn = false;
//
//public:
//    // Constructor and destructor
//    Board();
//    ~Board();
//
//    void printBoard();
//    void displayCapturedPieces(Color color);
//
//    // getter and setters
//    const Piece(&getBoard() const)[8][8];
//    const std::vector<Move>(&getValidComputerMoves() const);
//    const std::vector<Move>(&getValidPlayerMoves() const);
//    void setComputersTurn();
//
//    Color getCurrentTurn() const;
//    void switchTurn();
//
//    bool isHorizPathClear(int startCol, int endCol, int row, const Piece(&board)[8][8]);
//    bool isVertPathClear(int startRow, int endRow, int col, const Piece(&board)[8][8]);
//    bool isDiagPathClear(int startRow, int endRow, int startCol, int endCol, const Piece(&board)[8][8]);
//
//    void simulateMove(const Piece(&board)[8][8], Piece(&tempBoard)[8][8], const Move& move);
//    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& piece, const Piece(&board)[8][8]);
//    bool isMoveSafe(int fromRow, int fromCol, int toRow, int toCol, const Piece(&board)[8][8], Color currentColor);
//    bool isValidPawnMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& pawn, const Piece& destination);
//    bool isValidRookMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& rook, const Piece& destination, const Piece(&board)[8][8]);
//    bool isValidKnightMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& knight, const Piece& destination);
//    bool isValidBishopMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& bishop, const Piece& destination, const Piece(&board)[8][8]);
//    bool isValidQueenMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& queen, const Piece& destination, const Piece(&board)[8][8]);
//    bool isValidKingMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& king, const Piece& destination);
//
//    bool readPlayerMove(int fromRow, int fromCol, int toRow, int toCol);
//    void setPossibleMoves(Color color, std::vector<Move>& moves, const Piece(&board)[8][8]);
//    void setPossibleTemporaryMoves(Color color, std::vector<Move>& moves, const Piece(&tempBoard)[8][8]);
//    Move selectRandomMove(const std::vector<Move>& moves);
//    void makeMove(int fromRow, int fromCol, int toRow, int toCol);
//
//    bool isPlayerInCheck(Color color, const std::vector<Move>& opponentMoves, const Piece(&board)[8][8]);
//    bool isCheckmate(Color color);
//    bool isStalemate(Color color);
//
//};

