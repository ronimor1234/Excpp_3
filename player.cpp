// //ID: 208018028, Mail: ronimordechai70@gmail.com
#include "player.hpp"
#include "board.hpp"
#include "settlement.hpp"
#include "road.hpp"
#include <iostream>
#include <stdexcept>

namespace ariel {

Player::Player(const std::string& name) : name(name), points(0) {
    // Initialize all resources to 0
    resources[Resource::Wood] = 0;
    resources[Resource::Brick] = 0;
    resources[Resource::Wheat] = 0;
    resources[Resource::Ore] = 0;
    resources[Resource::Sheep] = 0;
}

void Player::placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
    try {
        if (canPlaceSettlement(places, placesNum, board)) {
            // Place settlement
            addSettlement(places, placesNum);
            std::cout << name << " placed a settlement:" << std::endl;
            for (size_t i = 0; i < places.size(); ++i) {
                std::cout << "Place: " << places[i] << ", Number: " << placesNum[i] << std::endl;
            }
            points += 1; // Each settlement is worth 1 point
        } else {
            throw std::runtime_error("Failed to place settlement. Location already occupied or not adjacent to a road.");
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

bool Player::canPlaceSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, const Board& board) const {
    // Check if all places are available and adjacent to player's roads
    for (size_t i = 0; i < places.size(); ++i) {
        auto key = std::make_pair(places[i], placesNum[i]);
        
        // Check if the place is already occupied
        if (board.isPlaceOccupied(places[i], placesNum[i])) {
            return false;
        }

        // Check if the place is adjacent to a road of the player
        bool connected = false;
        for (const auto& connection : roadConnections) {
            if (board.areAdjacent(key, connection)) {
                connected = true;
                break;
            }
        }
        if (!connected) {
            return false;
        }
    }
    return true;
}


void Player::placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
    if (canPlaceRoad(places, placesNum, board)) {
        if (board.placeRoad(*this, places, placesNum)) {
            addRoad(places, placesNum);
            std::cout << name << " placed a road:" << std::endl;
            std::cout << "Places: ";
            for (const auto& place : places) {
                std::cout << place << " ";
            }
            std::cout << std::endl;

            std::cout << "Numbers: ";
            for (const auto& num : placesNum) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        } else {
            std::cerr << name << " failed to place a road." << std::endl;
        }
    } else {
        std::cerr << name << " cannot place a road at the specified location." << std::endl;
    }
}

bool Player::canPlaceRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, const Board& board) const {
    if (places.size() != placesNum.size()) {
        return false; // Should have the same number of places and place numbers
    }

    for (size_t i = 0; i < places.size(); ++i) {
        auto key = std::make_pair(places[i], placesNum[i]);
        
        // Check if the place is occupied by another player
        if (!board.isPlaceOccupied(places[i], placesNum[i])) {
            return false;
        }

        // Check if the player has a road connection to this place
        if (roadConnections.find(key) == roadConnections.end()) {
            return false;
        }

        // Check if the road can be placed adjacent to another road
        bool connected = false;
        for (const auto& connection : roadConnections) {
            if (board.areAdjacent(key, connection)) {
                connected = true;
                break;
            }
        }
        if (!connected) {
            return false;
        }
    }

    return true;
}


const std::set<std::pair<std::string, int>>& Player::getRoadConnections() const {
    return roadConnections;
}

void Player::rollDice() {
    int roll = std::rand() % 6 + 1 + std::rand() % 6 + 1; // Rolling two six-sided dice
    std::cout << name << " rolled: " << roll << std::endl;
    // Implement resource distribution logic in the Catan class
}

void Player::endTurn() {
    std::cout << name << " ends his turn." << std::endl;
}

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

void Player::buyDevelopmentCard(std::shared_ptr<DevelopmentCard> card) {
    // Placeholder for buying development card logic
    // DevelopmentCard card; // Assume a method to generate a new card
    developmentCards.push_back(card);
    std::cout << name << " bought a development card." << std::endl;
}

void Player::printPoints() const {
    std::cout << name << " has " << points << " points." << std::endl;
}

std::string Player::getName() const {
    return name;
}

int Player::getPoints() const {
    return points;
}

int Player::getResource(Resource resource) const {
    auto it = resources.find(resource);
    if (it != resources.end()) {
        return it->second;
    }
    return 0;
}

void Player::addResource(Resource resource, int amount) {
    resources[resource] += amount;
}

void Player::removeResource(Resource resource, int amount) {
    if (resources[resource] >= amount) {
        resources[resource] -= amount;
    } else {
        throw std::runtime_error("Not enough resources to remove");
    }
}

void Player::addSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum) {
    for (size_t i = 0; i < places.size(); ++i) {
        Settlement settlement(places[i], placesNum[i]);
        settlements.push_back(settlement);
    }
}

void Player::addRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum) {
    for (size_t i = 0; i < places.size(); ++i) {
        roadConnections.insert(std::make_pair(places[i], placesNum[i]));
    }
}

std::set<std::pair<std::string, int>> Player::getSettlementLocations() const {
    std::set<std::pair<std::string, int>> locations;
    for (const auto& settlement : settlements) {
        locations.insert(std::make_pair(settlement.getPlace(), settlement.getPlaceNum()));
    }
    return locations;
}

std::set<std::pair<std::string, int>> Player::getSettlements() const {
    return getSettlementLocations();
}

} // namespace ariel


