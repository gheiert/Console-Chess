#pragma once
#include <string>
#include <cmath>

enum class PieceType {Empty, Pawn, Knight, Bishop, Rook, Queen, King};
enum class Color {None, White, Black};

struct Piece
{
    // Member Variables
    PieceType m_type;
    Color m_color;
    int m_id;
    std::string m_name;
    
    // Constructor
    Piece(PieceType t = PieceType::Empty, Color c = Color::None, int i = -1, std::string n = "") 
        : m_type(t), m_color(c), m_id(i), m_name(std::move(n))
    {

    }

    bool isRowEmpty(int startCol, int endCol, int row, const Piece(&board)[8][8])
    {
        if (startCol < endCol)
        { 
            startCol++;
            for (startCol; startCol < endCol; startCol++)
            {
                if (board[row][startCol].m_type != PieceType::Empty)
                {
                    return false;
                }
            }
        }
        else
        {
            startCol--;
            for (startCol; startCol > endCol; startCol--)
            {
                if (board[row][startCol].m_type != PieceType::Empty)
                {
                    return false;
                }
            }
        }

        return true;
    }

    // Movement Rules
    bool isValidMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& piece, const Piece (&board)[8][8])
    {
        const Piece& destination = board[toRow][toCol];
        switch (piece.m_type)
        {
        case PieceType::Pawn:
            isValidPawnMove(fromRow, fromCol, toRow, toCol, piece, destination);
            break;
        }
    }

    bool isValidPawnMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& pawn, const Piece& destination)
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

    bool isValidRookMove(int fromRow, int fromCol, int toRow, int toCol, const Piece& rook, const Piece& destination)
    {
        // Horizontal Move
        if (toRow == fromRow
            && isRowEmpty(fromCol,toCol,fromRow,))
        {
            return true;
        }
    }
};

class Board
{
private:
    Piece board[8][8];

public:
    Board();
    ~Board();
    void printBoard();
    void updateBoard();
};

