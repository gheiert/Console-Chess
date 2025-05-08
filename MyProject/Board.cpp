#include "Board.h"
#include <iostream>

Board::Board()
{
    board[0][0] = Piece(PieceType::Rook, Color::Black, 0, "bR1");
    board[0][1] = Piece(PieceType::Knight, Color::Black, 0, "bN1");
    board[0][2] = Piece(PieceType::Bishop, Color::Black, 0, "bB1");
    board[0][3] = Piece(PieceType::Queen, Color::Black, 0, "bQ1");
    board[0][4] = Piece(PieceType::King, Color::Black, 0, "bK");
    board[0][5] = Piece(PieceType::Bishop, Color::Black, 1, "bB2");
    board[0][6] = Piece(PieceType::Knight, Color::Black, 1, "bN2");
    board[0][7] = Piece(PieceType::Rook, Color::Black, 1, "bR2");

    for (int j = 0; j < 8; j++)
    {
        board[1][j] = Piece(PieceType::Pawn, Color::Black, j, "bP" + std::to_string(j));
    }

    for (int i = 2; i < 6; i++) 
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = Piece();
        }
    }

    for (int j = 0; j < 8; j++)
    {
        board[6][j] = Piece(PieceType::Pawn, Color::White, j, "wP" + std::to_string(j));
    }

    board[7][0] = Piece(PieceType::Rook, Color::White, 0, "wR1");
    board[7][1] = Piece(PieceType::Knight, Color::White, 0, "wN1");
    board[7][2] = Piece(PieceType::Bishop, Color::White, 0, "wB1");
    board[7][3] = Piece(PieceType::Queen, Color::White, 0, "wQ1");
    board[7][4] = Piece(PieceType::King, Color::White, 0, "wK");
    board[7][5] = Piece(PieceType::Bishop, Color::White, 1, "wB2");
    board[7][6] = Piece(PieceType::Knight, Color::White, 1, "wN2");
    board[7][7] = Piece(PieceType::Rook, Color::White, 1, "wR2");
}

Board::~Board()
{
}

void Board::printBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Piece p = board[i][j];
            if (p.m_type == PieceType::Empty)
            {
                std::cout << ". ";
            }
            else
            {
                char c = '?';
                switch (p.m_type)
                {
                case PieceType::King:
                    c = 'K';
                    break;
                case PieceType::Queen:
                    c = 'Q';
                    break;
                case PieceType::Rook:
                    c = 'R';
                    break;
                case PieceType::Knight:
                    c = 'N';
                    break;
                case PieceType::Bishop:
                    c = 'B';
                    break;
                case PieceType::Pawn:
                    c = 'P';
                    break;
                default:
                    std::cout << "This is a bug!";
                    break;
                }
                std::cout << (p.m_color == Color::White ? c : static_cast<char>(tolower(c))) << ' ';
            }
        }
        std::cout << '\n';
    }
}

void Board::updateBoard()
{
}
