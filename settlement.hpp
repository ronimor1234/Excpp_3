//ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include <string>

namespace ariel {

    class Settlement {
    private:
        std::string place;
        int placeNum;
        int point;
        bool isCity;
        std::string owner;

    public:
        Settlement(const std::string& place, int placeNum);
        const std::string& getPlace() const;
        int getPlaceNum() const;
        int getPoint() const;
        bool getIsCity() const;
        void setIsCity(bool isCity);
        // bool isCity() const;
        const std::string& getOwner() const;
        void upgradeToCity();
    };

} // namespace ariel

#endif // SETTLEMENT_HPP
