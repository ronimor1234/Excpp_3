//ID: 208018028, Mail: ronimordechai70@gmail.com

#include "settlement.hpp"
namespace ariel{

Settlement::Settlement(const std::string& place, int placeNum) : place(place), placeNum(placeNum) {}

const std::string& Settlement::getPlace() const {
    return place;
}

int Settlement::getPlaceNum() const {
    return placeNum;
}

bool Settlement::getIsCity() const {
        return isCity;
}

void Settlement::setIsCity(bool isCity) {
        this->isCity = isCity;
}

// bool Settlement::isConnectedTo(const std::string& place, int placeNum) const {
//         for (const auto& connected : connectedPlaces) {  // Use a different name for the loop variable
//             if (connected.first == place && connected.second == placeNum) {
//                 return true;
//             }
//         }
//         return false;
//     }

}