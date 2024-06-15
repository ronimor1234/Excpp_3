// ID: 208018028, Mail: ronimordechai70@gmail.com
#include "road.hpp"
#include "player.hpp"
#include "tile.hpp"

namespace ariel {

    // Constructor
    Road::Road(const Player& owner, Tile& start, Tile& end)
        : owner(owner), start(start), end(end) {
        // Initialize the road with the given owner and start/end tiles
    }

    // Getter for the starting tile of the road
    Tile& Road::getStart() const {
        return start;
    }

    // Getter for the ending tile of the road
    Tile& Road::getEnd() const {
        return end;
    }

} // namespace ariel
