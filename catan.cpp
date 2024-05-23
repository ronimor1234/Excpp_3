//ID: 208018028, Mail: ronimordechai70@gmail.com
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

void ariel::Catan::ChooseStartingPlayer() {
    std::size_t index = static_cast<std::size_t>(std::rand()) % players.size();  // Use std::size_t and static_cast
    currentPlayer = &players[index];
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
} //namesapace ariel