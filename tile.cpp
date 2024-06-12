// // //ID: 208018028, Mail: ronimordechai70@gmail.com
// #include "tile.hpp"
// #include "resource.hpp"


// namespace ariel {

//     Tile::Tile(const std::string& type, int number) : type(type), number(number) {}

//     std::string Tile::getType() const {
//         return type;
//     }

//     int Tile::getNumber() const {
//         return number;
//     }

//     Resource Tile::produceResource() const {
//         // Default implementation returns None
//         return Resource::None;
//     }

//     ResourceTile::ResourceTile(const std::string& type, int number, Resource resource)
//         : Tile(type, number), resource(resource) {}

//     Resource ResourceTile::produceResource() const {
//         return resource;
//     }

//     DesertTile::DesertTile(const std::string& type, int number)
//         : Tile(type, number) {}

//     Resource DesertTile::produceResource() const {
//         // Deserts produce no resources
//         return Resource::None;
//     }

// } // namespace ariel

#include "tile.hpp"

namespace ariel {

    // Tile class
    Tile::Tile(const std::string& type, int number)
        : type(type), number(number) {
    }

    std::string Tile::getType() const {
        return type;
    }

    int Tile::getNumber() const {
        return number;
    }

    void Tile::addPoint(int point) {
        points.insert(point);
    }

    bool Tile::hasPoint(int point) const {
        return points.count(point) > 0;
    }

    std::unordered_set<int> Tile::getPoints() const {
        return points;
    }

    Resource Tile::produceResource() const {
        return Resource::Brick;  // Default implementation for base class
    }

    void Tile::addFixedPoints(const std::vector<int>& fixedPoints) {
        for (int point : fixedPoints) {
            addPoint(point);
        }
    }
    // ResourceTile class
    ResourceTile::ResourceTile(const std::string& type, int number, Resource resource)
        : Tile(type, number), resource(resource) {
    }

    Resource ResourceTile::produceResource() const {
        return resource;
    }

    Resource ResourceTile::getResource() const {
        return resource;
    }

    // DesertTile class
    DesertTile::DesertTile(const std::string& type, int number)
        : Tile(type, number) {
    }

    Resource DesertTile::produceResource() const {
        return Resource::Brick;
    }

} // namespace ariel
