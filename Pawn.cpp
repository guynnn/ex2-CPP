#include "Pawn.h"
#include "Board.h"

/**
 * Constructor.
 * @param x x-axis coordinates on the board
 * @param y y-axis coordinates on the board
 * @param color black (false) or white (true)
 */
Pawn::Pawn(const char &x, const char &y, const bool color, const Board* board) : Piece(x, y, color,
                                                                                  board)
{
    this->board = board;
}

void Pawn::draw() const
{
    int blackOrWhite = (posX + posY) % 2;
    if (color)
    {
        // white
        if (blackOrWhite)
        {
            // white pawn and white square
            std::cout << "\33[37;46m\u265F\33[0m";
        }
        else
        {
            // white pawn and black square
            std::cout << "\33[37;42m\u265F\33[0m";
        }
    }
    else
    {
        if (blackOrWhite)
        {
            // black pawn and white square
            std::cout << "\33[30;46m\u265F\33[0m";
        }
        else
        {
            // black pawn and black square
            std::cout << "\33[30;42m\u265F\33[0m";
        }
    }
}

/**
 * check if the piece can legally move the a new location.
 * @param x the x coordinates of the move
 * @param y the y coordinates of the move
 * @return true iff the move is legal
 */
bool Pawn::isLegal(const char &x, const char &y)
{
    Piece *piece = board->findPiece(x, y);
    if (posX == x)
    {
        if ((y - posY == 1 && color) || (posY - y == 1 && !color) || (y - posY == 2 && !started)
            || (posY - y == 2 && !started))
        {
            return piece == nullptr;
        }
    }
    else if ((posX - x == 1 || x - posX == 1) && ((y - posY == 1 && color) || (posY - y == 1 && !color)))
    {
        return piece != nullptr && piece->color != color;
    }
    return false;
}

/**
 * @return true iff the piece need to be promoted to a queen.
 */
bool Pawn::isPromote() const
{
    return (color && posY == '8') || (!color && posY == '1');
}