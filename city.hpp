//ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef CITY_HPP
#define CITY_HPP

#include "construction.hpp"
#include "player.hpp"
#include "tile.hpp"

namespace ariel {

    class City : public Construction {
    public:
        City(Player& owner, Tile& location);  // Constructor declaration

        bool isSettlement() const override;  // Override functions
        bool isCity() const override;

    private:
        Player& owner;
        Tile& location;
    };

} // namespace ariel

#endif // CITY_HPP
