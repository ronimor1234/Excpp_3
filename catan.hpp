// ID: 208018028, Mail: ronimordechai70@gmail.com
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
        std::vector<Player> players; // Vector to store all players
        Board board; // The game board
        Player* currentPlayer; // Pointer to the current player
        Player* startingPlayer; // Pointer to the starting player
        int point;
        int lastRoll; // Store the last rolled number

    public:
        // Constructor that initializes the game with three players
        Catan(const Player& p1, const Player& p2, const Player& p3);
        
        // for test: constructor to handle more than 3 players
        Catan(const Player& p1, const Player& p2, const Player& p3, const Player& p4);

        // Method to initialize the game
        void initialize();

        // Method to choose the starting player
        void chooseStartingPlayer();

        // Method to place the initial settlement and road for a player
        void placeInitialSettlement(Player& player, int settlementPoint, int roadPoint, Board& board);

        // Method to place the second settlement and road for a player
        void placeSecondSettlement(Player& player, int settlementPoint, int roadPoint, Board& board);

        // Getter for the starting player
        Player* getStartingPlayer() const { return startingPlayer; }

        // Method to get the current game board
        Board& getBoard();

        // Method to print the winner of the game
        void printWinner();

        // Method to add a city to a player
        void addCityToPlayer(Player& player, int point, Board& board);

        // Method to collect monopoly resources for a player
        void collectMonopolyResources(Player& currentPlayer, Resource chosenResource);

        // Method to convert a Resource enum to string
        std::string resourceToString(Resource resource);

        // Getter for the vector of players
        std::vector<Player>& getPlayers() { return players; }

        // Method to get a player by index
        Player& getPlayer(int index);

        // Method to roll the dice for a player
        void rollDice(Player& player);

        // Get the last rolled number
        int getLastRoll() const {return lastRoll;}
    };
} // namespace ariel

#endif // CATAN_HPP
