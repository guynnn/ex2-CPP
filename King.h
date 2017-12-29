#ifndef EX2_KING_H
#define EX2_KING_H


#include "Piece.h"

/**
 * Represents a king.
 */
class King : public Piece
{

public:
    /**
     * Constructor.
     * @param x x-axis coordinates on the board
     * @param y y-axis coordinates on the board
     * @param color black (false) or white (true)
     */
    King(const char &x, const char &y, const bool color, const Board* board);
    /**
     * check if the piece can legally move the a new location.
     * @param x the x coordinates of the move
     * @param y the y coordinates of the move
     * @return true iff the move is legal
     */
    bool isLegal(const char& x, const char& y);
    /**
     * updates the location of the piece.
     * @param x new x
     * @param y new y
     */
    void draw() const;
};

#endif //EX2_KING_H
