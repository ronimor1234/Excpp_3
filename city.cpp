//ID: 208018028, Mail: ronimordechai70@gmail.com
#include "city.hpp"

namespace ariel{
City::City(Player& owner, Tile& location) : Construction(owner, location, 2) {}

bool City::isSettlement() const {
    return false;
}

bool City::isCity() const {
    return true;
}
} // namespace ariel