// //ID: 208018028, Mail: ronimordechai70@gmail.com
#include "catan.hpp"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib> // for std::rand()
#include "resource.hpp"

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
    std::cout << player.getName() << " want to buy city at point " << point << ":" << std::endl;

    // Check if a city can be added at the specified point on the board
    if (board.canAddCity(point)) {
        player.addCity(point, board);
    } else {
        std::cerr << "Cannot add city at point " << point << ": invalid location or conditions." << std::endl;
    }
}

// Function to convert Resource enum to string
std::string Catan::resourceToString(Resource resource) {
    switch (resource) {
        case Resource::Brick: return "Brick";
        case Resource::Wood: return "Wood";
        case Resource::Sheep: return "Sheep";
        case Resource::Wheat: return "Wheat";
        case Resource::Ore: return "Ore";
        default: return "Unknown";
    }
}

// void Catan::collectMonopolyResources(Player& player, Resource chosenResource) {
//     std::cout << "Player " << player.getName() << " is using Monopoly Card for " << resourceToString(chosenResource) << std::endl;
    
//     int totalResourcesTaken = 0;

//     // Loop through all players and take the chosen resource from them
//     for (Player& otherPlayer : players) {
//         if (&otherPlayer != &player) {  // Avoid taking from the player who played the card
//             int resourcesTaken = otherPlayer.getResource(chosenResource);
//             int test = otherPlayer.getResource(Resource::Sheep);
//             std::cout << otherPlayer.getName() << " have " << test << " " << resourceToString(chosenResource) << std::endl;
//             std::cout << otherPlayer.getName() << " has " << resourcesTaken << " " << resourceToString(chosenResource) << std::endl;
//             if (resourcesTaken > 0) {
//                 player.addResource(chosenResource, resourcesTaken);
//                 otherPlayer.removeResource(chosenResource, resourcesTaken);
//                 totalResourcesTaken += resourcesTaken;
//                 std::cout << "Took " << resourcesTaken << " " << resourceToString(chosenResource) << " from " << otherPlayer.getName() << std::endl;
//             }
//         }
//     }

//     std::cout << "Total " << resourceToString(chosenResource) << " taken: " << totalResourcesTaken << std::endl;
//     std::cout << "Monopoly Card effect finished." << std::endl;
// }

   void Catan::collectMonopolyResources(Player& currentPlayer, Resource chosenResource) {
    int totalAmount = 0;

    // Calculate total amount of chosen resource across all players except currentPlayer
    for (auto& player : players) {
        if (&player != &currentPlayer) {
            totalAmount += player.getResource(chosenResource);
        }
    }

    // Distribute the total amount to the currentPlayer and reset other players' amounts to zero
    for (auto& player : players) {
        if (&player != &currentPlayer) {
            int amount = player.getResource(chosenResource);
            player.removeResource(chosenResource, amount); // Set other players' resource to zero
        }
    }
    currentPlayer.addResource(chosenResource, totalAmount); // Add the total to the currentPlayer

}


} //namesapace ariel


