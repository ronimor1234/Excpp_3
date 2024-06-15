// ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef ROAD_HPP
#define ROAD_HPP

#include <string>

namespace ariel {
    // Forward declarations
    class Player;
    class Tile;

    class Road {
    private:
        const Player& owner; // Reference to the owner player
        Tile& start;         // Reference to the starting tile of the road
        Tile& end;           // Reference to the ending tile of the road

    public:
        // Constructor
        Road(const Player& owner, Tile& start, Tile& end);

        // Getters
        Tile& getStart() const; // Get the starting tile of the road
        Tile& getEnd() const;   // Get the ending tile of the road
    };

} // namespace ariel

#endif // ROAD_HPP
