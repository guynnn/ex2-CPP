#include "Knight.h"
#include "Board.h"

/**
 * Constructor.
 * @param x x-axis coordinates on the board
 * @param y y-axis coordinates on the board
 * @param color black (false) or white (true)
 */
Knight::Knight(const char &x, const char &y, const bool color, const Board* board) : Piece(x, y, color, board)
{
    this->board = board;
}

/**
 * draws the piece on the screen
 */
void Knight::draw() const
{
    int blackOrWhite = (posX + posY) % 2;
    if (color)
    {
        if (blackOrWhite)
        {
            // white knight and white square
            std::cout << "\33[37;46m\u265E\33[0m";
        }
        else
        {
            // white knight and black square
            std::cout << "\33[37;42m\u265E\33[0m";
        }
    }
    else
    {
        if (blackOrWhite)
        {
            // black knight and white square
            std::cout << "\33[30;46m\u265E\33[0m";
        }
        else
        {
            // black knight and black square
            std::cout << "\33[30;42m\u265E\33[0m";
        }
    }
}

/**
 * check if the piece can legally move the a new location.
 * @param x the x coordinates of the move
 * @param y the y coordinates of the move
 * @return true iff the move is legal
 */
bool Knight::isLegal(const char &x, const char &y)
{
    Piece* pieceInDest = board->findPiece(x, y);
    if (pieceInDest != nullptr && pieceInDest->color == color)
    {
        return false;
    }
    return (posX - x == 2 && posY - y == 1) || (posX - x == -2 && posY - y == 1) ||
           (posX - x == 2 && posY - y == -1) || (posX - x == -2 && posY - y == -1) ||
           (posX - x == 1 && posY - y == 2) || (posX - x == -1 && posY - y == 2) ||
           (posX - x == 1 && posY - y == -2) || (posX - x == -1 && posY - y == -2);
}