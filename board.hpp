// ID: 208018028, Mail: ronimordechai70@gmail.com
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

    // Forward declarations
    class Tile;
    class Player;
    class Road;
    class Settlement;
    class City;

    // Class representing the game board
    class Board {
    private:
        // Data members
        std::map<int, Tile*> tileMap;                                      // For quick lookup by number
        std::vector<Settlement> settlements;                               // List of settlements on the board
        std::vector<Player> players;                                       // List of players in the game
        std::vector<City> cities;                                          // List of cities on the board
        std::vector<Road> roads;                                           // List of roads on the board
        std::map<std::pair<std::string, int>, std::string> occupiedPlaces; // Occupied places on the board
        std::unordered_map<int, std::vector<int>> adjacencyList;           // Adjacency list for places

        // Private methods
        void initializeAdjacencyList();             // Initialize adjacency list for board places

    public:
        std::vector<Tile> tiles;                    // Vector of tiles on the board

        // Constructors
        Board();                                  

        // Initialization methods
        void initializeBoard();                     // Initialize the board with tiles

        // Getter to OccupiedPlaces and Settlements
        const std::map<std::pair<std::string, int>, std::string>& getOccupiedPlaces() const {return occupiedPlaces;}
        const std::vector<Settlement>& getSettlements() const { return settlements;}
        
        // Methods to place settlements and roads
        bool placeSettlement(int point, const std::string& playerName);     // Place a settlement
        bool placeRoad(int startPoint, int endPoint, const Player& player); // Place a road
        bool isPlaceOccupied(int point) const;                              // Check if a place is occupied

        // Helper methods
        Tile& getTile(int point);                   // Get a tile by its point
        bool areAdjacent(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const; // Check adjacency between places
        bool isWithinTwoEdges(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const; // Check distance between places
        std::vector<int> getNeighbors(int point) const; // Get neighbors of a place

        // Debugging method 
        void printBoard();                          // Print the board state

        // Utility methods
        int columnIndex(const std::string& column) const; // Get column index
        bool isPlaceAdjacentToPlayerRoad(const std::pair<std::string, int>& place, const Player& player) const; // Check if place is adjacent to player's road
        bool isValidSettlementPoint(int point, const Player& player); // Check if settlement point is valid for player
        bool isValidRoad(int startPoint, int endPoint, const Player& player) const; // Check if road is valid for player
        bool canAddCity(int point) const;            // Check if a city can be added
        void upgradeSettlementToCity(int point, const std::string& playerName); // Upgrade settlement to city
        bool hasSettlementOrCity(int point, const std::string& playerName) const; // Check if player has settlement or city at point
        void printBoardState() const;                // Print current board state
        std::vector<Tile*> getTilesByNumber(int number) const; // Get tiles by their number
        bool hasSettlementOrCityOnTile(const std::string& playerName, int tileNumber) const; // Check if player has settlement or city on a tile
    };

} // namespace ariel

#endif // BOARD_HPP
