// // //ID: 208018028, Mail: ronimordechai70@gmail.com
// #ifndef PLAYER_HPP
// #define PLAYER_HPP
// #include <set>
// #include <string>
// #include <vector>
// #include <memory>
// #include <map>
// #include "settlement.hpp"
// #include "road.hpp"
// #include "development_card.hpp"
// #include "resource.hpp" 
// #include "board.hpp"
// #include "tile.hpp"

// namespace ariel {
//     class Tile;
//     class Settlement;
//     class Road;
//     class Board;

// class Player {
// private:
//     std::string name;
//     std::vector<Settlement> settlements;
//     std::vector<Road> roads;
//     std::map<Resource, int> resources; 
//     std::vector<std::shared_ptr<DevelopmentCard>> developmentCards;
//     int points;
//     std::set<std::pair<std::string, int>> roadConnections;
    
// public:
    
//     Player() : name("Default Player"), points(0) {}

//     Player(const std::string& name);

//     Player(const char* name) : name(name), points(0) {}
    
//     void placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
//     bool canPlaceSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, const Board& board) const;
//     void placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
//     bool canPlaceRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, const Board& board) const;
//     void rollDice();
//     void endTurn();
//     void trade(Player& other, const std::string& give, const std::string& receive, int giveAmount, int receiveAmount); // Use Resource enum here
//     void buyDevelopmentCard(std::shared_ptr<DevelopmentCard> card);
//     void printPoints() const;

//     // Getters and Setters
//     std::string getName() const;
//     int getPoints() const;
//     int getResource(Resource resource) const;
//     // Methods to add settlements and roads
//     void addSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum);
//     void addRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum);

//     const std::set<std::pair<std::string, int>>& getRoadConnections() const;
//     std::set<std::pair<std::string, int>> getSettlementLocations() const;
//     // std::set<std::pair<std::string, int>> getSettlements() const;

//     // Resource management
//     void addResource(Resource resource, int amount);
//     void removeResource(Resource resource, int amount);

//     const std::vector<Road>& getRoads() const;
//     const std::vector<Settlement>& getSettlements() const;
//     bool hasRoadAt(int place) const;
// };

// } // namespace ariel

// #endif // PLAYER_HPP
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <set>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include "settlement.hpp"
#include "road.hpp"
#include "development_card.hpp"
#include "resource.hpp"
#include "board.hpp"

namespace ariel {

class Board;
class DevelopmentCard;
class Catan;

class Player {
private:
    std::string name;
    std::vector<Settlement> settlements; // List of settlements owned by the player
    std::vector<Road> roads; // List of roads owned by the player
    std::map<Resource, int> resources; // Map to track resources owned by the player
    std::vector<std::shared_ptr<DevelopmentCard>> developmentCards; // List of development cards owned by the player
    int points; // Player's total points
    std::set<std::pair<int, int>> roadConnections; // Set to track road connections owned by the player
    int knightCount = 0;
    bool largestArmy = false;

public:
    Player() : name("Default Player"), points(0) {}

    Player(const std::string& name);

    Player(const char* name) : name(name), points(0) {}

    void placeSettlement(int point, Board& board);
    bool canPlaceSettlement(int point, const Board& board) const;
    void placeRoad(int startPoint, int endPoint, Board& board);
    bool canPlaceRoad(int startPoint, int endPoint, const Board& board) const;
    void rollDice();
    void endTurn();
    void trade(Player& other, const std::string& give, const std::string& receive, int giveAmount, int receiveAmount); // Use Resource enum here
    void buyDevelopmentCard(std::shared_ptr<DevelopmentCard> card);
    void useDevelopmentCard(const std::string& cardName, Catan& catan);
    void printPoints() const;
    void printPlayerInfo() const;

    void addKnightCard();
    void checkLargestArmy();
    bool hasLargestArmy() const;


    // Getters and Setters
    std::string getName() const;
    int getPoints() const;
    int getResource(Resource resource) const;

    // Functions for managing settlements and cities
    void addSettlement(int point);
    bool hasSettlement(int point) const;
    void addCity(int point, Board& board);
    bool hasSettlementOrCity(int point) const;

    // Functions for managing roads
    void addRoad(int startPoint, int endPoint, Board& board);
    bool hasRoad(int startPoint, int endPoint) const;

    const std::set<std::pair<int, int>>& getRoadConnections() const;
    std::set<int> getSettlementLocations() const; // Return only the points of settlements

    // Resource management
    void addResource(Resource resource, int amount);
    void removeResource(Resource resource, int amount);

    const std::vector<Road>& getRoads() const;
    const std::vector<Settlement>& getSettlements() const;
    bool hasRoadAt(int point) const;

    void addPoints(int points);

     // Getter for resources
    const std::map<Resource, int>& getResources() const {
        return resources;
    }



};

} // namespace ariel

#endif // PLAYER_HPP
