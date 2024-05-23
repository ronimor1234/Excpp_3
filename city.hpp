//ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef CITY_HPP
#define CITY_HPP

#include "construction.hpp"

namespace ariel{
class City : public Construction {
public:
    City(Player& owner, Tile& location);

    bool isSettlement() const override;
    bool isCity() const override;
};
} //namespace ariel
#endif // CITY_HPP
