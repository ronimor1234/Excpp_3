// //ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "player.hpp"
#include "board.hpp"
#include <string>
#include <iostream>
#include <random>
#include <algorithm>

namespace ariel {
    class Catan {
        private:
        std::vector<Player> players;
        Board board;
        Player* currentPlayer;
        Player* startingPlayer;

        public:

        Catan(const Player& p1, const Player& p2, const Player& p3);
    
        void initialize();

        // Method to choose the starting player
        void ChooseStartingPlayer();

        void placeInitialSettlement(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
        void placeSecondSettlement(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    
        // Getter for starting player
        Player* getStartingPlayer() const { return startingPlayer; }

        // Method to get the current board
        Board& getBoard();

        // Method to print the winner
        void printWinner();
        };
} // namespace ariel
#endif // CATAN_HPP

