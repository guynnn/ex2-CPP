#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

#define PIECES_NUM 32
#define ROWS 8
#define WHITE_KING 0
#define BLACK_KING 31
#define WHITE_LROOK 1
#define WHITE_RROOK 7
#define BLACK_LROOK 24
#define BLACK_RROOK 30


/**
 * Constructor.
 */
Board::Board()
{
    _initializePieces();
}

/**
 * Destructor.
 */
Board::~Board()
{
    int i;
    for (i = 0; i < PIECES_NUM ; ++i)
    {
        if (_pieces[i] != nullptr)
        {
            delete (_pieces[i]);
        }
    }
}

// initialize the pieces in the right locations

void Board::_initializePieces()
{
    _pieces[0] = new King('E', '1', true, this);
    _pieces[1] = new Rook('A', '1', true, this);
    _pieces[2] = new Knight('B', '1', true, this);
    _pieces[3] = new Bishop('C', '1', true, this);
    _pieces[4] = new Queen('D', '1', true, this);
    _pieces[5] = new Bishop('F', '1', true, this);
    _pieces[6] = new Knight('G', '1', true, this);
    _pieces[7] = new Rook('H', '1', true, this);
    _pieces[8] = new Pawn('A', '2', true, this);
    _pieces[9] = new Pawn('B', '2', true, this);
    _pieces[10] = new Pawn('C', '2', true, this);
    _pieces[11] = new Pawn('D', '2', true, this);
    _pieces[12] = new Pawn('E', '2', true, this);
    _pieces[13] = new Pawn('F', '2', true, this);
    _pieces[14] = new Pawn('G', '2', true, this);
    _pieces[15] = new Pawn('H', '2', true, this);
    _pieces[16] = new Pawn('A', '7', false, this);
    _pieces[17] = new Pawn('B', '7', false, this);
    _pieces[18] = new Pawn('C', '7', false, this);
    _pieces[19] = new Pawn('D', '7', false, this);
    _pieces[20] = new Pawn('E', '7', false, this);
    _pieces[21] = new Pawn('F', '7', false, this);
    _pieces[22] = new Pawn('G', '7', false, this);
    _pieces[23] = new Pawn('H', '7', false, this);
    _pieces[24] = new Rook('A', '8', false, this);
    _pieces[25] = new Knight('B', '8', false, this);
    _pieces[26] = new Bishop('C', '8', false, this);
    _pieces[27] = new Queen('D', '8', false, this);
    _pieces[28] = new Bishop('F', '8', false, this);
    _pieces[29] = new Knight('G', '8', false, this);
    _pieces[30] = new Rook('H', '8', false, this);
    _pieces[31] = new King('E', '8', false, this);
}

/**
 * prints the board on the screen.
 */
void Board::print() const
{
    int counter = ROWS;
    char i, j;
    std::cout << "  ABCDEFGH\n" << std::endl;
    for (i = '8'; i >= '1' ; --i)
    {
        std::cout << counter << " ";
        for (j = 'A'; j <= 'H'; ++j)
        {
            Piece* piece = findPiece(j, i);
            if (piece != nullptr)
            {
                piece->draw();
            }
            else
            {
                if (_isWhite(j, i))
                {
                    std::cout << "\33[0;46m \33[0m";
                }
                else
                {
                    std::cout << "\33[0;42m \33[0m";
                }
            }
        }
        std::cout << " "  << counter--;
        std::cout << std::endl;
    }
    std::cout << "\n  ABCDEFGH\n" << std::endl;
}

