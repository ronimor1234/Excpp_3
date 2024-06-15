// ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include <string>

namespace ariel {

    class Settlement {
    private:
        std::string place;   // Name of the place where the settlement is located
        int placeNum;        // Numeric identifier of the settlement's location
        int point;           // Point value associated with the settlement
        bool isCity;         // Indicates whether the settlement has been upgraded to a city
        std::string owner;   // Name of the player who owns the settlement

    public:
        Settlement(const std::string& place, int placeNum);
        // Constructor to initialize a settlement with a place name and place number
        
        const std::string& getPlace() const;
        // Getter for the name of the place
        
        int getPlaceNum() const;
        // Getter for the place number
        
        int getPoint() const;
        // Getter for the point value of the settlement
        
        bool getIsCity() const;
        // Getter to check if the settlement is a city
        
        void setIsCity(bool isCity);
        // Setter to mark the settlement as a city
        
        const std::string& getOwner() const;
        // Getter for the owner of the settlement
        
        void upgradeToCity();
        // Method to upgrade the settlement to a city
    };

} // namespace ariel

#endif // SETTLEMENT_HPP
