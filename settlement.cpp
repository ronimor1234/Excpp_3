//ID: 208018028, Mail: ronimordechai70@gmail.com

#include "settlement.hpp"
using namespace ariel;

Settlement::Settlement(const std::string& place, int placeNum) : place(place), placeNum(placeNum) {}

const std::string& Settlement::getPlace() const {
    return place;
}

int Settlement::getPlaceNum() const {
    return placeNum;
}