// make a castle to the given color, king or queen side
bool Board::_castle(const bool& color, const bool& side)
{
    Piece* king;
    Piece* rook;

    // white king-side
    if (color && side)
    {
        // locations of white king and right white rook in the array
        king = _pieces[WHITE_KING];
        rook = _pieces[WHITE_RROOK];
        if (king->getStarted() || rook->getStarted() ||
            findIndex('F', '1') != -1 || findIndex('G', '1') != -1)
        {
            return false;
        }
        if (_isThreat('E', '1', color) || _isThreat('F', '1', color) || _isThreat('G', '1', color))
        {
            return false;
        }
        king->setPos('G', '1');
        rook->setPos('F', '1');
        return true;
    }
    // white queen-side
    else if (color && !side)
    {
        // locations of white king and left white rook in the array
        king = _pieces[WHITE_KING];
        rook = _pieces[WHITE_LROOK];
        if (king->getStarted() || rook->getStarted() ||
            findIndex('B', '1') != -1 || findIndex('C', '1') != -1 || findIndex('D', '1') != -1)
        {
            return false;
        }
        if (_isThreat('E', '1', color) || _isThreat('D', '1', color) || _isThreat('C', '1', color))
        {
            return false;
        }
        king->setPos('C', '1');
        rook->setPos('D', '1');
        return true;
    }
    // black king-side
    else if (!color && side)
    {
        // locations of white king and right white rook in the array
        king = _pieces[BLACK_KING];
        rook = _pieces[BLACK_RROOK];
        if (king->getStarted() || rook->getStarted() ||
            findIndex('F', '8') != -1 || findIndex('G', '8') != -1)
        {
            return false;
        }
        if (_isThreat('E', '8', color) || _isThreat('F', '8', color) || _isThreat('G', '8', color))
        {
            return false;
        }
        king->setPos('G', '8');
        rook->setPos('F', '8');
        return true;
    }
    // black queen-side
    else
    {
        king = _pieces[BLACK_KING];
        rook = _pieces[BLACK_LROOK];
        if (king->getStarted() || rook->getStarted() ||
            findIndex('B', '8') != -1 || findIndex('C', '8') != -1 || findIndex('D', '8') != -1)
        {
            return false;
        }
        if (_isThreat('E', '8', color) || _isThreat('D', '8', color) || _isThreat('C', '8', color))
        {
            return false;
        }
        king->setPos('C', '8');
        rook->setPos('D', '8');
        return true;
    }
}

// check if there's a threat by the opponent on the given cell
bool Board::_isThreat(const char &x, const char &y, const bool& color) const
{
    int i;
    int n;
    if (color)
    {
        // opponents of white are between 16 to 30
        i = 16;
        n = 30;
    }
    else
    {
        // opponents od black are between 1 to 15
        i = 1;
        n = 15;
    }
    for (; i <= n; ++i)
    {
        Piece* piece = _pieces[i];
        if (piece != nullptr && piece->isLegal(x, y))
        {
            return true;
        }
    }
    return false;
}

/**
 * check if the player with this color is in check.
 * @param color color to check.
 * @return true iff the color given is indeed in check.
 */
bool Board::isCheck(const bool &color) const
{
    Piece* king = color ? _pieces[WHITE_KING] : _pieces[BLACK_KING];
    return _isThreat(king->getX(), king->getY(), color);
}

// check if a given cell has a white piece in it
bool Board::_isWhite(const char posX, const char posY) const
{
    return (posX + posY) % 2 == 1;
}

/**
 * find a piece on the board when given the coordinates of the piece.
 * @param posX x-axis coordinates.
 * @param PosY y-axis coordinates.
 * @return pointer the the piece if it was found, nullptr otherwise.
 */
Piece* Board::findPiece(const char& posX, const char& posY) const
{
    int i;
    for (i = 0; i < PIECES_NUM; i++)
    {
        if (_pieces[i] == nullptr)
        {
            continue;
        }
        else if (_pieces[i]->getX() == posX && _pieces[i]->getY() == posY)
        {
            return _pieces[i];
        }
    }
    return nullptr;
}

/**
 * find a piece on the board when given the coordinates of the piece.
 * @param posX x-axis coordinates.
 * @param PosY y-axis coordinates.
 * @return index of the piece in the array of pieces the board has.
 */
int Board::findIndex(const char& posX, const char& posY) const
{
    int i;
    for (i = 0; i < PIECES_NUM; i++)
    {
        if (_pieces[i] == nullptr)
        {
            continue;
        }
        else if (_pieces[i]->getX() == posX && _pieces[i]->getY() == posY)
        {
            return i;
        }
    }
    return -1;
}

