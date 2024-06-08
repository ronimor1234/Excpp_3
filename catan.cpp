// //ID: 208018028, Mail: ronimordechai70@gmail.com
#include "catan.hpp"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib> // for std::rand()

namespace ariel{
Catan::Catan(const Player& p1, const Player& p2, const Player& p3) {
    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);
    currentPlayer = &players[0]; // Assume the first player starts
    board = Board();
}

void Catan::ChooseStartingPlayer() {
    // Get a random starting player
    srand(time(NULL)); // Initialize random seed
    int randomNum = rand() % 3;
    startingPlayer = &players[static_cast<std::vector<Player>::size_type>(randomNum)];

    // Print the starting player's name
    std::cout << "Starting player: " << startingPlayer->getName() << std::endl;
}

void Catan::placeInitialSettlement(Player& player, int settlementPoint, int roadPoint, Board& board) {
    std::cout << player.getName() << " placing initial settlement and road:" << std::endl;
    player.placeSettlement(settlementPoint, board);
    player.placeRoad(settlementPoint, roadPoint, board);
}

void Catan::placeSecondSettlement(Player& player, int settlementPoint, int roadPoint, Board& board) {
    std::cout << player.getName() << " placing second settlement and road:" << std::endl;
    player.placeSettlement(settlementPoint, board);
    player.placeRoad(settlementPoint, roadPoint, board);
}


void Catan::initialize() {
    // Add players to the game
    players.reserve(3); // Reserve space for three players
    players.emplace_back("Player 1");
    players.emplace_back("Player 2");
    players.emplace_back("Player 3");

}

Board& Catan::getBoard() {
    return board;
}

void Catan::printWinner() {
    // Implement logic to determine the winner
    Player* winner = nullptr;
    for (Player& player : players) {
        if (player.getPoints() >= 10) {
            winner = &player;
            break;
        }
    }
    if (winner) {
        std::cout << "Winner: " << winner->getName() << std::endl;
    } else {
        std::cout << "No winner yet." << std::endl;
    }
}

void Catan::addCityToPlayer(Player& player, int point, Board& board) {
    std::cout << player.getName() << " adding a city at point " << point << ":" << std::endl;

    // Check if a city can be added at the specified point on the board
    if (board.canAddCity(point)) {
        player.addCity(point);
    } else {
        std::cerr << "Cannot add city at point " << point << ": invalid location or conditions." << std::endl;
    }
}


} //namesapace ariel


