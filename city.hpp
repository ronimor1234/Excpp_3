//ID: 208018028, Mail: ronimordechai70@gmail.com

#ifndef CITY_HPP
#define CITY_HPP

#include "player.hpp" // Include the full definition of Player
#include <string>

namespace ariel {

    class Tile; // Forward declaration

    class City {
    private:
        Player& owner;
        Tile& location;
        int point;
        int placeNum;

    public:
        City(Player& owner, Tile& location);  // Constructor declaration
        bool isSettlement() const;  // Function declaration
        bool isCity() const;  // Function declaration
        int getPoint() const { return point; }
        std::string getOwner() const;
        int getPlaceNum() const; // Getter for placeNum
    };

} // namespace ariel

#endif // CITY_HPP
