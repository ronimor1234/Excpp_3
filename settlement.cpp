// ID: 208018028, Mail: ronimordechai70@gmail.com

#include "settlement.hpp"

namespace ariel {

    Settlement::Settlement(const std::string& place, int placeNum)
        : place(place), placeNum(placeNum), point(placeNum), isCity(false), owner("") {
        // Constructor initializes the settlement with provided place name and place number
        // The point is set to the same value as the placeNum initially
        // isCity is initialized to false, indicating it's a settlement, not a city
        // The owner is initialized to an empty string
    }

    const std::string& Settlement::getPlace() const {
        return place;
        // Getter for the name of the place where the settlement is located
    }

    int Settlement::getPlaceNum() const {
        return placeNum;
        // Getter for the numeric identifier of the settlement's location
    }

    int Settlement::getPoint() const {
        return point;
        // Getter for the point value associated with the settlement
    }

    bool Settlement::getIsCity() const {
        return isCity;
        // Getter to check if the settlement has been upgraded to a city
    }

    void Settlement::setIsCity(bool isCity) {
        this->isCity = isCity;
        // Setter to mark the settlement as a city or revert it to a settlement
    }

    const std::string& Settlement::getOwner() const {
        return owner;
        // Getter for the name of the player who owns the settlement
    }

    void Settlement::upgradeToCity() {
        isCity = true;
        // Method to upgrade the settlement to a city
    }

} // namespace ariel
