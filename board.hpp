// //ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
#include <map>
#include "tile.hpp"
#include "settlement.hpp"
#include "road.hpp"
#include "city.hpp"
#include "player.hpp"


namespace ariel {
    class Tile;
    class Player;
    class Road;
    class Settlement;
    class City;
class Board {
private:
    std::map<int, Tile*> tileMap; // For quick lookup by number
    std::vector<Settlement> settlements;
    std::vector<City> cities;
    std::vector<Road> roads;
    std::map<std::pair<std::string, int>, std::string> occupiedPlaces;

public:
    std::vector<Tile> tiles; // vector of a tiles
    Board();
    
    // Method to initialize the board with tiles
    void initializeBoard();

    // Methods to place settlements and roads
    bool placeSettlement(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum);
    bool placeRoad(const Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum);
    bool isPlaceOccupied(const std::string& place, int placeNum) const;
    // Helper methods
    Tile* getTile(int number);
   
    bool areAdjacent(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const;
    bool isWithinTwoEdges(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const;

    // Method to print the current state of the board (optional, for debugging)
    void printBoard(const std::vector<Tile>& tiles); 
};

} // namespace ariel
#endif // BOARD_HPP

