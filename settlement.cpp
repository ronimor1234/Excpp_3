//ID: 208018028, Mail: ronimordechai70@gmail.com
#include "settlement.hpp"

namespace ariel{

// Constructor
Settlement::Settlement(Player& owner, Tile& location) : owner(owner), location(location) {
    location.addSettlement(this);  // Adds this settlement to the tile's list of settlements
}

// Getter for the owner
Player& Settlement::getOwner() const {
    return owner;
}

// Getter for the location
Tile& Settlement::getLocation() const {
    return location;
}

}