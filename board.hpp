//ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
#include <map>
#include "tile.hpp"
#include "settlement.hpp"
#include "road.hpp"
#include "player.hpp"


namespace ariel {
    class Tile;
    class Player;
    class Road;
    class Settlement;
class Board {
private:
    std::vector<Tile> tiles; // vector of a tiles
    std::map<int, Tile*> tileMap; // For quick lookup by number
    std::vector<Settlement> settlements;
    std::vector<Road> roads;

public:
    Board();
    
    // Method to initialize the board with tiles
    void initializeBoard();

    // Methods to place settlements and roads
    bool placeSettlement(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum);
    bool placeRoad(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum);
    
    // Helper methods
    Tile* getTile(int number);
    bool isValidSettlementPlacement(const std::vector<int>& placesNum);
    bool isValidRoadPlacement(const std::vector<int>& placesNum);

    // Method to print the current state of the board (optional, for debugging)
    void printBoard() const;
};

} // namespace ariel
#endif // BOARD_HPP
