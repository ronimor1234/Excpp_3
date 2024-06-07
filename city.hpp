//ID: 208018028, Mail: ronimordechai70@gmail.com

#ifndef CITY_HPP
#define CITY_HPP


namespace ariel {

    class Player; // Forward declaration

    class Tile; // Forward declaration

    class City {
    private:
        Player& owner;
        Tile& location;

    public:
        City(Player& owner, Tile& location);  // Constructor declaration
        bool isSettlement() const;  // Function declaration
        bool isCity() const;  // Function declaration
    };

} // namespace ariel

#endif // CITY_HPP
