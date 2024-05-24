//ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "player.hpp"
#include "board.hpp"

namespace ariel {
class Catan {
private:
    std::vector<Player> players;
    Board board;
    Player* currentPlayer;

public:
    Catan() = default; // Default constructor

    Catan(const Player& p1, const Player& p2, const Player& p3);
    
    void initialize();

    // Method to choose the starting player
    void ChooseStartingPlayer();
    
    // Method to get the current board
    Board& getBoard();

    // Method to print the winner
    void printWinner();
    };
} // namespace ariel
#endif // CATAN_HPP
