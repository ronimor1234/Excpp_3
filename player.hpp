//ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef PLAYER_HPP
#define PLAYER_HPP

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
    class Settlement;
    class Board;
class Player {
private:
    std::string name;
    std::vector<Settlement> settlements;
    std::vector<Road> roads;
    std::map<Resource, int> resources; 
    std::vector<std::shared_ptr<DevelopmentCard>> developmentCards;
    int points;

public:
    
    Player() : name("Default Player"), points(0) {}

    Player(const std::string& name) : name(name), points(0) {}

    Player(const char* name) : name(name), points(0) {}
    
    void placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    void placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    void rollDice();
    void endTurn();
    void trade(Player& other, Resource give, Resource receive, int giveAmount, int receiveAmount); // Use Resource enum here
    void buyDevelopmentCard(std::shared_ptr<DevelopmentCard> card);
    void printPoints() const;

    // Getters and Setters
    std::string getName() const;
    int getPoints() const;

    // Methods to add settlements and roads
    void addSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum);
    void addRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum);

    // Resource management
    void addResource(Resource resource, int amount);
    void removeResource(Resource resource, int amount);
};

} // namespace ariel

#endif // PLAYER_HPP
