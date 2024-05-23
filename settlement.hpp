//ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include "player.hpp"
#include "tile.hpp"

namespace ariel{
    class Player;
class Settlement {
private:
    Player& owner;    // Reference to the player who owns this settlement
    Tile& location;   // Reference to the tile where this settlement is placed

public:
    Settlement(Player& owner, Tile& location); // Constructor

    // Getters
    Player& getOwner() const;   // Returns the player who owns this settlement
    Tile& getLocation() const;  // Returns the location of this settlement
};
} // namespace ariel
#endif // SETTLEMENT_HPP
