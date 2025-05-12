#include "utils.h"

std::string pieceTypeToString(Piece* type)
{
    switch (type)
    {
    case PieceType::Pawn:
        return "Pawn";
    case PieceType::Rook:
        return "Rook";
    case PieceType::Knight:
        return "Knight";
    case PieceType::Bishop:
        return "Bishop";
    case PieceType::Queen:
        return "Queen";
    case PieceType::King:
        return "King";
    default:
        return "Error";
    }
}

std::string colorToString(Piece::Color color)
{
    switch (color)
    {
    case Piece::Color::White:
        return "White";
    case Piece::Color::Black:
        return "Black";
    default:
        return "Error";
    }
}

std::string numberToLetter(int index)
{
    std::string col[8] = {"a","b","c","d","e","f","g","h"};
    return col[index];
}

std::string formatWhiteRow(int whiteRow)
{
    switch (whiteRow)
    {
    case 0:
        return "8";
    case 1:
        return "7";
    case 2:
        return "6";
    case 3:
        return "5";
    case 4:
        return "4";
    case 5:
        return "3";
    case 6:
        return "2";
    case 7:
        return "1";
    case 8:
        return "0";
    default:
        return "If you are reading this, then there has been a mistake.";
    }
}

void setTextColor(const std::string& color)
{
    std::cout << color;
}

void resetTextColor()
{
    std::cout << "\033[0m";
}
