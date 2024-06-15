// ID: 208018028, Mail: ronimordechai70@gmail.com

#include "tile.hpp"

namespace ariel {

    // Tile class
    Tile::Tile(const std::string& type, int number)
        : type(type), number(number) {
        // Constructor to initialize type and number of the tile
    }

    std::string Tile::getType() const {
        return type;
    }
    // Getter for the type of the tile

    int Tile::getNumber() const {
        return number;
    }
    // Getter for the number associated with the tile

    void Tile::addPoint(int point) {
        points.insert(point);
    }
    // Method to add a point to the tile

    bool Tile::hasPoint(int point) const {
        return points.count(point) > 0;
    }
    // Method to check if the tile has a specific point

    std::unordered_set<int> Tile::getPoints() const {
        return points;
    }
    // Getter for all points associated with the tile

    Resource Tile::produceResource() const {
        return Resource::Brick;  // Default implementation for base class
    }
    // Virtual function to produce a resource (to be overridden by derived classes)

    void Tile::addFixedPoints(const std::vector<int>& fixedPoints) {
        for (int point : fixedPoints) {
            addPoint(point);
        }
    }
    // Method to add fixed points based on fixedTiles

    // ResourceTile class
    ResourceTile::ResourceTile(const std::string& type, int number, Resource resource)
        : Tile(type, number), resource(resource) {
        // Constructor to initialize type, number, and resource of the tile
    }

    Resource ResourceTile::produceResource() const {
        return resource;
    }
    // Override the virtual function to produce the specific resource

    Resource ResourceTile::getResource() const {
        return resource;
    }
    // Getter for the resource associated with this tile

    // DesertTile class
    DesertTile::DesertTile(const std::string& type, int number)
        : Tile(type, number) {
        // Constructor to initialize type and number of the desert tile
    }

    Resource DesertTile::produceResource() const {
        return Resource::Brick;
    }
    // Override the virtual function to indicate that no resource is produced

} // namespace ariel
