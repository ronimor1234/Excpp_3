//ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef ROAD_HPP
#define ROAD_HPP

#include <string>

namespace ariel {
    class Player; // Forward declaration
    class Tile;   // Forward declaration

    class Road {
    private:
        const Player& owner;
        Tile& start;
        Tile& end;

    public:
        Road(const Player& owner, Tile& start, Tile& end);
        // bool isConnectedTo(const std::string& place, int placeNum) const;
        // Getters
        
        Tile& getStart() const;
        Tile& getEnd() const;
    };

} // namespace ariel

#endif // ROAD_HPP
