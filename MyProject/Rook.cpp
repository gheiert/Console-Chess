#include "Rook.h"

std::vector<std::pair<int, int>> Rook::getPossibleMoves(int startRow, int startCol) const
{
    std::vector<std::pair<int, int>> possibleMoves;

    for (int row = 0; row < 8; row++)
    {
        if (row != startRow && isValidCoordinate(row, startCol))
        {
            possibleMoves.emplace_back(row, startCol);
        }
    }

    for (int col = 0; col < 8; col++)
    {
        if (col != startCol && isValidCoordinate(startRow, col))
        {
            possibleMoves.emplace_back(startRow, col);
        }
    }

    return possibleMoves;
}

bool Rook::isValidMove(int startRow, int startCol, int endRow, int endCol, const Board& board) const
{
    if (!isValidCoordinate(endRow, endCol)) // Early return if invalid coordinate
    {
        return false;
    }

    if (startRow == endRow && board.isHorizPathClear(startRow, startCol, endRow, endCol)) 
    {
        return true;
    }

    if (startCol == endCol && board.isVertPathClear(startRow, startCol, endRow, endCol)) 
    {
        return true;
    }

    return false;
}

std::vector<std::pair<int, int>> Rook::getThreatenedSquares(int startRow, int startCol, const Board& board) const
{
    std::vector<std::pair<int, int>> threatenedSquares;

    for (int row = 0; row < 8; row++)
    {
        if (row != startRow)
        {
            if (!board.isVertPathClear(startRow, startCol, row, startCol))
            {
                break;
            }
            threatenedSquares.emplace_back(row, startCol);
        }
    }

    for (int col = 0; col < 8; col++)
    {
        if (col != startCol)
        {
            if (!board.isHorizPathClear(startRow, startCol, startRow, col))
            {
                break;
            }
            threatenedSquares.emplace_back(startRow, col);
        }
    }

    return threatenedSquares;
}
