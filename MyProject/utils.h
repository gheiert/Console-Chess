#pragma once
#include "Board.h"
#include "Piece.h"
#include <string>
#include <iomanip>

std::string pieceTypeToString(Piece* type);
std::string colorToString(Piece::Color color);
std::string numberToLetter(int index);
std::string formatWhiteRow(int WhiteRow);
void setTextColor(const std::string& color);
void resetTextColor();
