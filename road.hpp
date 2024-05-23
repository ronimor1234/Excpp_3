//ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef ROAD_HPP
#define ROAD_HPP

#include "player.hpp"
#include "tile.hpp"
#include "board.hpp"

namespace ariel{
    class Player;  // Forward declaration
class Road {
private:
    Player& owner;
    Tile& start;
    Tile& end;

public:
     Road(Player& owner, Tile& start, Tile& end)
            : owner(owner), start(start), end(end) {}

    // Getters
    Player& getOwner() const{ return owner; }
    Tile& getStart() const;
    Tile& getEnd() const;
};
} // namespace ariel
#endif // ROAD_HPP
