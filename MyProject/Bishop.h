#pragma once
#include "Piece.h"
#include "Board.h"

class Bishop : public Piece
{
public:
	// Derived Class (Bishop) Constructor
	Bishop(Color color = Color::None, std::string name = "")
		: Piece(color, color == Color::White ? "whiteBishop" : "blackBishop")
	{

	}

	std::vector<std::pair<int, int>> getPossibleMoves(int startRow, int startCol) const override;
	bool isValidMove(int startRow, int startCol, int endRow, int endCol, const Board& board) const override;
	std::vector<std::pair<int, int>> getThreatenedSquares(int startRow, int startCol, const Board& board) const override;
};

