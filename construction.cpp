//ID: 208018028, Mail: ronimordechai70@gmail.com
#include "construction.hpp"

namespace ariel{
Construction::Construction(const std::vector<std::string>& places, const std::vector<int>& placesNum)
    : places(places), placesNum(placesNum) {}

Settlement::Settlement(const std::vector<std::string>& places, const std::vector<int>& placesNum)
    : Construction(places, placesNum) {}

int Settlement::getPoints() const {
    return 1;
}

City::City(const std::vector<std::string>& places, const std::vector<int>& placesNum)
    : Construction(places, placesNum) {}

int City::getPoints() const {
    return 2;
}

} // namespace ariel