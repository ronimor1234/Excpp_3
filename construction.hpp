//ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef CONSTRUCTION_HPP
#define CONSTRUCTION_HPP

namespace ariel {
    class Player;
    class Tile;

    class Construction {
    public:
        Construction(Player& owner, Tile& location, int points);
        virtual ~Construction() = default;

        virtual int getPoints() const;
        virtual bool isSettlement() const = 0;
        virtual bool isCity() const = 0;

    protected:
        Player& owner;
        Tile& location;
        int points;
    };

} // namespace ariel

#endif // CONSTRUCTION_HPP
