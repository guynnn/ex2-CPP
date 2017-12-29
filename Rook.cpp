#include "Rook.h"
#include "Board.h"

/**
 * Constructor.
 * @param x x-axis coordinates on the board
 * @param y y-axis coordinates on the board
 * @param color black (false) or white (true)
 */
Rook::Rook(const char &x, const char &y, const bool color, const Board* board) : Piece(x, y, color,
                                                                                  board)
{
    this->board = board;
}

/**
 * draws the piece on the screen
 */
void Rook::draw() const
{
    int blackOrWhite = (posX + posY) % 2;
    if (color)
    {
        if (blackOrWhite)
        {
            // white rook and white square
            std::cout << "\33[37;46m\u265C\33[0m";
        }
        else
        {
            // white rook and black square
            std::cout << "\33[37;42m\u265C\33[0m";
        }
    }
    else
    {
        if (blackOrWhite)
        {
            // black rook and white square
            std::cout << "\33[30;46m\u265C\33[0m";
        }
        else
        {
            // black rook and black square
            std::cout << "\33[30;42m\u265C\33[0m";
        }
    }
}

/**
 * check if the piece can legally move the a new location.
 * @param x the x coordinates of the move
 * @param y the y coordinates of the move
 * @return true iff the move is legal
 */
bool Rook::isLegal(const char &x, const char &y)
{
    if (posX != x && posY != y)
    {
        return false;
    }
    char maxX = posX > x ? posX : x;
    char maxY = posY > y ? posY : y;
    char minX = posX < x ? posX : x;
    char minY = posY < y ? posY : y;
    char i;

    if (x == posX)
    {
        for (i = char(minY + 1); i < maxY; ++i)
        {
            Piece* piece = board->findPiece(posX, i);
            if (piece != nullptr)
            {
                return false;
            }
        }
    }
    else // y == posY
    {
        for (i = char(minX + 1); i < maxX; ++i)
        {
            Piece* piece = board->findPiece(i, posY);
            if (piece != nullptr)
            {
                return false;
            }
        }
    }
    Piece* pieceInDest = board->findPiece(x, y);
    return pieceInDest == nullptr || pieceInDest->color != color;
}