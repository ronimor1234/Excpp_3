//ID: 208018028, Mail: ronimordechai70@gmail.com
#include "board.hpp"
#include "tile.hpp"
#include <iostream>

namespace ariel {

    Board::Board() {
        initializeBoard();
    }

    void Board::initializeBoard() {
        tiles.push_back(ResourceTile("Forest", 5, Resource::Wood));
        tiles.push_back(ResourceTile("Hills", 6, Resource::Brick));
        tiles.push_back(ResourceTile("Agricultural Land", 3, Resource::Wheat));
        tiles.push_back(DesertTile("Desert", 4));
        tiles.push_back(ResourceTile("Mountains", 9, Resource::Ore));
        tiles.push_back(ResourceTile("Pasture Land", 8, Resource::Sheep));
        
        for (auto& tile : tiles) {
            tileMap[tile.getNumber()] = &tile;
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

    void Board::printBoard() const {
    std::size_t numRows = 7;
    std::size_t numCols = 7;
    
    // Print the top border
    std::cout << "####### THE BOARD OF THE GAME #######" << std::endl;
    std::cout << "                    ";
    for (std::size_t i = 0; i < numCols; ++i) {
        std::cout << "sea ";
    }
    std::cout << std::endl;

    // Print the rows
    for (std::size_t i = 0; i < numRows; ++i) {
        std::cout << "       ";
        if (i % 2 == 0) std::cout << " ";
        for (std::size_t j = 0; j < numCols; ++j) {
            std::string tileType = tiles[i * numCols + j].getType();
            int tileNumber = tiles[i * numCols + j].getNumber();
            std::cout << " " << tileType << "(" << tileNumber << ") ";
        }
        std::cout << " sea" << std::endl;
    }

    // Print the bottom border
    std::cout << "                    ";
    for (std::size_t i = 0; i < numCols; ++i) {
        std::cout << "sea ";
    }
    std::cout << std::endl;
    std::cout << "#####################################" << std::endl;
}


} // namespace ariel
