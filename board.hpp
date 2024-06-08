// // //ID: 208018028, Mail: ronimordechai70@gmail.com
// #ifndef BOARD_HPP
// #define BOARD_HPP

// #include <vector>
// #include <string>
// #include <map>
// #include "tile.hpp"
// #include "settlement.hpp"
// #include "road.hpp"
// #include "city.hpp"
// #include "player.hpp"


// namespace ariel {
//     class Tile;
//     class Player;
//     class Road;
//     class Settlement;
//     class City;
// class Board {
// private:
//     std::map<int, Tile*> tileMap; // For quick lookup by number
//     std::vector<Settlement> settlements;
//     std::vector<City> cities;
//     std::vector<Road> roads;
//     std::map<std::pair<std::string, int>, std::string> occupiedPlaces;

// public:
//     std::vector<Tile> tiles; // vector of a tiles
//     Board();
    
//     // Method to initialize the board with tiles
//     void initializeBoard();

//     // Methods to place settlements and roads
//     bool placeSettlement(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum);
//     bool placeRoad(const Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum);
//     bool isPlaceOccupied(const std::string& place, int placeNum) const;
//     // Helper methods
//     Tile* getTile(int number);
   
//     bool areAdjacent(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const;
//     bool isWithinTwoEdges(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const;

//     // Method to print the current state of the board (optional, for debugging)
//     void printBoard(const std::vector<Tile>& tiles); 

//     int columnIndex(const std::string& column) const;
// };

// } // namespace ariel
// #endif // BOARD_HPP


// //ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include "tile.hpp"
#include "settlement.hpp"
#include "road.hpp"
#include "city.hpp"
#include "player.hpp"
#include <utility>

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
        std::unordered_map<int, std::vector<int>> adjacencyList;
        
        void initializeAdjacencyList();

    public:
        std::vector<Tile> tiles; // vector of tiles

        Board();

        // Method to initialize the board with tiles
        void initializeBoard();

        // Methods to place settlements and roads
        void placeSettlement(int point, const Player& player);
        bool placeRoad(int startPoint, int endPoint, const Player& player);
        bool isPlaceOccupied(const std::string& place, int placeNum) const;

        // Helper methods
        Tile& getTile(int point);
        
        bool areAdjacent(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const;
        bool isWithinTwoEdges(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const;
        std::vector<int> getNeighbors(int point) const;

        // Method to print the current state of the board (optional, for debugging)
        void printBoard();

        int columnIndex(const std::string& column) const;

        // Method to check if a place is adjacent to a road of the player
        bool isPlaceAdjacentToPlayerRoad(const std::pair<std::string, int>& place, const Player& player) const;

        bool isValidSettlementPoint(int point, const Player& player);

        bool isValidRoad(int startPoint, int endPoint, const Player& player);

        bool canAddCity(int point) const;
    };

} // namespace ariel

#endif // BOARD_HPP
