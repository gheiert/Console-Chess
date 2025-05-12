#pragma once
#include <string>
#include <vector>
#include <utility>

class Board;

class Piece
{
public:
	enum class Color { None, White, Black };

	// Base Class (Piece) Constructor
	Piece(Color color, const std::string& name)
		: m_color(color), m_name(name)
	{

	}

	virtual ~Piece() = default;

	virtual std::vector<std::pair<int, int>> getPossibleMoves(int startRow, int startCol) const = 0;
	virtual bool isValidMove(int startRow, int startCol, int endRow, int endCol, const Board& board) const = 0;
	virtual std::vector<std::pair<int, int>> getThreatenedSquares(int startRow, int startCol, const Board& board) const = 0;

	Color getColor() const
	{
		return m_color;
	}

	std::string getName() const
	{
		return m_name;
	}

protected:
	bool isValidCoordinate(int x, int y) const
	{
		return x >= 0 && x < 8 && y >= 0 && y < 8;
	}

private:
	// Member variables
	Color m_color;
	std::string m_name;
};

