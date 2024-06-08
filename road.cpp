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

//     bool Road::isConnectedTo(const std::string& place, int placeNum) const {
//     // Implement your logic to check if this road is connected to the specified place
//     // Example implementation:
//     // Assuming 'connectedPlaces' is a member variable of type std::vector<std::pair<std::string, int>>
//     // for (const auto& connectedPlace : connectedPlaces) {
//     //     if (connectedPlace.first == place && connectedPlace.second == placeNum) {
//     //         return true;
//     //     }
//     // }
//     return false;
// }

} // namespace ariel