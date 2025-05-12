#pragma once
#include "Piece.h"
#include "Board.h"

class Knight : public Piece
{
public:
	// Derived Class (Knight) Constructor
	Knight(Color color = Color::None, std::string name = "")
		: Piece(color, color == Color::White ? "whiteKnight" : "blackKnight")
	{

	}

	std::vector<std::pair<int, int>> getPossibleMoves(int startRow, int startCol) const override;
	bool isValidMove(int startRow, int startCol, int endRow, int endCol, const Board& board) const override;
	std::vector<std::pair<int, int>> getThreatenedSquares(int startRow, int startCol, const Board& board) const override;
};

