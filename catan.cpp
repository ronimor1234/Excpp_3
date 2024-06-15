// ID: 208018028, Mail: ronimordechai70@gmail.com
#include "catan.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <tuple>
#include <ctime>
#include <cstdlib> // for std::rand()
#include "resource.hpp"
#include "player.hpp"

namespace ariel {

    // Constructor to initialize the game with three players
    Catan::Catan(const Player& p1, const Player& p2, const Player& p3) {
        players.push_back(p1);
        players.push_back(p2);
        players.push_back(p3);
        currentPlayer = &players[0]; // Assume the first player starts
        board = Board();
    }

    // Constructor to handle more than 3 players
    Catan::Catan(const Player& p1, const Player& p2, const Player& p3, const Player& p4) {
        (void)p1; // Suppress unused parameter warning
        (void)p2; // Suppress unused parameter warning
        (void)p3; // Suppress unused parameter warning
        (void)p4; // Suppress unused parameter warning
        throw std::invalid_argument("Catan can only be initialized with exactly 3 players.");
    }


    // Randomly chooses a starting player among the three
    void Catan::chooseStartingPlayer() {
        srand(time(NULL)); // Initialize random seed
        int randomNum = rand() % 3;
        startingPlayer = &players[static_cast<std::vector<Player>::size_type>(randomNum)];

        // Print the starting player's name
        std::cout << "Starting player: " << startingPlayer->getName() << std::endl;
    }

    // Places the initial settlement and road for a player
    void Catan::placeInitialSettlement(Player& player, int settlementPoint, int roadPoint, Board& board) {
        std::cout << player.getName() << " placing initial settlement and road:" << std::endl;
        player.placeSettlement(settlementPoint, board);
        player.placeRoad(settlementPoint, roadPoint, board);
    }

    // Places the second settlement and road for a player
    void Catan::placeSecondSettlement(Player& player, int settlementPoint, int roadPoint, Board& board) {
        std::cout << player.getName() << " placing second settlement and road:" << std::endl;
        player.placeSettlement(settlementPoint, board);
        player.placeRoad(settlementPoint, roadPoint, board);

        std::vector<std::tuple<std::string, int, std::vector<int>, Resource>> fixedTiles = {
            {"Mountains", 10, {1, 2, 3, 9, 10, 11}, Resource::Ore},
            {"Pasture Land", 2, {3, 4, 5, 11, 12, 13}, Resource::Sheep},
            {"Forest", 9, {5, 6, 7, 13, 14, 15}, Resource::Wood},
            {"Agricultural Land", 12, {8, 9, 10, 18, 19, 20}, Resource::Wheat},
            {"Hills", 6, {10, 11, 12, 22, 21, 20}, Resource::Brick},
            {"Pasture Land", 4, {12, 13, 14, 24, 23, 22}, Resource::Sheep},
            {"Hills", 10, {14, 15, 16, 26, 25, 24}, Resource::Brick},
            {"Agricultural Land", 9, {17, 18, 19, 28, 29, 30}, Resource::Wheat},
            {"Forest", 11, {19, 20, 21, 32, 31, 30}, Resource::Wood},
            {"Forest", 3, {23, 24, 25, 36, 35, 34}, Resource::Wood},
            {"Mountains", 8, {25, 26, 27, 38, 37, 36}, Resource::Ore},
            {"Forest", 8, {29, 30, 31, 41, 40, 39}, Resource::Wood},
            {"Mountains", 3, {31, 32, 33, 43, 42, 41}, Resource::Ore},
            {"Agricultural Land", 4, {33, 34, 35, 45, 44, 43}, Resource::Wheat},
            {"Pasture Land", 5, {35, 36, 37, 47, 46, 45}, Resource::Sheep},
            {"Hills", 5, {40, 41, 42, 50, 49, 48}, Resource::Brick},
            {"Agricultural Land", 6, {42, 43, 52, 51, 50, 44}, Resource::Wheat},
            {"Pasture Land", 11, {44, 45, 46, 54, 53, 52}, Resource::Sheep}
        };

        for (const auto& tile : fixedTiles) {
                if (std::find(std::get<2>(tile).begin(), std::get<2>(tile).end(), settlementPoint) != std::get<2>(tile).end()) {
                    player.addResource(std::get<3>(tile),1);}
                }
    }

    // Initializes the game by adding three players
    void Catan::initialize() {
        players.reserve(3); // Reserve space for three players
        players.emplace_back("Player 1");
        players.emplace_back("Player 2");
        players.emplace_back("Player 3");
    }

