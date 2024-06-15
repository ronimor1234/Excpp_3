// ID: 208018028, Mail: ronimordechai70@gmail.com

#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include <string>
#include <unordered_set>
#include "resource.hpp" // Include the Resource enum

namespace ariel {

    class Tile {
    private:
        std::string type;                      // Type of the tile
        int number;                            // Number associated with the tile
        std::unordered_set<int> points;        // Set to store points associated with this tile

    public:
        Tile(const std::string& type, int number);
        // Constructor to initialize type and number of the tile

        std::string getType() const;
        // Getter for the type of the tile

        int getNumber() const;
        // Getter for the number associated with the tile

        void addPoint(int point);
        // Method to add a point to the tile

        bool hasPoint(int point) const;
        // Method to check if the tile has a specific point

        std::unordered_set<int> getPoints() const;
        // Getter for all points associated with the tile

        void addFixedPoints(const std::vector<int>& fixedPoints);
        // Method to add fixed points based on fixedTiles

        virtual Resource produceResource() const;
        // Virtual function to produce a resource (to be overridden by derived classes)
    };

    class ResourceTile : public Tile {
    private:
        Resource resource; // Resource associated with this tile

    public:
        ResourceTile(const std::string& type, int number, Resource resource);
        // Constructor to initialize type, number, and resource of the tile

        Resource produceResource() const override;
        // Override the virtual function to produce the specific resource

        Resource getResource() const;
        // Getter for the resource associated with this tile
    };

    class DesertTile : public Tile {
    public:
        DesertTile(const std::string& type, int number);
        // Constructor to initialize type and number of the desert tile

        Resource produceResource() const override;
        // Override the virtual function to indicate that no resource is produced
    };

} // namespace ariel

#endif // TILE_HPP
