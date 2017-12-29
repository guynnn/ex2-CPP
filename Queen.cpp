#include "Queen.h"
#include "Board.h"

/**
 * Constructor.
 * @param x x-axis coordinates on the board
 * @param y y-axis coordinates on the board
 * @param color black (false) or white (true)
 */
Queen::Queen(const char &x, const char &y, const bool color, const Board* board) : Piece(x, y, color, board)
{
    this->board = board;
}

/**
 * draws the queen on the screen
 */
void Queen::draw() const
{
    int blackOrWhite = (posX + posY) % 2;
    if (color)
    {
        if (blackOrWhite)
        {
            // white queen and white square
            std::cout << "\33[37;46m\u265B\33[0m";
        }
        else
        {
            // white queen and black square
            std::cout << "\33[37;42m\u265B\33[0m";
        }
    }
    else
    {
        if (blackOrWhite)
        {
            // black queen and white square
            std::cout << "\33[30;46m\u265B\33[0m";
        }
        else
        {
            // black queen and black square
            std::cout << "\33[30;42m\u265B\33[0m";
        }
    }
}

/**
 * check if the piece can legally move the a new location.
 * @param x the x coordinates of the move
 * @param y the y coordinates of the move
 * @return true iff the move is legal
 */
bool Queen::isLegal(const char &x, const char &y)
{
    Piece* pieceInDest = board->findPiece(x, y);
    char maxX = posX > x ? posX : x;
    char maxY = posY > y ? posY : y;
    char minX = posX < x ? posX : x;
    char minY = posY < y ? posY : y;
    if (posX == x || posY == y)
    {
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
        return pieceInDest == nullptr || pieceInDest->color != color;
    }
    else if (posX - x == posY - y || posX - x == y - posY)
    {
        int sign = posX - x == posY - y ? 1 : -1;
        char i, j;
        for (j = '8'; j >= '1' ; --j)
        {
            for (i = 'A'; i <= 'H'; ++i)
            {
                Piece* piece = board->findPiece(i, j);
                if ((piece != nullptr) && (i - sign * j == posX - sign * posY) && (minX < i) &&
                    (i < maxX) && (minY < j) && (j < maxY))
                {
                    return false;
                }
            }
        }
        return pieceInDest == nullptr || pieceInDest->color != color;
    }
    return false;
}