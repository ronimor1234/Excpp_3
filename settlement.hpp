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
        
        public:
        Settlement(const std::string& place, int placeNum);
        // bool isConnectedTo(const std::string& place, int placeNum) const;
        const std::string& getPlace() const;
        int getPlaceNum() const;
        int getPoint() const { return point; }
        bool getIsCity() const;
        void setIsCity(bool isCity);
    };
} //namespace ariel
#endif
