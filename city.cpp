//ID: 208018028, Mail: ronimordechai70@gmail.com
#include "city.hpp"
#include "player.hpp"
#include "tile.hpp"

namespace ariel {

    City::City(Player& owner, Tile& location)
        : owner(owner), location(location) {
    }

    bool City::isSettlement() const {
        return false; 
    }

    bool City::isCity() const {
        return true; 
    }

    std::string City::getOwner() const {
        return owner.getName();
    }

} // namespace ariel
