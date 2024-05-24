//ID: 208018028, Mail: ronimordechai70@gmail.com
#include "construction.hpp"

namespace ariel {

    Construction::Construction(Player& owner, Tile& location, int points)
        : owner(owner), location(location), points(points) {}

    int Construction::getPoints() const {
        return points;
    }

} // namespace ariel