/**
 * check if the player with this color is in mate.
 * @param color color to check.
 * @return true iff the color given is indeed in mate.
 */
bool Board::isMate(const bool& color)
{
    if (!isCheck(color))
    {
        return false;
    }
    Piece* king = color ? _pieces[WHITE_KING] : _pieces[BLACK_KING];
    char x = king->getX();
    char y = king->getY();
    // return true iff the king cant move to any direction
    return  _mateHelper(char(x - 1), char(y - 1), color) && _mateHelper(x, char(y - 1), color) &&
            _mateHelper(char(x + 1), char(y - 1), color) && _mateHelper(char(x - 1), y, color) &&
            _mateHelper(char(x + 1), y, color) && _mateHelper(char(x - 1), char(y + 1), color) &&
            _mateHelper(x, char(y + 1), color) && _mateHelper(char(x + 1), char(y + 1), color);
}

// check if the given color has mated
bool Board::_mateHelper(const char& x, const char& y, const bool &color)
{
    if (x > 'H' || x < 'A' || y > '8' || y < '1')
    {
        return true;
    }
    Piece* king = color ? _pieces[WHITE_KING] : _pieces[BLACK_KING];
    char oldX = king->getX();
    char oldY = king->getY();
    int index = findIndex(x, y);
    if (!king->isLegal(x, y))
    {
        return true;
    }
    king->setPos(x, y);
    Piece* temp = nullptr;
    if (index != -1)
    {
        temp = _pieces[index];
        _pieces[index] = nullptr;
    }
    bool answer = isCheck(color);
    if (index != -1)
    {
        _pieces[index] = temp;
    }
    king->setPos(oldX, oldY);
    return answer;
}

/**
 * make a single piece to a new location if possible.
 * @param position the location of the piece to move and the destination.
 * @param color color to move.
 * @return true iff the move was successful.
 */
bool Board::makeMove(const std::string &position, const bool& color)
{
    if (position == "0-0")
    {
        return _castle(color, true);
    }
    else if (position == "0-0-0")
    {
        return _castle(color, false);
    }
    else if (position.length() != 4)
    {
        return false;
    }
    char oldX = position.at(0);
    char oldY = position.at(1);
    char newX = position.at(2);
    char newY = position.at(3);
    if (!('A' <= oldX && oldX <= 'H' && '1' <= oldY && oldY <= '8' &&
        'A' <= newX && newX <= 'H' && '1' <= newY && newY <= '8'))
    {
        return false;
    }
    Piece* old = findPiece(oldX, oldY);
    if (old == nullptr)
    {
        return false;
    }
    int currentPiece = findIndex(newX, newY);
    bool saveStarted = old->getStarted();

    if (isCheck(color))
    {
        int oldIndex = findIndex(oldX, oldY);
        if (!((oldIndex == 0 && color) || (oldIndex == 31 && !color)))
        {
            // must move the king in check
            return false;
        }
    }
    // piece to move not found or it is a piece of the opponent
    if (old->color != color)
    {
        return false;
    }
    if (!old->isLegal(newX, newY))
    {
        return false;
    }
    old->setPos(newX, newY);
    Piece* temp = nullptr;

    // if there is a piece in the destination cell, we delete it from the board
    if (currentPiece != -1)
    {
        temp = _pieces[currentPiece];
        _pieces[currentPiece] = nullptr;
    }
    // illegal move, restoring everything
    if (isCheck(color))
    {
        old->setPos(oldX, oldY);
        old->setStarted(saveStarted);
        _pieces[currentPiece] = temp;
        return false;
    }
    if (temp != nullptr)
    {
        delete(temp);
    }
    _promotion();
    return true;
}

// check if some pawn need to be promoted
void Board::_promotion()
{
    int i;
    for (i = 0; i < PIECES_NUM; ++i)
    {
        if (_pieces[i] != nullptr && _pieces[i]->isPromote())
        {
            char x = _pieces[i]->getX();
            char y = _pieces[i]->getY();
            bool color = _pieces[i]->color;
            delete(_pieces[i]);
            _pieces[i] = new Queen(x, y, color, this);
            return;
        }
    }
}