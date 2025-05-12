#include "Bishop.h"

std::vector<std::pair<int, int>> Bishop::getPossibleMoves(int startRow, int startCol) const
{
    return std::vector<std::pair<int, int>>();
}

bool Bishop::isValidMove(int startRow, int startCol, int endRow, int endCol, const Board& board) const
{
    return false;
}

std::vector<std::pair<int, int>> Bishop::getThreatenedSquares(int startRow, int startCol, const Board& board) const
{
    return std::vector<std::pair<int, int>>();
}
