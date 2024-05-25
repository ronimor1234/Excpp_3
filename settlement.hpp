//ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include "construction.hpp"
#include "player.hpp"
#include "tile.hpp"

namespace ariel {

    class Settlement : public Construction {
    friend class Board; // Declare Board as a friend class

    public:
        Settlement(Player& owner, Tile& location);  // Constructor declaration

        bool isSettlement() const override;  // Override functions
        bool isCity() const override;

    private:
        Player& owner;
        Tile& location;
    };

} // namespace ariel

#endif // SETTLEMENT_HPP
