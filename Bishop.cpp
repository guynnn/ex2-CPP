#include "Bishop.h"
#include "Board.h"

/**
 * Constructor.
 * @param x x-axis coordinates on the board
 * @param y y-axis coordinates on the board
 * @param color black (false) or white (true)
 */
Bishop::Bishop(const char &x, const char &y, const bool color, const Board* board) : Piece(x, y, color, board)
{
    this->board = board;
}

/**
 * draws the piece on the screen
 */
void Bishop::draw() const
{
    int blackOrWhite = (posX + posY) % 2;
    if (color)
    {
        if (blackOrWhite)
        {
            // white bishop and white square
            std::cout << "\33[37;46m\u265D\33[0m";
        }
        else
        {
            // white bishop and black square
            std::cout << "\33[37;42m\u265D\33[0m";
        }
    }
    else
    {
        if (blackOrWhite)
        {
            // black bishop and white square
            std::cout << "\33[30;46m\u265D\33[0m";
        }
        else
        {
            // black bishop and black square
            std::cout << "\33[30;42m\u265D\33[0m";
        }
    }
}

/**
 * check if the piece can legally move the a new location.
 * @param x the x coordinates of the move
 * @param y the y coordinates of the move
 * @return true iff the move is legal
 */
bool Bishop::isLegal(const char &x, const char &y)
{
    if (posX - x != posY - y && posX - x != y - posY)
    {
        return false;
    }
    int sign = posX - x == posY - y ? 1 : -1;
    int maxX = posX > x ? posX : x;
    int maxY = posY > y ? posY : y;
    int minX = posX < x ? posX : x;
    int minY = posY < y ? posY : y;
    char i, j;
    for (j = '8'; j >= '1' ; --j)
    {
        for (i = 'A'; i <= 'H'; ++i)
        {
            if ((i - sign * j == posX - sign * posY) && (minX < i) &&
                (i < maxX) && (minY < j) && (j < maxY))
            {
                Piece* piece = board->findPiece(i, j);
                if (piece != nullptr)
                {
                    return false;
                }
            }
        }
    }
    Piece* pieceInDest = board->findPiece(x, y);
    return pieceInDest == nullptr || pieceInDest->color != color;
}