    // Returns the game board
    Board& Catan::getBoard() {
        return board;
    }

    // Prints the winner of the game
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

    // Adds a city to a player at the specified point on the board
    void Catan::addCityToPlayer(Player& player, int point, Board& board) {
        std::cout << player.getName() << " wants to buy city at point " << point << ":" << std::endl;

        // Check if a city can be added at the specified point on the board
        if (board.canAddCity(point)) {
            player.addCity(point, board);
        } else {
            std::cerr << "Cannot add city at point " << point << ": invalid location or conditions." << std::endl;
        }
    }

    // Converts a Resource enum value to its string representation
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

    // Collects monopoly resources of a chosen type from other players and adds them to the current player
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

    // Retrieves a player by index
    Player& Catan::getPlayer(int index) {
        if (index < 0 || static_cast<size_t>(index) >= players.size()) {
            throw std::out_of_range("Player index out of range");
        }
        return players[static_cast<size_t>(index)];
    }

    // Simulates rolling dice and distributes resources to players based on the dice roll
    void Catan::rollDice(Player& player) {
        int roll = std::rand() % 6 + 1 + std::rand() % 6 + 1; // Rolling two six-sided dice

        // If the roll is 7, roll again
        while (roll == 7) {
            std::cout << "A 7 was rolled! Rolling again." << std::endl;
            roll = std::rand() % 6 + 1 + std::rand() % 6 + 1; // Rolling two six-sided dice again
        }
        std::cout << player.getName() << " rolled: " << roll << std::endl;

        // Fixed tiles with their associated resources and points
        std::vector<std::tuple<std::string, int, std::vector<int>, Resource>> fixedTiles = {
            {"Mountains", 10, {1, 2, 3, 9, 10, 11}, Resource::Ore},
            {"Pasture Land", 2, {3, 4, 5, 11, 12, 13}, Resource::Sheep},
            {"Forest", 9, {5, 6, 7, 13, 14, 15}, Resource::Wood},
            {"Agricultural Land", 12, {8, 9, 10, 18, 19, 20}, Resource::Wheat},
            {"Hills", 6, {10, 11, 12, 22, 21, 20}, Resource::Brick},
            {"Pasture Land", 4, {12, 13, 14, 24, 23, 22}, Resource::Sheep},
            {"Hills", 10, {14, 15, 16, 26, 25, 24}, Resource::Brick},
            {"Agricultural Land", 9, {17, 18, 19, 28, 29, 30}, Resource::Wheat},
            {"Forest", 11, {19, 20, 21, 32, 31, 30}, Resource::Wood},
            {"Forest", 3, {23, 24, 25, 36, 35, 34}, Resource::Wood},
            {"Mountains", 8, {25, 26, 27, 38, 37, 36}, Resource::Ore},
            {"Forest", 8, {29, 30, 31, 41, 40, 39}, Resource::Wood},
            {"Mountains", 3, {31, 32, 33, 43, 42, 41}, Resource::Ore},
            {"Agricultural Land", 4, {33, 34, 35, 45, 44, 43}, Resource::Wheat},
            {"Pasture Land", 5, {35, 36, 37, 47, 46, 45}, Resource::Sheep},
            {"Hills", 5, {40, 41, 42, 50, 49, 48}, Resource::Brick},
            {"Agricultural Land", 6, {42, 43, 52, 51, 50, 44}, Resource::Wheat},
            {"Pasture Land", 11, {44, 45, 46, 54, 53, 52}, Resource::Sheep}
        };

        // Iterate through all tiles to find and process those with the rolled number
        for (const auto& tile : fixedTiles) {
            std::string terrain;
            int tileRoll;
            std::vector<int> points;
            Resource resource;

            std::tie(terrain, tileRoll, points, resource) = tile;

            // Process only the tiles that match the rolled number
            if (tileRoll == roll) {
                for (int point : points) {
                    for (auto& settlement : player.getSettlements()) {
                        if (point == settlement.getPoint() || point == settlement.getPlaceNum()) {
                            std::cout << "Matching tile: " << terrain << ", Roll: " << roll << ", Resource: " << resourceToString(resource) << std::endl;
                            std::cout << "Distributing resource: " << resourceToString(resource) << " to player: " << player.getName() << std::endl;
                            int amount = settlement.getIsCity() ? 2 : 1;
                            player.addResource(resource, amount); // Assuming addResource takes amount as a parameter
                        }
                    }
                }
            }
        }
    }

} // namespace ariel

