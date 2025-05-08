#pragma once
#include "Board.h"
#include <string>
#include <iomanip>

std::string pieceTypeToString(PieceType type);
std::string colorToString(Color color);
std::string numberToLetter(int index);
std::string formatWhiteRow(int WhiteRow);
void setTextColor(const std::string& color);
void resetTextColor();
