//ID: 208018028, Mail: ronimordechai70@gmail.com

#include "player.hpp"
#include "board.hpp"
#include "settlement.hpp"
#include "road.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "development_card.hpp"
#include <string>


namespace ariel {

// Constructor with name
Player::Player(const std::string& name) : name(name), points(0) {
    //Initialize all resources to 0
    resources[Resource::Wood] = 0;
    resources[Resource::Brick] = 0;
    resources[Resource::Wheat] = 0;
    resources[Resource::Ore] = 0;
    resources[Resource::Sheep] = 0;
}

// Place a settlement at a given point on the board
void Player::placeSettlement(int point, Board& board) {
    if (canPlaceSettlement(point, board)) {
        addSettlement(point); // Add settlement to player's settlements
        board.placeSettlement(point, getName()); // Update the board with the settlement
        points += 1; // Each settlement is worth 1 point
    } else {
        std::cerr << getName() << " failed to place a settlement." << std::endl;
    }
}

// Check if a settlement can be placed at a given point
bool Player::canPlaceSettlement(int point, const Board& board) const {
    // Allow placing the first two settlements without additional checks
    if (settlements.size() < 2) {
        // return !board.isPlaceOccupied("some_place", point);
        return !board.isPlaceOccupied(point);
    }

    // Additional checks for subsequent settlements
    if (board.isPlaceOccupied(point)) {
        return false;
    }
    if (!board.isPlaceAdjacentToPlayerRoad(std::make_pair(getName(), point), *this)) {
        return false;
    }
    // Add more checks if necessary (e.g., settlements should not be adjacent to each other)
    return true;
}


// Place a road between two points on the board
void Player::placeRoad(int startPoint, int endPoint, Board& board) {
        if (canPlaceRoad(startPoint, endPoint, board)) {
            addRoad(startPoint, endPoint, board); // Add road to player's roads
            board.placeRoad(startPoint, endPoint, *this); // Update the board with the road
            std::cout << getName() << " placed a road from " << startPoint << " to " << endPoint << std::endl;
        } else {
            std::cerr << getName() << " failed to place a road." << std::endl;
        }
    }

// Check if a road can be placed between two points
// bool Player::canPlaceRoad(int startPoint, int endPoint, const Board& board) const {
//     std::cout << "Checking road placement for " << getName() << " from " << startPoint << " to " << endPoint << std::endl;

//     // First, check if the player has settlements or cities at both start and end points
//     if (!hasSettlementOrCity(startPoint) || !hasSettlementOrCity(endPoint)) {
//         std::cout << "No settlement or city for " << getName() << " at start or end point." << std::endl;
//         return false;
//     }

//     // Check if there is already a road at the start or end point
//     if (board.isPlaceOccupied(startPoint) || board.isPlaceOccupied(endPoint)) {
//         std::cout << "Road already occupied at startPoint " << startPoint << " or endPoint " << endPoint << std::endl;
//         return false;
//     }

//     // For the first two roads, allow placement without additional checks
//     if (roads.size() < 2) {
//         return true;
//     }

//     // Additional checks for subsequent roads
//     auto startPair = std::make_pair(startPoint, endPoint);
//     auto endPair = std::make_pair(endPoint, startPoint);
//     if (roadConnections.find(startPair) == roadConnections.end() &&
//         roadConnections.find(endPair) == roadConnections.end()) {
//         std::cout << "No road connection found between " << startPoint << " and " << endPoint << std::endl;
//         return false;
//     }

//     // Check adjacency between the start and end points
//     if (!board.areAdjacent(std::make_pair(getName(), startPoint), std::make_pair(getName(), endPoint))) {
//         std::cout << "Points " << startPoint << " and " << endPoint << " are not adjacent" << std::endl;
//         return false;
//     }

//     // If all checks pass, road can be placed
//     return true;
// }

bool Player::canPlaceRoad(int startPoint, int endPoint, const Board& board) const {
    // Check if the player has a settlement or city at either startPoint or endPoint
    if (hasSettlementOrCity(startPoint) || hasSettlementOrCity(endPoint)) {
        return true;
    }

    // Check if the player has a road at either startPoint or endPoint
    if (hasRoadAt(startPoint) || hasRoadAt(endPoint)) {
        return true;
    }

    // Check if the points are adjacent and free of roads
    if (board.areAdjacent(std::make_pair(name, startPoint), std::make_pair(name, endPoint))) {
        return true;
    }

    // Otherwise, the road placement is invalid
    return false;
}




// Get the road connections owned by the player
const std::set<std::pair<int, int>>& Player::getRoadConnections() const {
    return roadConnections;
}

// Get the locations of the player's settlements
std::set<int> Player::getSettlementLocations() const {
    std::set<int> locations;
    for (const auto& settlement : settlements) {
        locations.insert(settlement.getPoint());
    }
    return locations;
}

// Roll the dice and print the result
void Player::rollDice() {
    int roll = std::rand() % 6 + 1 + std::rand() % 6 + 1; // Rolling two six-sided dice
    std::cout << name << " rolled: " << roll << std::endl;
    // Implement resource distribution logic in the Catan class
}

// End the player's turn
void Player::endTurn() {
    std::cout << name << " ends his turn." << std::endl;
}

// Trade resources with another player
void Player::trade(Player& other, const std::string& give, const std::string& receive, int giveAmount, int receiveAmount) {
    Resource giveResource = Resource::Wood; // Placeholder, convert string to Resource enum
    Resource receiveResource = Resource::Brick; // Placeholder, convert string to Resource enum

    if (resources[giveResource] >= giveAmount && other.resources[receiveResource] >= receiveAmount) {
        resources[giveResource] -= giveAmount;
        other.resources[receiveResource] -= receiveAmount;
        resources[receiveResource] += receiveAmount;
        other.resources[giveResource] += giveAmount;
        std::cout << name << " traded " << giveAmount << " " << give << " for " << receiveAmount << " " << receive << " with " << other.getName() << "." << std::endl;
    } else {
        std::cerr << "Trade failed due to insufficient resources." << std::endl;
    }
}

// Buy a development card and add it to the player's collection
void Player::buyDevelopmentCard() {
    // Placeholder for checking and removing resources
    if (resources[Resource::Sheep] >= 1 && resources[Resource::Wheat] >= 1 && resources[Resource::Ore] >= 1) {
        resources[Resource::Sheep] -= 1;
        resources[Resource::Wheat] -= 1;
        resources[Resource::Ore] -= 1;
        std::shared_ptr<DevelopmentCard> card = std::make_shared<VictoryPointCard>(); // Create a VictoryPointCard
        developmentCards.push_back(card);
        std::cout << name << " bought a development card." << std::endl;
    } else {
        std::cerr << "Cannot buy a development card due to insufficient resources." << std::endl;
    }
}

void Player::useDevelopmentCard(const std::string& cardName, Catan& game) {
    auto it = std::find_if(developmentCards.begin(), developmentCards.end(), [&](const std::shared_ptr<DevelopmentCard>& card) {
        return card->getName() == cardName && !card->isUsed();
    });

    if (it != developmentCards.end()) {
        (*it)->applyEffect(*this, game); // Pass both Player and Catan objects
        (*it)->setUsed(true); // Mark the card as used
    } else {
        throw std::invalid_argument("Invalid development card name or card already used.");
    }
}





// Print the player's current points
void Player::printPoints() const {
    std::cout << name << " has " << points << " points." << std::endl;
}

// Get the player's name
std::string Player::getName() const {
    return name;
}

// Get the player's total points
int Player::getPoints() const {
    return points;
}

// Get the amount of a specific resource owned by the player
int Player::getResource(Resource resource) const {
    auto it = resources.find(resource);
    if (it != resources.end()) {
        return it->second;
    }
    return 0;
}

// Add a specified amount of a resource to the player's inventory
void Player::addResource(Resource resource, int amount) {
    resources[resource] += amount;
}

// Remove a specified amount of a resource from the player's inventory
void Player::removeResource(Resource resource, int amount) {
    resources[resource] -= amount;
    if (resources[resource] < 0) {
        resources[resource] = 0; // Ensure it doesn't go below zero
    }
}

// Get a reference to the vector of roads owned by the player
const std::vector<Road>& Player::getRoads() const {
    return roads;
}

// Get a reference to the vector of settlements owned by the player
const std::vector<Settlement>& Player::getSettlements() const {
    return settlements;
}

// Add a settlement to the player's list of settlements
void Player::addSettlement(int point) {
    // Always allow placing the first two settlements without checking resources
    if (settlements.size() < 2 || 
        (resources[Resource::Brick] >= 1 && 
         resources[Resource::Wood] >= 1 && 
         resources[Resource::Wheat] >= 1 && 
         resources[Resource::Sheep] >= 1)) {

        settlements.emplace_back(name, point);
        
        // Deduct resources only if it's not the initial setup phase
        if (settlements.size() >= 2) {
            resources[Resource::Brick] -= 1;
            resources[Resource::Wood] -= 1;
            resources[Resource::Wheat] -= 1;
            resources[Resource::Sheep] -= 1;
        }

    } else {
        std::cerr << getName() << " cannot add settlement due to insufficient resources." << std::endl;
    }
}


// Check if the player has a settlement at a specified point
bool Player::hasSettlement(int point) const {
    for (const auto& settlement : settlements) {
        if (settlement.getPoint() == point) {
            return true;
        }
    }
    return false;
}

// Add a road between two points on the board
void Player::addRoad(int startPoint, int endPoint, Board& board) {
    // Always allow placing the first two roads without checking resources
    if (roads.size() < 2 || 
        (resources[Resource::Brick] >= 1 && 
         resources[Resource::Wood] >= 1)) {
        
        Tile& startTile = board.getTile(startPoint);
        Tile& endTile = board.getTile(endPoint);
        roads.emplace_back(*this, startTile, endTile);
        roadConnections.insert(std::make_pair(startPoint, endPoint));
        
        // Deduct resources only if it's not the initial setup phase
        if (roads.size() >= 2) {
            resources[Resource::Brick] -= 1;
            resources[Resource::Wood] -= 1;
        }

    } else {
        std::cerr << getName() << " cannot add road due to insufficient resources." << std::endl;
    }
}




// Check if the player has a road between two points
bool Player::hasRoad(int startPoint, int endPoint) const {
    return roadConnections.find({startPoint, endPoint}) != roadConnections.end();
}

// Check if the player has a road at a specified point
bool Player::hasRoadAt(int point) const {
    for (const auto& road : roads) {
        if (road.getStart().getPoints().find(point) != road.getStart().getPoints().end() ||
            road.getEnd().getPoints().find(point) != road.getEnd().getPoints().end()) {
            return true;
        }
    }
    return false;
}

void Player::addCity(int point, Board& board) {
    // Check if there is a settlement at the specified point owned by the player
    bool hasSettlement = false;
    for (auto& settlement : settlements) {
        if (settlement.getPoint() == point && settlement.getPlace() == this->name) {
            hasSettlement = true;
            break;
        }
    }
    if (!hasSettlement) {
        std::cerr << getName() << " cannot add city: no settlement at the specified point " << point << " or settlement does not belong to the player." << std::endl;
        return;
    }

    // Check if the player has sufficient resources to upgrade the settlement to a city
    if (resources[Resource::Wheat] >= 2 && resources[Resource::Ore] >= 3) {
        // Deduct resources
        resources[Resource::Wheat] -= 2;
        resources[Resource::Ore] -= 3;

        // Upgrade settlement to city
        for (auto& settlement : settlements) {
            if (settlement.getPoint() == point) {
                settlement.setIsCity(true);
                std::cout << getName() << " upgraded settlement at point " << point << " to a city." << std::endl;
                break;
            }
        }

        // Add a point to the player
        points += 1;

        // Update the board
        board.upgradeSettlementToCity(point, getName());

        std::cout << getName() << " added a city at point " << point << " successfully." << std::endl;
    } else {
        std::cerr << getName() << " cannot add city: insufficient resources ("
                  << resources[Resource::Wheat] << " Wheat, "
                  << resources[Resource::Ore] << " Ore, but 2 Wheat and 3 Ore required)." << std::endl;
    }
}


void Player::printPlayerInfo() const {
    std::cout << getName() << " has " << points << " points and resources: ";
    for (const auto& resource : resources) {
        std::cout << static_cast<int>(resource.first) << ": " << resource.second << " ";
    }
    std::cout << std::endl;
}

bool Player::hasSettlementOrCity(int point) const {
    for (const auto& settlement : settlements) {
        if (settlement.getPlaceNum() == point) {
            return true;
        }
    }
    return false;
}

void Player::addKnightCard() {
    knightCount++;
    checkLargestArmy();
}

void Player::checkLargestArmy() {
    static int maxKnightCount = 0;
    static Player* currentLargestArmyPlayer = nullptr;

    if (knightCount >= 3 && knightCount > maxKnightCount) {
        if (currentLargestArmyPlayer) {
            currentLargestArmyPlayer->largestArmy = false;
            currentLargestArmyPlayer->points -= 2;
        }
        largestArmy = true;
        points += 2;
        maxKnightCount = knightCount;
        currentLargestArmyPlayer = this;
        std::cout << name << " has the largest army and gains 2 points." << std::endl;
    }
}

bool Player::hasLargestArmy() const {
    return largestArmy;
}

void Player::addPoints(int points) {
    this->points += points;
}

} // namespace ariel

