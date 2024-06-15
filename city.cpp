// ID: 208018028, Mail: ronimordechai70@gmail.com
#include "city.hpp"
#include "player.hpp"
#include "tile.hpp"

namespace ariel {

    // Constructor initializes the city with an owner and location
    City::City(Player& owner, Tile& location)
        : owner(owner), location(location) {
    }

    // Returns false because a city is not a settlement
    bool City::isSettlement() const {
        return false; 
    }

    // Returns true because it is a city
    bool City::isCity() const {
        return true; 
    }

    // Returns the name of the owner of the city
    std::string City::getOwner() const {
        return owner.getName();
    }

    // Returns the place number of the city
    int City::getPlaceNum() const {
        return placeNum; // It seems placeNum is not defined in the provided code
    }

} // namespace ariel
