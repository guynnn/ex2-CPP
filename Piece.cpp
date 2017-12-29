#include "Piece.h"
#include "Board.h"

/**
 * Constructor.
 * @param x x-axis coordinates on the board
 * @param y y-axis coordinates on the board
 * @param color black (false) or white (true)
 */
Piece::Piece(const char& x, const char &y, const bool& color, const Board*)
{
    posX = x;
    posY = y;
    this->color = color;
    this->board = board;
    started = false;
}

/**
 * Destructor.
 */
Piece::~Piece()
{}

/**
 * @return current x-axis coordinates.
 */
char Piece::getX() const
{
    return posX;
}

char Piece::getY() const
{
    return posY;
}

/**
 * updates the location of the piece.
 * @param x new x
 * @param y new y
 */
void Piece::setPos(const char &x, const char &y)
{
    posX = x;
    posY = y;
    started = true;
}

/**
 * @return true iff the piece need to be promoted to a queen.
 */
bool Piece::isPromote() const
{
    return false;
}

/**
 * @return true iff the piece made a move.
 */
void Piece::setStarted(const bool& start)
{
    started = start;
}

/**
 * @return true iff the piece made a move.
 */
bool Piece::getStarted()
{
    return started;
}
