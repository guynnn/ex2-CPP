#include "Board.h"

/**
 *
 * @return 0 iff the execution was successful.
 */
int main()
{
    Board board;
    std::string whitePlayer, blackPlayer;
    std::cout << "Enter white player name:\n";
    std::cin >> whitePlayer;
    std::cout << "Enter black player name:\n";
    std::cin >> blackPlayer;
    bool currentColor = true;
    std::cout << "\33[2J";
    while (true)
    {
        if (board.isMate(currentColor))
        {
            board.print();
            std::string winner = currentColor ? blackPlayer : whitePlayer;
            std::cout << winner << " won!\n";
            return 0;
        }
        board.print();
        if (board.isCheck(currentColor))
        {
            std::cout << "\33[37;41mCheck!\33[0m" << std::endl;
        }
        std::string position;
        std::string currentPlayer = currentColor ? whitePlayer : blackPlayer;
        std::cout << currentPlayer << ": Please enter your move:\n";
        std::cin >> position;
        if (!board.makeMove(position, currentColor))
        {
            // clear the screen
            std::cout << "\33[37;41millegal move\33[0m" << std::endl;
            std::cout << "\33[2J";
            continue;
        }
        currentColor = !currentColor;
        // clear the screen
        std::cout << "\33[2J";
    }
}