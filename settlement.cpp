//ID: 208018028, Mail: ronimordechai70@gmail.com

#include "settlement.hpp"

namespace ariel {

    Settlement::Settlement(const std::string& place, int placeNum)
        : place(place), placeNum(placeNum), point(placeNum), isCity(false), owner("") {}

    const std::string& Settlement::getPlace() const {
        return place;
    }

    int Settlement::getPlaceNum() const {
        return placeNum;
    }

    int Settlement::getPoint() const {
        return point;
    }

    bool Settlement::getIsCity() const {
        return isCity;
    }

    void Settlement::setIsCity(bool isCity) {
        this->isCity = isCity;
    }

    // bool Settlement::isCity() const {
    //     return isCity;
    // }

    const std::string& Settlement::getOwner() const {
        return owner;
    }

    void Settlement::upgradeToCity() {
        isCity = true;
    }

} // namespace ariel
