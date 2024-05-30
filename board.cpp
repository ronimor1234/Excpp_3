//ID: 208018028, Mail: ronimordechai70@gmail.com
#include "board.hpp"
#include "tile.hpp"
#include <iostream>
#include <algorithm> // For std::shuffle
#include <random>    // For std::default_random_engine and std::random_device

namespace ariel {

    Board::Board() {
        initializeBoard();
    }

    void Board::initializeBoard() {
    // Clear the tiles vector before adding new tiles
    tiles.clear();

    // Define the distribution of numbers according to Catan rules
    std::vector<int> diceNumbers = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(diceNumbers.begin(), diceNumbers.end(), rng);

    // Add tiles in the order of types (e.g., Forest, Hills, Agricultural Land, etc.)
    for (int i = 0; i < 4; ++i) {
        tiles.push_back(ResourceTile("Forest", i + 1, Resource::Wood));
        tiles.push_back(ResourceTile("Hills", i + 5, Resource::Brick));
        tiles.push_back(ResourceTile("Agricultural Land", i + 9, Resource::Wheat));
    }
    for (int i = 0; i < 3; ++i) {
        tiles.push_back(ResourceTile("Mountains", i + 13, Resource::Ore));
        tiles.push_back(ResourceTile("Pasture Land", i + 16, Resource::Sheep));
    }
    tiles.push_back(DesertTile("Desert", 7)); // i will assume that the number of the desert will be 7 becouse the knight

    // Assign the numbers to the tiles
    std::size_t diceIndex = 0;
    for (std::size_t i = 0; i < tiles.size(); ++i) {
        if (tiles[i].getType() != "Desert") { // Exclude Desert tile
            tiles[i].setNumber(diceNumbers[diceIndex]); // Set the number for the tile
            tileMap[diceNumbers[diceIndex]] = &tiles[i]; // Map the number to the tile
            diceIndex++;
        }
    }
}


    bool Board::placeSettlement(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum) {
        if (!isValidSettlementPlacement(placesNum)) {
             throw std::runtime_error("Invalid settlement placement.");
        }
        for (int num : placesNum) {
            settlements.push_back(Settlement(player, *getTile(num)));
        }
        player.addSettlement(places, placesNum);
        return true;
    }

    bool Board::placeRoad(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum) {
        if (!isValidRoadPlacement(placesNum)) {
            return false;
        }
        for (size_t i = 0; i < placesNum.size() - 1; ++i) {
            roads.push_back(Road(player, *getTile(placesNum[i]), *getTile(placesNum[i + 1])));
        }
        player.addRoad(places, placesNum);
        return true;
    }

    Tile* Board::getTile(int number) {
        if (tileMap.find(number) != tileMap.end()) {
            return tileMap[number];
        }
        return nullptr;
    }

    bool Board::isValidSettlementPlacement(const std::vector<int>& placesNum) {
        for (int num : placesNum) {
            if (tileMap.find(num) == tileMap.end()) {
                return false; // Tile number not found, placement is invalid
            }

            for (const Settlement& settlement : settlements) {
                if (&settlement.location == getTile(num)) {
                    return false; // Tile already occupied, placement is invalid
                }
            }
        }
        return true; // All tile numbers are valid and not occupied, placement is valid
    }


    bool Board::isValidRoadPlacement(const std::vector<int>& placesNum) {
        // Implement the logic to check if the placement is valid
        // For example, ensure roads are connected correctly
        for (int num : placesNum) {
            if (tileMap.find(num) == tileMap.end()) {
                return false;
            }
        }
        return true;
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
