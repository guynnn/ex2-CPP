
#ifndef EX2_PIECE_H
#define EX2_PIECE_H


#include <iostream>

class Board;

/**
 *  Resresents general piece on the board.
 */
class Piece
{

public:

    // white or black
    bool color;
    // the board that the piece belongs to
    const Board* board;
    /**
     * Constructor.
     * @param x x-axis coordinates on the board
     * @param y y-axis coordinates on the board
     * @param color black (false) or white (true)
     */
    Piece(const char& x, const char& y, const bool& color, const Board*);
    /**
     * Destructor.
     */
    virtual ~Piece();
    /**
     * draws the piece on the screen
     */
    virtual void draw() const = 0;
    /**
     * updates the location of the piece.
     * @param x new x
     * @param y new y
     */
    virtual void setPos(const char& x, const char& y);
    /**
     * check if the piece can legally move the a new location.
     * @param x the x coordinates of the move
     * @param y the y coordinates of the move
     * @return true iff the move is legal
     */
    virtual bool isLegal(const char& x, const char& y) = 0;
    /**
     * @return current x-axis coordinates.
     */
    virtual char getX() const;
    /**
     * @return current y-axis coordinates.
     */
    virtual char getY() const;
    /**
     * @return true iff the piece need to be promoted to a queen.
     */
    virtual bool isPromote() const;
    /**
     * @param start true if the piece made a move.
     */
    virtual void setStarted(const bool& start);
    /**
     * @return true iff the piece made a move.
     */
    virtual bool getStarted();

protected:
    // x-axis coordinates
    char posX;
    // y-axis coordinates
    char posY;
    // true iff the piece made a move
    bool started;
};

#endif //EX2_PIECE_H
