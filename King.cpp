#include "King.h"
#include "Board.h"

/**
 * Constructor.
 * @param x x-axis coordinates on the board
 * @param y y-axis coordinates on the board
 * @param color black (false) or white (true)
 */
King::King(const char &x, const char &y, const bool color, const Board* board) : Piece(x, y, color, board)
{
    this->board = board;
}

/**
 * updates the location of the piece.
 * @param x new x
 * @param y new y
 */
void King::draw() const
{
    int blackOrWhite = (posX + posY) % 2;
    if (color)
    {
        if (blackOrWhite)
        {
            // white king and white square
            std::cout << "\33[37;46m\u265A\33[0m";
        }
        else
        {
            // white king and black square
            std::cout << "\33[37;42m\u265A\33[0m";
        }
    }
    else
    {
        if (blackOrWhite)
        {
            // black king and white square
            std::cout << "\33[30;46m\u265A\33[0m";
        }
        else
        {
            // black king and black square
            std::cout << "\33[30;42m\u265A\33[0m";
        }
    }
}

/**
 * check if the piece can legally move the a new location.
 * @param x the x coordinates of the move
 * @param y the y coordinates of the move
 * @return true iff the move is legal
 */
bool King::isLegal(const char &x, const char &y)
{
    if (!((posX == x && (posY - y == 1 || y - posY == 1)) ||
        ((posX == x + 1 || posX == x - 1) && (posY - y == 1 || y - posY == 1 || y == posY))))
    {
        return false;
    }
    Piece* pieceInDest = board->findPiece(x, y);
    return pieceInDest == nullptr || pieceInDest->color != color;
}