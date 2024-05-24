//ID: 208018028, Mail: ronimordechai70@gmail.com
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
    if (board.placeSettlement(*this, places, placesNum)) {
        addSettlement(places, placesNum);
        std::cout << name << " placed a settlement." << std::endl;
        points += 1; // Each settlement is worth 1 point
    } else {
        std::cerr << name << " failed to place a settlement." << std::endl;
    }
}

void Player::placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board) {
    if (board.placeRoad(*this, places, placesNum)) {
        addRoad(places, placesNum);
        std::cout << name << " placed a road." << std::endl;
    } else {
        std::cerr << name << " failed to place a road." << std::endl;
    }
}

void Player::rollDice() {
    int roll = std::rand() % 6 + 1 + std::rand() % 6 + 1; // Rolling two six-sided dice
    std::cout << name << " rolled: " << roll << std::endl;
    // Implement resource distribution logic in the Catan class
}

void Player::endTurn() {
    std::cout << name << " ends their turn." << std::endl;
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
    (void)places; // Suppress unused parameter warning
    (void)placesNum; // Suppress unused parameter warning

    // Example with dummy Tile object (replace with actual logic)
    Tile dummyTile("dummy", 1);  // Replace with actual Tile object creation
    Settlement settlement(*this, dummyTile);
}

void Player::addRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum) {
     (void)places; // Suppress unused parameter warning
    (void)placesNum; // Suppress unused parameter warning

    // Example with dummy Tile objects (replace with actual logic)
    Tile dummyStartTile("start", 1);  // Replace with actual Tile object creation
    Tile dummyEndTile("end", 2);    // Replace with actual Tile object creation
    Road road(*this, dummyStartTile, dummyEndTile);
}

} // namespace ariel
