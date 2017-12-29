#ifndef EX2_PAWN_H
#define EX2_PAWN_H


#include "Piece.h"

/**
 * Represents a pawn.
 */
class Pawn : public Piece
{
public:

    /**
     * Constructor.
     * @param x x-axis coordinates on the board
     * @param y y-axis coordinates on the board
     * @param color black (false) or white (true)
     */
    Pawn(const char &x, const char &y, const bool color, const Board* board);
    /**
     * check if the piece can legally move the a new location.
     * @param x the x coordinates of the move
     * @param y the y coordinates of the move
     * @return true iff the move is legal
     */
    bool isLegal(const char& x, const char& y);
    /**
     * draws the piece on the screen
     */
    void draw() const;
    /**
     * @return true iff the piece need to be promoted to a queen.
     */
    bool isPromote() const;

};


#endif //EX2_PAWN_H
