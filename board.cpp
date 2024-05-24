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
            return false;
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
        // Implement the logic to check if the placement is valid
        // For example, ensure no overlapping settlements and valid locations
        for (int num : placesNum) {
            if (tileMap.find(num) == tileMap.end()) {
                return false;
            }
        }
        return true;
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
        // Optional: Implement a method to print the current state of the board for debugging
        for (const Tile& tile : tiles) {
            std::cout << "Tile: " << tile.getType() << ", Number: " << tile.getNumber() << std::endl;
        }
    }

} // namespace ariel
