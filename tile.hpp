// ID: 208018028, Mail: ronimordechai70@gmail.com

#ifndef TILE_HPP
#define TILE_HPP
#include <vector>
#include <string>
#include <unordered_set>
#include "resource.hpp"

namespace ariel {

    class Tile {
    private:
        std::string type;
        int number;
        std::unordered_set<int> points;  // Set to store points associated with this tile

    public:
        Tile(const std::string& type, int number);
        std::string getType() const;
        int getNumber() const;
        void addPoint(int point);
        bool hasPoint(int point) const;
        std::unordered_set<int> getPoints() const;
        void addFixedPoints(const std::vector<int>& fixedPoints);  // Add fixed points based on fixedTiles
        virtual Resource produceResource() const;  // Virtual function
    };

    class ResourceTile : public Tile {
    private:
        Resource resource;

    public:
        ResourceTile(const std::string& type, int number, Resource resource);
        Resource produceResource() const override;  // Override the virtual function
        Resource getResource() const;
    };

    class DesertTile : public Tile {
    public:
        DesertTile(const std::string& type, int number);
        Resource produceResource() const override;  // Override the virtual function
    };

} // namespace ariel

#endif // TILE_HPP
