//ID: 208018028, Mail: ronimordechai70@gmail.com
#include "settlement.hpp"

namespace ariel {

    Settlement::Settlement(Player& owner, Tile& location)
        : Construction(owner, location, 1), owner(owner), location(location) {}

    bool Settlement::isSettlement() const {
        return true;
    }

    bool Settlement::isCity() const {
        return false;
    }

} // namespace ariel
