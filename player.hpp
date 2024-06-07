// //ID: 208018028, Mail: ronimordechai70@gmail.com
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
#include "tile.hpp"

namespace ariel {
    class Tile;
    class Settlement;
    class Road;
    class Board;

class Player {
private:
    std::string name;
    std::vector<Settlement> settlements;
    std::vector<Road> roads;
    std::map<Resource, int> resources; 
    std::vector<std::shared_ptr<DevelopmentCard>> developmentCards;
    int points;
    std::set<std::pair<std::string, int>> roadConnections;
    
public:
    
    Player() : name("Default Player"), points(0) {}

    Player(const std::string& name);

    Player(const char* name) : name(name), points(0) {}
    
    void placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    bool canPlaceSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, const Board& board) const;
    void placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    bool canPlaceRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, const Board& board) const;
    void rollDice();
    void endTurn();
    void trade(Player& other, const std::string& give, const std::string& receive, int giveAmount, int receiveAmount); // Use Resource enum here
    void buyDevelopmentCard(std::shared_ptr<DevelopmentCard> card);
    void printPoints() const;

    // Getters and Setters
    std::string getName() const;
    int getPoints() const;
    int getResource(Resource resource) const;
    // Methods to add settlements and roads
    void addSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum);
    void addRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum);

    const std::set<std::pair<std::string, int>>& getRoadConnections() const;
    std::set<std::pair<std::string, int>> getSettlementLocations() const;
    std::set<std::pair<std::string, int>> getSettlements() const;

    // Resource management
    void addResource(Resource resource, int amount);
    void removeResource(Resource resource, int amount);
};

} // namespace ariel

#endif // PLAYER_HPP
