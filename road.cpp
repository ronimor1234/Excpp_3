//ID: 208018028, Mail: ronimordechai70@gmail.com
#include "road.hpp"
#include "player.hpp"
#include "tile.hpp"

namespace ariel{

    Road::Road(const Player& owner, Tile& start, Tile& end) 
        : owner(owner), start(start), end(end) {}

    Tile& Road::getStart() const {
        return start;
    }

    Tile& Road::getEnd() const {
        return end;
    }

} // namespace ariel