// ID: 208018028, Mail: ronimordechai70@gmail.com

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
#include "city.hpp"

namespace ariel {

    class Board;
    class DevelopmentCard;
    class Catan;
    class City;

    class Player {
    private:
        std::string name;
        std::vector<Settlement> settlements; // List of settlements owned by the player
        std::vector<Road> roads; // List of roads owned by the player
        std::vector<City> cities; // List of cities owned by the player
        std::map<Resource, int> resources; // Map to track resources owned by the player
        std::vector<std::shared_ptr<DevelopmentCard>> developmentCards; // List of development cards owned by the player
        int points; // Player's total points
        std::set<std::pair<int, int>> roadConnections; // Set to track road connections owned by the player
        int knightCount = 0; // Number of knight cards owned by the player
        bool largestArmy = false; // Flag indicating if the player has the largest army

    public:
        // Constructors
        Player() : name("Default Player"), points(0) {}
        Player(const std::string& name);
        Player(const char* name) : name(name), points(0) {}

        // Main actions
        void placeSettlement(int point, Board& board);
        bool canPlaceSettlement(int point, const Board& board) const;
        void placeRoad(int startPoint, int endPoint, Board& board);
        bool canPlaceRoad(int startPoint, int endPoint, const Board& board) const;
        void endTurn();
        void trade(Player& other, const std::string& give, const std::string& receive, int giveAmount, int receiveAmount);
        void buyDevelopmentCard(std::shared_ptr<DevelopmentCard> card);
        void useDevelopmentCard(const std::string& cardName, Catan& catan);
        void printPoints() const;
        void printPlayerInfo() const;

        // Knight card related
        void addKnightCard();
        void checkLargestArmy();
        bool hasLargestArmy() const;

        // Getters and Setters
        std::string getName() const;
        int getPoints() const;
        int getResource(Resource resource) const;

        // Settlement and city management
        void addSettlement(int point);
        bool hasSettlement(int point) const;
        bool hasCityAt(int point) const;
        void addCity(int point, Board& board);
        bool hasSettlementOrCity(int point) const;

        // Road management
        bool addRoad(int startPoint, int endPoint, Board& board);
        bool hasRoad(int startPoint, int endPoint) const;
        const std::set<std::pair<int, int>>& getRoadConnections() const;

        // Resource management
        void addResource(Resource resource, int amount);
        void removeResource(Resource resource, int amount);
        const std::map<Resource, int>& getResources() const;
        Resource stringToResource(const std::string& resourceStr);

        // Getters for settlements and roads
        const std::vector<Road>& getRoads() const;
        const std::vector<Settlement>& getSettlements() const;
        bool hasRoadAt(int point) const;
        bool hasSettlementAt(int point) const; 
        int numSettlementsAt(int point) const;
        std::set<int> getSettlementLocations() const;

        // Add points to the player
        void addPoints(int points);

        // Resource conversion to string
        std::string resourceToString(Resource resource);

        // print status of the player
        void printStatus();

        //get to knightCount
        int getknightCount() {return knightCount;}
    };

} // namespace ariel

#endif // PLAYER_HPP
