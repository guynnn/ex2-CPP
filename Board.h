#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#include "Piece.h"

/**
 * Rpresents a board.
 */
class Board
{
public:

    /**
     * Constructor.
     */
    Board();

    /**
     * Destructor.
     */
    ~Board();

    /**
     * prints the board on the screen.
     */
    void print() const;

    /**
     * find a piece on the board when given the coordinates of the piece.
     * @param posX x-axis coordinates.
     * @param PosY y-axis coordinates.
     * @return pointer the the piece if it was found, nullptr otherwise.
     */
    Piece* findPiece(const char& posX, const char& PosY) const;
    /**
     * find a piece on the board when given the coordinates of the piece.
     * @param posX x-axis coordinates.
     * @param PosY y-axis coordinates.
     * @return index of the piece in the array of pieces the board has.
     */
    int findIndex(const char& posX, const char& PosY) const;

    /**
     * make a single piece to a new location if possible.
     * @param position the location of the piece to move and the destination.
     * @param color color to move.
     * @return true iff the move was successful.
     */
    bool makeMove(const std::string& position, const bool& color);

    /**
     * check if the player with this color is in check.
     * @param color color to check.
     * @return true iff the color given is indeed in check.
     */
    bool isCheck(const bool& color) const;

    /**
     * check if the player with this color is in mate.
     * @param color color to check.
     * @return true iff the color given is indeed in mate.
     */
    bool isMate(const bool& color);

private:

    // check if there's a threat by the opponent on the given cell
    bool _isThreat(const char& x, const char& y, const bool& color) const;
    // check if the given color has mated
    bool _mateHelper(const char& x, const char& y, const bool& color);
    // check if a given cell has a white piece in it
    bool _isWhite(const char posX, const char posY) const;
    // check if some pawn need to be promoted
    void _promotion();
    // make a castle to the given color, king or queen side
    bool _castle(const bool& color, const bool& side);
    // initialize the pieces in the right locations
    void _initializePieces();
    // array of all the pieces on the board
    Piece* _pieces[32];
};

#endif //EX2_BOARD_H
