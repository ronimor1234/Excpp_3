// //ID: 208018028, Mail: ronimordechai70@gmail.com
#include "board.hpp"
#include "tile.hpp"
#include <iostream>
#include <algorithm> // For std::shuffle
#include <random>    // For std::default_random_engine and std::random_device
#include <unordered_set>

namespace ariel {

    Board::Board() {
        initializeBoard();
    }

    void Board::initializeBoard() {
        // Clear the tiles vector before adding new tiles
        tiles.clear();
        tileMap.clear();

        // Define the fixed positions and numbers for the tiles according to Catan rules
        std::vector<std::pair<std::string, int>> fixedTiles = {
            {"Forest", 5}, {"Hills", 2}, {"Agricultural Land", 6}, {"Pasture Land", 3}, {"Forest", 8},
            {"Mountains", 10}, {"Agricultural Land", 9}, {"Forest", 12}, {"Pasture Land", 11}, {"Forest", 4},
            {"Desert", 7}, {"Mountains", 8}, {"Agricultural Land", 3}, {"Pasture Land", 4}, {"Mountains", 5},
            {"Hills", 6}, {"Pasture Land", 9}, {"Agricultural Land", 10}, {"Forest", 11}
        };

        for (const auto& tile : fixedTiles) {
            if (tile.first == "Desert") {
                tiles.push_back(Tile(tile.first, tile.second)); // Use Tile for Desert
            } else if (tile.first == "Forest") {
                tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Wood));
            } else if (tile.first == "Hills") {
                tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Brick));
            } else if (tile.first == "Agricultural Land") {
                tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Wheat));
            } else if (tile.first == "Mountains") {
                tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Ore));
            } else if (tile.first == "Pasture Land") {
                tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Sheep));
            }

            if (tile.first != "Desert") {
                tileMap[tile.second] = &tiles.back(); // Map the number to the tile
            }
        }
    }

    bool Board::placeSettlement(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum) {
        for (size_t i = 0; i < places.size(); ++i) {
            auto key = std::make_pair(places[i], placesNum[i]);
            // Check if the place is occupied or within two edges of another settlement
            for (const auto& entry : occupiedPlaces) {
                if (entry.second != player.getName() && isWithinTwoEdges(key, entry.first)) {
                    return false; // Place is within two edges of another settlement
                }
            }
        }
        for (size_t i = 0; i < places.size(); ++i) {
            auto key = std::make_pair(places[i], placesNum[i]);
            occupiedPlaces[key] = player.getName();
        }
        return true;
    }

    bool Board::placeRoad(const Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum) {
        const auto& roadConnections = player.getRoadConnections();

        for (size_t i = 0; i < places.size(); ++i) {
            auto key = std::make_pair(places[i], placesNum[i]);
            if (occupiedPlaces.find(key) != occupiedPlaces.end()) {
                if (occupiedPlaces[key] != player.getName()) {
                    return false; // Place is already occupied by another player
                }
            } else {
                bool connected = false;
                // Check if the new road is connected to any of the player's existing roads or settlements
                for (const auto& connection : roadConnections) {
                    if (areAdjacent(key, connection)) {
                        connected = true;
                        break;
                    }
                }
                if (!connected) {
                    // Optionally, check if the road is connected to any of the player's settlements
                    for (const auto& settlement : player.getSettlements()) {
                        if (areAdjacent(key, settlement)) {
                            connected = true;
                            break;
                        }
                    }
                }
                if (!connected) {
                    return false; // New road is not connected to existing roads or settlements
                }
            }
        }

        for (size_t i = 0; i < places.size(); ++i) {
            auto key = std::make_pair(places[i], placesNum[i]);
            occupiedPlaces[key] = player.getName();
        }

        return true;
    }

    bool Board::isPlaceOccupied(const std::string& place, int placeNum) const {
        auto key = std::make_pair(place, placeNum);
        return occupiedPlaces.find(key) != occupiedPlaces.end();
    }

    bool Board::areAdjacent(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const {
        // Implement logic to check if places a and b are adjacent
        // This logic is simplified and might need to be adapted based on the board structure
        return abs(a.second - b.second) == 1;
    }

    bool Board::isWithinTwoEdges(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const {
        // Implement logic to check if places a and b are within two edges of each other
        // This logic is simplified and might need to be adapted based on the board structure
        return abs(a.second - b.second) <= 2;
    }

    Tile* Board::getTile(int number) {
        if (tileMap.find(number) != tileMap.end()) {
            return tileMap[number];
        }
        return nullptr;
    }


    void ariel::Board::printBoard(const std::vector<ariel::Tile>& tiles) {
    if (tiles.size() != 19) {
        std::cerr << "Error: The number of tiles should be 19 for a Catan board." << std::endl;
        return;
    }
    std::cout << "####### THE BOARD OF THE GAME #######" << std::endl;
    std::vector<int> rowSizes = {3, 4, 5, 4, 3};
    size_t tileIndex = 0; // Use size_t for tileIndex to match the type of vector indices

    // Top sea row
    std::cout << "            sea      sea     sea     sea" << std::endl;

    for (std::size_t i = 0; i < rowSizes.size(); ++i) {
        int numTilesInRow = rowSizes[i];
        int spacesBeforeRow = 5 - numTilesInRow;

        // Print leading spaces for sea
        for (int s = 0; s < spacesBeforeRow; ++s) {
            std::cout << "  ";
        }

        // Print sea at the beginning of the row
        std::cout << "sea ";

        // Print tiles in the row
        for (int j = 0; j < numTilesInRow; ++j) {
            std::string tileType = tiles[tileIndex].getType();
            int tileNumber = tiles[tileIndex].getNumber();
            std::cout << " " << tileType << "(" << tileNumber << ") ";
            tileIndex++;
        }

        // Print sea at the end of the row
        std::cout << " sea" << std::endl;
    }

    // Bottom sea row
    std::cout << "            sea      sea      sea      sea" << std::endl;
    std::cout << "#####################################" << std::endl;
}



} // namespace ariel

