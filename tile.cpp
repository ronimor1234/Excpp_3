//ID: 208018028, Mail: ronimordechai70@gmail.com
#include "tile.hpp"

namespace ariel {

    Tile::Tile(const std::string& type, int number) : type(type), number(number) {}

    std::string Tile::getType() const {
        return type;
    }

    int Tile::getNumber() const {
        return number;
    }

    Resource Tile::produceResource() const {
        // Default implementation returns None
        return Resource::None;
    }

    ResourceTile::ResourceTile(const std::string& type, int number, Resource resource)
        : Tile(type, number), resource(resource) {}

    Resource ResourceTile::produceResource() const {
        return resource;
    }

    DesertTile::DesertTile(const std::string& type, int number)
        : Tile(type, number) {}

    Resource DesertTile::produceResource() const {
        // Deserts produce no resources
        return Resource::None;
    }

} // namespace ariel
