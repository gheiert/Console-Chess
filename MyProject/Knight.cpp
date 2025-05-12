#include "Knight.h"

std::vector<std::pair<int, int>> Knight::getPossibleMoves(int startRow, int startCol) const
{
    std::vector<std::pair<int, int>> possibleMoves;

    // Possible relative moves for a knight
    const std::vector<std::pair<int, int>> moveOffsets = 
    {
        {-2, 1}, {-2, -1}, {2, 1}, {2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    for (const auto& offset : moveOffsets) {
        int newRow = startRow + offset.first;
        int newCol = startCol + offset.second;

        if (isValidCoordinate(newRow, newCol)) {
            possibleMoves.emplace_back(newRow, newCol);
        }
    }

    return possibleMoves;
}

bool Knight::isValidMove(int startRow, int startCol, int endRow, int endCol, const Board& board) const
{
    if (!isValidCoordinate(endRow, endCol)) // Early return if invalid coordinate
    {
        return false;
    }

    int rowDiff = std::abs(startRow - endRow);
    int colDiff = std::abs(startCol - endCol);

    return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}

std::vector<std::pair<int, int>> Knight::getThreatenedSquares(int startRow, int startCol, const Board& board) const
{
    return getPossibleMoves(startRow, startCol);
}
