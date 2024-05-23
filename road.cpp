//ID: 208018028, Mail: ronimordechai70@gmail.com
#include "road.hpp"

namespace ariel{
// Road::Road(Player& owner, Tile& start, Tile& end) : owner(owner), start(start), end(end) {
//     start.addRoad(this);
//     end.addRoad(this);
// }

// Player& Road::getOwner() const {
//     return owner;
// }

Tile& Road::getStart() const {
    return start;
}

Tile& Road::getEnd() const {
    return end;
}

} // namespace ariel