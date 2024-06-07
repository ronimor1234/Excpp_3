// //ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include "resource.hpp"

namespace ariel {

    class Tile {
    private:
        std::string type;
        int number;

    public:
        Tile(const std::string& type, int number);
        std::string getType() const;
        int getNumber() const;
        void setNumber(int num) { number = num; }
        virtual Resource produceResource() const;
    };

    class ResourceTile : public Tile {
    private:
        Resource resource;

    public:
        ResourceTile(const std::string& type, int number, Resource resource);
        Resource produceResource() const override;
    };

    class DesertTile : public Tile {
    public:
        DesertTile(const std::string& type, int number);
        Resource produceResource() const override;
    };

} // namespace ariel

#endif // TILE_HPP

