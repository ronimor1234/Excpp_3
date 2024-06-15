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

        void placeInitialSettlement(Player& player, int settlementPoint, int roadPoint, Board& board);
        void placeSecondSettlement(Player& player, int settlementPoint, int roadPoint, Board& board);
    
        // Getter for starting player
        Player* getStartingPlayer() const { return startingPlayer; }

        // Method to get the current board
        Board& getBoard();

        // Method to print the winner
        void printWinner();

        // Method to add city
        void addCityToPlayer(Player& player, int point, Board& board);

        void collectMonopolyResources(Player& currentPlayer, Resource chosenResource);
        std:: string resourceToString(Resource resource);
        std::vector<Player>& getPlayers() { return players; }
        Player& getPlayerByName(const std::string& name);
        Player& getPlayer(int index);
        void distributeResources(int roll);
        void rollDice(Player& player);

        };
} // namespace ariel
#endif // CATAN_HPP

