// // //ID: 208018028, Mail: ronimordechai70@gmail.com
// #include "board.hpp"
// #include "tile.hpp"
// #include <iostream>
// #include <algorithm> // For std::shuffle
// #include <random>    // For std::default_random_engine and std::random_device
// #include <unordered_set>

// namespace ariel {

//     Board::Board() {
//         initializeBoard();
//     }

//     void Board::initializeBoard() {
//         // Clear the tiles vector before adding new tiles
//         tiles.clear();
//         tileMap.clear();

//         // Define the fixed positions and numbers for the tiles according to Catan rules
//         std::vector<std::pair<std::string, int>> fixedTiles = {
//             {"Forest", 5}, {"Hills", 2}, {"Agricultural Land", 6}, {"Pasture Land", 3}, {"Forest", 8},
//             {"Mountains", 10}, {"Agricultural Land", 9}, {"Forest", 12}, {"Pasture Land", 11}, {"Forest", 4},
//             {"Desert", 7}, {"Mountains", 8}, {"Agricultural Land", 3}, {"Pasture Land", 4}, {"Mountains", 5},
//             {"Hills", 6}, {"Pasture Land", 9}, {"Agricultural Land", 10}, {"Forest", 11}
//         };

//         for (const auto& tile : fixedTiles) {
//             if (tile.first == "Desert") {
//                 tiles.push_back(Tile(tile.first, tile.second)); // Use Tile for Desert
//             } else if (tile.first == "Forest") {
//                 tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Wood));
//             } else if (tile.first == "Hills") {
//                 tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Brick));
//             } else if (tile.first == "Agricultural Land") {
//                 tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Wheat));
//             } else if (tile.first == "Mountains") {
//                 tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Ore));
//             } else if (tile.first == "Pasture Land") {
//                 tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Sheep));
//             }

//             if (tile.first != "Desert") {
//                 tileMap[tile.second] = &tiles.back(); // Map the number to the tile
//             }
//         }
//     }

//     bool Board::placeSettlement(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum) {
//         for (size_t i = 0; i < places.size(); ++i) {
//             auto key = std::make_pair(places[i], placesNum[i]);
//             // Check if the place is occupied or within two edges of another settlement
//             for (const auto& entry : occupiedPlaces) {
//                 if (entry.second != player.getName() && isWithinTwoEdges(key, entry.first)) {
//                     return false; // Place is within two edges of another settlement
//                 }
//             }
//         }
//         for (size_t i = 0; i < places.size(); ++i) {
//             auto key = std::make_pair(places[i], placesNum[i]);
//             occupiedPlaces[key] = player.getName();
//         }
//         return true;
//     }

//     bool Board::placeRoad(const Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum) {
//         const auto& roadConnections = player.getRoadConnections();

//         for (size_t i = 0; i < places.size(); ++i) {
//             auto key = std::make_pair(places[i], placesNum[i]);
//             if (occupiedPlaces.find(key) != occupiedPlaces.end()) {
//                 if (occupiedPlaces[key] != player.getName()) {
//                     return false; // Place is already occupied by another player
//                 }
//             } else {
//                 bool connected = false;
//                 // Check if the new road is connected to any of the player's existing roads or settlements
//                 for (const auto& connection : roadConnections) {
//                     if (areAdjacent(key, connection)) {
//                         connected = true;
//                         break;
//                     }
//                 }
//                 if (!connected) {
//                     // Optionally, check if the road is connected to any of the player's settlements
//                     for (const auto& settlement : player.getSettlements()) {
//                         if (areAdjacent(key, settlement)) {
//                             connected = true;
//                             break;
//                         }
//                     }
//                 }
//                 if (!connected) {
//                     return false; // New road is not connected to existing roads or settlements
//                 }
//             }
//         }

//         for (size_t i = 0; i < places.size(); ++i) {
//             auto key = std::make_pair(places[i], placesNum[i]);
//             occupiedPlaces[key] = player.getName();
//         }

//         return true;
//     }

//     bool Board::isPlaceOccupied(const std::string& place, int placeNum) const {
//         auto key = std::make_pair(place, placeNum);
//         return occupiedPlaces.find(key) != occupiedPlaces.end();
//     }

//     bool Board::areAdjacent(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const {
//     // Implement logic to check if places a and b are adjacent
//     // This logic is simplified and might need to be adapted based on the board structure
    
//     // Check adjacency based on the standard Catan board layout
//     if (a.first == b.first) {
//         // Same column, check if the difference in numbers is 1
//         return abs(a.second - b.second) == 1;
//     } else if (a.second == b.second) {
//         // Same number, check if they are adjacent columns
//         if (a.first == "sea" || b.first == "sea") {
//             // Check for the sea adjacency (sea has no numbers)
//             return true;
//         } else {
//             // Check if the difference in columns is 1 or the wrapping around the board
//             return abs(columnIndex(a.first) - columnIndex(b.first)) == 1;
//         }
//     } else {
//         // Check diagonal adjacency
//         if (a.first == "sea" || b.first == "sea") {
//             // Diagonal adjacency involving sea
//             return false;
//         } else {
//             int diffCol = abs(columnIndex(a.first) - columnIndex(b.first));
//             int diffNum = abs(a.second - b.second);
            
//             // Ensure the diagonal condition is met
//             return (diffCol == 1 && diffNum == 1);
//         }
//     }
// }

//     bool Board::isWithinTwoEdges(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const {
//     // Implement logic to check if places a and b are within two edges of each other
//     // This logic is simplified and might need to be adapted based on the board structure
    
//     // Check if the difference in column and number is within two edges
//     int diffCol = abs(columnIndex(a.first) - columnIndex(b.first));
//     int diffNum = abs(a.second - b.second);
    
//     return (diffCol <= 2 && diffNum <= 2);
// }

// int Board::columnIndex(const std::string& column) const {
//     // Implement logic to convert column name to index
//     // Example logic for standard Catan board layout
//     if (column == "sea") return -1;
//     else if (column == "Forest") return 0;
//     else if (column == "Hills") return 1;
//     else if (column == "Agricultural Land") return 2;
//     else if (column == "Pasture Land") return 3;
//     else if (column == "Mountains") return 4;
//     else if (column == "Desert") return 5;
//     else return -1; // Handle unknown column names
// }

//     Tile* Board::getTile(int number) {
//         if (tileMap.find(number) != tileMap.end()) {
//             return tileMap[number];
//         }
//         return nullptr;
//     }


//     void ariel::Board::printBoard(const std::vector<ariel::Tile>& tiles) {
//     if (tiles.size() != 19) {
//         std::cerr << "Error: The number of tiles should be 19 for a Catan board." << std::endl;
//         return;
//     }
//     std::cout << "####### THE BOARD OF THE GAME #######" << std::endl;
//     std::vector<int> rowSizes = {3, 4, 5, 4, 3};
//     size_t tileIndex = 0; // Use size_t for tileIndex to match the type of vector indices

//     // Top sea row
//     std::cout << "            sea      sea     sea     sea" << std::endl;

//     for (std::size_t i = 0; i < rowSizes.size(); ++i) {
//         int numTilesInRow = rowSizes[i];
//         int spacesBeforeRow = 5 - numTilesInRow;

//         // Print leading spaces for sea
//         for (int s = 0; s < spacesBeforeRow; ++s) {
//             std::cout << "  ";
//         }

//         // Print sea at the beginning of the row
//         std::cout << "sea ";

//         // Print tiles in the row
//         for (int j = 0; j < numTilesInRow; ++j) {
//             std::string tileType = tiles[tileIndex].getType();
//             int tileNumber = tiles[tileIndex].getNumber();
//             std::cout << " " << tileType << "(" << tileNumber << ") ";
//             tileIndex++;
//         }

//         // Print sea at the end of the row
//         std::cout << " sea" << std::endl;
//     }

//     // Bottom sea row
//     std::cout << "            sea      sea      sea      sea" << std::endl;
//     std::cout << "#####################################" << std::endl;
// }



// } // namespace ariel

#include "board.hpp"
#include "player.hpp"
#include <iostream>
#include <algorithm>

namespace ariel {

    Board::Board() {
        initializeAdjacencyList();
        initializeBoard();
    }

    void Board::initializeAdjacencyList() {
        adjacencyList = {
            {1, {2, 9}}, {2, {1, 3}}, {3, {2, 4, 11}}, {4, {3, 5}}, {5, {4, 6, 13}}, 
            {6, {5, 7}}, {7, {6, 15}}, {8, {18, 9}}, {9, {8, 10, 1}}, {10, {9, 11, 20}}, 
            {11, {3, 10, 12}}, {12, {11, 13, 22}}, {13, {12, 5, 14}}, {14, {13, 15, 24}}, 
            {15, {7, 16, 14}}, {16, {15, 26}}, {17, {28}}, {18, {17, 19, 8}}, {19, {18, 20, 30}}, 
            {20, {10, 19, 21}}, {21, {20, 22, 32}}, {22, {12, 21, 23}}, {23, {24, 22, 34}}, 
            {24, {23, 25, 14}}, {25, {24, 36}}, {26, {25, 27, 16}}, {27, {26, 38}}, 
            {28, {17, 29}}, {29, {28, 30, 39}}, {30, {29, 19, 31}}, {31, {30, 32, 41}}, 
            {32, {31, 21, 33}}, {33, {32, 34, 43}}, {34, {33, 35, 23}}, {35, {34, 36, 45}}, 
            {36, {35, 25, 37}}, {37, {36, 38, 47}}, {38, {37, 27}}, {39, {29, 40}}, 
            {40, {39, 41, 48}}, {41, {31, 40, 42}}, {42, {41, 43, 50}}, {43, {42, 44, 33}}, 
            {44, {43, 52, 45}}, {45, {44, 35, 46}}, {46, {45, 54, 47}}, {47, {46, 37}}, 
            {48, {40, 49}}, {49, {48, 50}}, {50, {49, 42, 51}}, {51, {50, 52}}, 
            {52, {51, 44, 53}}, {53, {52, 54}}, {54, {53, 46}}
        };
    }

    // void Board::initializeBoard() {
    //     // Clear the tiles vector before adding new tiles
    //     tiles.clear();
    //     tileMap.clear();

    //     // Define the fixed positions and numbers for the tiles according to Catan rules
    //     std::vector<std::pair<std::string, int>> fixedTiles = {
    //         {"Forest", 5}, {"Hills", 2}, {"Agricultural Land", 6}, {"Pasture Land", 3}, {"Forest", 8},
    //         {"Mountains", 10}, {"Agricultural Land", 9}, {"Forest", 12}, {"Pasture Land", 11}, {"Forest", 4},
    //         {"Desert", 7}, {"Mountains", 8}, {"Agricultural Land", 3}, {"Pasture Land", 4}, {"Mountains", 5},
    //         {"Hills", 6}, {"Pasture Land", 9}, {"Agricultural Land", 10}, {"Forest", 11}
    //     };

    //     for (const auto& tile : fixedTiles) {
    //         if (tile.first == "Desert") {
    //             tiles.push_back(Tile(tile.first, tile.second)); // Use Tile for Desert
    //         } else if (tile.first == "Forest") {
    //             tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Wood));
    //         } else if (tile.first == "Hills") {
    //             tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Brick));
    //         } else if (tile.first == "Agricultural Land") {
    //             tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Wheat));
    //         } else if (tile.first == "Mountains") {
    //             tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Ore));
    //         } else if (tile.first == "Pasture Land") {
    //             tiles.push_back(ResourceTile(tile.first, tile.second, Resource::Sheep));
    //         }

    //         if (tile.first != "Desert") {
    //             tileMap[tile.second] = &tiles.back(); // Map the number to the tile
    //         }
    //     }
    // }

    void Board::initializeBoard() {
        // Clear the tiles vector before adding new tiles
        tiles.clear();
        tileMap.clear();

        // Define the fixed positions and numbers for the tiles according to Catan rules
        std::vector<std::tuple<std::string, int, std::vector<int>>> fixedTiles = {
            {"Mountains", 10, {1, 2, 3, 9, 10, 11}},
            {"Pasture Land", 2, {3, 4, 5, 11, 12, 13}},
            {"Forest", 9, {5, 6, 7, 13, 14, 15}},
            {"Agricultural Land", 12, {8, 9, 10, 18, 19, 20}},
            {"Hills", 6, {10, 11, 12, 22, 21, 20}},
            {"Pasture Land", 4, {12, 13, 14, 24, 23, 22}},
            {"Hills", 10, {14, 15, 16, 26, 25, 24}},
            {"Agricultural Land", 9, {17, 18, 19, 28, 29, 30}},
            {"Forest", 11, {19, 20, 21, 32, 31, 30}},
            {"Desert", 7, {21, 22, 23, 34, 33, 32}},
            {"Forest", 3, {23, 24, 25, 36, 35, 34}},
            {"Mountains", 8, {25, 26, 27, 38, 37, 36}},
            {"Forest", 8, {29, 30, 31, 41, 40, 39}},
            {"Mountains", 3, {31, 32, 33, 43, 42, 41}},
            {"Agricultural Land", 4, {33, 34, 35, 45, 44, 43}},
            {"Pasture Land", 5, {35, 36, 37, 47, 46, 45}},
            {"Hills", 5, {40, 41, 42, 50, 49, 48}},
            {"Agricultural Land", 6, {42, 43, 52, 51, 50, 44}},
            {"Pasture Land", 11, {44, 45, 46, 54, 53, 52}}
        };

        for (const auto& tile : fixedTiles) {
            if (std::get<0>(tile) == "Desert") {
                DesertTile desertTile(std::get<0>(tile), std::get<1>(tile));
                tiles.push_back(desertTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if (std::get<0>(tile) == "Mountains" && std::get<1>(tile) == 10) {
                ResourceTile mountainsTile(std::get<0>(tile), std::get<1>(tile), Resource::Ore);
                tiles.push_back(mountainsTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if (std::get<0>(tile) == "Pasture Land" && std::get<1>(tile) == 2) {
                ResourceTile pastureTile(std::get<0>(tile), std::get<1>(tile), Resource::Sheep);
                tiles.push_back(pastureTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if (std::get<0>(tile) == "Forest" && std::get<1>(tile) == 9) {
                ResourceTile forestTile(std::get<0>(tile), std::get<1>(tile), Resource::Wood);
                tiles.push_back(forestTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if (std::get<0>(tile) == "Agricultural Land" && std::get<1>(tile) == 12) {
                ResourceTile agriLandTile(std::get<0>(tile), std::get<1>(tile), Resource::Wheat);
                tiles.push_back(agriLandTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if (std::get<0>(tile) == "Hills" && std::get<1>(tile) == 6) {
                ResourceTile hillsTile(std::get<0>(tile), std::get<1>(tile), Resource::Brick);
                tiles.push_back(hillsTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if (std::get<0>(tile) == "Pasture Land" && std::get<1>(tile) == 4) {
                ResourceTile pastureTile(std::get<0>(tile), std::get<1>(tile), Resource::Sheep);
                tiles.push_back(pastureTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if (std::get<0>(tile) == "Hills" && std::get<1>(tile) == 10) {
                ResourceTile hillsTile(std::get<0>(tile), std::get<1>(tile), Resource::Brick);
                tiles.push_back(hillsTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if (std::get<0>(tile) == "Agricultural Land" && std::get<1>(tile) == 9) {
                ResourceTile agriLandTile(std::get<0>(tile), std::get<1>(tile), Resource::Wheat);
                tiles.push_back(agriLandTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if (std::get<0>(tile) == "Forest" && std::get<1>(tile) == 11) {
                ResourceTile forestTile(std::get<0>(tile), std::get<1>(tile), Resource::Wood);
                tiles.push_back(forestTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if (std::get<0>(tile) == "Forest" && std::get<1>(tile) == 3) {
                ResourceTile forestTile(std::get<0>(tile), std::get<1>(tile), Resource::Wood);
                tiles.push_back(forestTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if(std::get<0>(tile) == "Mountains" && std::get<1>(tile) == 8) {
                ResourceTile mountainsTile(std::get<0>(tile), std::get<1>(tile), Resource::Ore);
                tiles.push_back(mountainsTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if (std::get<0>(tile) == "Forest" && std::get<1>(tile) == 8) {
                ResourceTile forestTile(std::get<0>(tile), std::get<1>(tile), Resource::Wood);
                tiles.push_back(forestTile);
                tiles.back().addFixedPoints(std::get<2>(tile));   
            } else if(std::get<0>(tile) == "Mountains" && std::get<1>(tile) == 3) {
                ResourceTile mountainsTile(std::get<0>(tile), std::get<1>(tile), Resource::Ore);
                tiles.push_back(mountainsTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if(std::get<0>(tile) == "Agricultural Land" && std::get<1>(tile) == 4) {
                ResourceTile agriLandTile(std::get<0>(tile), std::get<1>(tile), Resource::Wheat);
                tiles.push_back(agriLandTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if(std::get<0>(tile) == "Pasture Land" && std::get<1>(tile) == 5) {
                ResourceTile pastureTile(std::get<0>(tile), std::get<1>(tile), Resource::Sheep);
                tiles.push_back(pastureTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if(std::get<0>(tile) == "Hills" && std::get<1>(tile) == 5) {
                ResourceTile hillsTile(std::get<0>(tile), std::get<1>(tile), Resource::Brick);
                tiles.push_back(hillsTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else if(std::get<0>(tile) == "Agricultural Land" && std::get<1>(tile) == 6) {
                ResourceTile agriLandTile(std::get<0>(tile), std::get<1>(tile), Resource::Wheat);
                tiles.push_back(agriLandTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            } else(std::get<0>(tile) == "Pasture Land" && std::get<1>(tile) == 11); {
                ResourceTile pastureTile(std::get<0>(tile), std::get<1>(tile), Resource::Sheep);
                tiles.push_back(pastureTile);
                tiles.back().addFixedPoints(std::get<2>(tile));
            }
            // Map the number to the tile
            tileMap[std::get<1>(tile)] = &tiles.back();
        }
    }

    // bool Board::placeSettlement(Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum) {
    //     bool placed = false;
    //     for (size_t i = 0; i < places.size(); ++i) {
    //         if (!isPlaceOccupied(places[i], placesNum[i])) {
    //             settlements.emplace_back(player.getName(), placesNum[i]); // Assuming Settlement constructor takes (const std::string&, int)
    //             occupiedPlaces[{places[i], placesNum[i]}] = "settlement";
    //             placed = true;
    //             break;
    //         }
    //     }
    //     return placed;
    // }

    // bool Board::placeRoad(const Player& player, const std::vector<std::string>& places, const std::vector<int>& placesNum) {
    //     bool placed = false;
    //     for (size_t i = 0; i < places.size(); ++i) {
    //         if (!isPlaceOccupied(places[i], placesNum[i])) {
    //             // Example logic to get start and end tiles for the road
    //             Tile* startTile = getTile(placesNum[i]);
    //             Tile* endTile = getTile((placesNum[i] % 54) + 1); // Example logic to get end tile
    //             if (startTile && endTile) {
    //                 roads.emplace_back(player, *startTile, *endTile); // Using const Player& here
    //                 occupiedPlaces[{places[i], placesNum[i]}] = "road";
    //                 placed = true;
    //                 break;
    //             }
    //         }
    //     }
    //     return placed;
    // }

    // bool Board::isPlaceOccupied(const std::string& place, int placeNum) const {
    //     return occupiedPlaces.find({place, placeNum}) != occupiedPlaces.end();
    // }

    bool Board::isPlaceOccupied(int point) const {
    for (const auto& place : occupiedPlaces) {
        std::cout << "Checking place: " << place.first.first << " -> " << place.first.second << std::endl;
        if (place.first.second == point) {
            std::cout << "Place " << point << " is occupied." << std::endl;
            return true;
        }
    }
    std::cout << "Place " << point << " is not occupied." << std::endl;
    return false;
}

  
    Tile& Board::getTile(int point) {
        return tiles[static_cast<std::vector<Tile>::size_type>(point)];
    }

    bool Board::areAdjacent(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const {
        if (adjacencyList.find(a.second) != adjacencyList.end()) {
            const auto& neighbors = adjacencyList.at(a.second);
            return std::find(neighbors.begin(), neighbors.end(), b.second) != neighbors.end();
        }
        return false;
    }

    bool Board::isWithinTwoEdges(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const {
        if (areAdjacent(a, b)) return true;
        if (adjacencyList.find(a.second) != adjacencyList.end()) {
            const auto& neighbors = adjacencyList.at(a.second);
            for (int neighbor : neighbors) {
                if (areAdjacent({a.first, neighbor}, b)) return true;
            }
        }
        return false;
    }

    std::vector<int> Board::getNeighbors(int point) const {
        if (adjacencyList.find(point) != adjacencyList.end()) {
            return adjacencyList.at(point);
        }
        return {};
    }

void ariel::Board::printBoard() {
    std::cout << "####### THE BOARD OF THE GAME #######" << std::endl;
    std::cout << "            sea      sea     sea     sea" << std::endl;
    std::cout << "    sea  Mountains(10)  Pasture Land(2)  Forest(9)  sea" << std::endl;
    std::cout << "  sea  Agricultural Land(12)  Hills(6)  Pasture Land(4)  Hills(10)  sea" << std::endl;
    std::cout << "sea  Agricultural Land(9)  Forest(11)  Desert(7)  Forest(3)  Mountains(8)  sea" << std::endl;
    std::cout << "  sea  Forest(8)  Mountains(3)  Agricultural Land(4)  Pasture Land(5)  sea" << std::endl;
    std::cout << "    sea  Hills(5)  Agricultural Land(6)  Pasture Land(11)  sea" << std::endl;
    std::cout << "            sea      sea      sea      sea" << std::endl;
    std::cout << "#####################################" << std::endl;
}


    int Board::columnIndex(const std::string& column) const {
        if (column.size() == 1) {
            return column[0] - 'A';
        } else if (column.size() == 2) {
            return (column[0] - 'A' + 1) * 26 + (column[1] - 'A');
        }
        return -1;
    }

bool Board::isPlaceAdjacentToPlayerRoad(const std::pair<std::string, int>& place, const Player& player) const {
    auto it = adjacencyList.find(place.second);
    if (it != adjacencyList.end()) {
        const std::vector<int>& neighbors = it->second;
        for (int neighbor : neighbors) {
            if (player.hasRoadAt(neighbor)) {
                return true;
            }
        }
    }
    return false;
}

    bool Board::isValidSettlementPoint(int point, const Player& player) {
    // // Check if the point is within valid range
    // if (point < 1 || point > 54) {
    //     std::cout << "Invalid point for settlement: out of board range." << std::endl;
    //     return false;
    // }

    // // Check if the point is already occupied by another settlement or city
    // if (occupiedPlaces.find(point) != occupiedPlaces.end()) {
    //     std::cout << "Invalid point for settlement: point already occupied." << std::endl;
    //     return false;
    // }

    // // Check if the point is adjacent to any road owned by the player
    // for (const auto& road : player.getRoads()) {
    //     int start = road.first;
    //     int end = road.second;
    //     if (start == point || end == point) {
    //         return true;
    //     }
    // }

    // std::cout << "Invalid point for settlement: not adjacent to player's road." << std::endl;
    // return false;
        auto it = occupiedPlaces.find({player.getName(), point});
        return it == occupiedPlaces.end();
    }

    // bool Board::isValidRoad(int startPoint, int endPoint, const Player& player)  {
    // // Initial placements: skip detailed checks
    // if (player.getRoads().size() < 2) {
    //     return !isPlaceOccupied("some_place", startPoint) && !isPlaceOccupied("some_place", endPoint);
    // }

    // bool Board::isValidRoad(int startPoint, int endPoint, const Player& player) const {
    //     // Example validity check; implement your actual logic
    //     return !isPlaceOccupied(player.getName(), startPoint) && !isPlaceOccupied(player.getName(), endPoint);
    // }
    
    // bool Board::isValidRoad(int startPoint, int endPoint, const Player& player) const {
    //     // Example validity check; implement your actual logic
    //     if (player.hasRoadAt(startPoint) || player.hasSettlement(startPoint) ||
    //         player.hasRoadAt(endPoint) || player.hasSettlement(endPoint)) {
    //         return true;
    //     }
    //     return areAdjacent(std::make_pair("", startPoint), std::make_pair("", endPoint));
    // }

    bool Board::isValidRoad(int startPoint, int endPoint, const Player& player) const {
    // Check if the player has a settlement or city at either startPoint or endPoint
    if (player. hasSettlement(startPoint) || player. hasSettlement(endPoint)) {
        return true;
    }

    // Check if the player has a road at either startPoint or endPoint
    if (player.hasRoadAt(startPoint) || player.hasRoadAt(endPoint)) {
        return true;
    }

    // Check if the points are adjacent and free of roads
    if (areAdjacent(std::make_pair(player.getName(), startPoint), std::make_pair(player.getName(), endPoint))) {
        return true;
    }

    // Otherwise, the road placement is invalid
    return false;
}

    
    // // Check if the road is connected to player's existing roads or settlements
    // if (player.hasRoadAt(startPoint) || player.hasSettlement(startPoint) ||
    //     player.hasRoadAt(endPoint) || player.hasSettlement(endPoint)) {
    //     return true;
    // }

    // // Check if the road points are adjacent
    // return areAdjacent(std::make_pair("some_place", startPoint), std::make_pair("some_place", endPoint));



    // void Board::placeSettlement(int point, const Player& player) {
    //     // Place the settlement on the board and mark the point as occupied
    //     occupiedPlaces[{player.getName(), point}] = "Settlement";
    // }

    bool Board::placeSettlement(int point, const std::string& playerName) {
        // Check if the point is valid for placing a settlement
        if (!isPlaceOccupied(point)) {
            occupiedPlaces[std::make_pair(playerName, point)] = "Settlement";
            settlements.emplace_back(playerName, point); 
            std::cout << playerName << " placed a settlement at point: " << point << std::endl;
            
            // Debug print the current board state after placing settlement
            std::cout << "Current Board State after placing settlement:" << std::endl;
            printBoardState();
            
            return true;
        } else {
            std::cerr << "Point " << point << " is already occupied. Cannot place settlement." << std::endl;
            return false;
        }
    }
    
    // bool Board::placeRoad(int startPoint, int endPoint, const Player& player) {
    //     // Example of using occupiedPlaces
    //     occupiedPlaces[std::make_pair(player.getName(), startPoint)] = "Road";
    //     // You can use endPoint here if necessary
    //     std::cout << "Placing road from " << startPoint << " to " << endPoint << std::endl;
    //     // Other logic for placing road
    //     return true;
    // }
    bool Board::placeRoad(int startPoint, int endPoint, const Player& player) {
    // Check if the road points are valid
    if (isValidRoad(startPoint, endPoint, player)) {
        // Example of using occupiedPlaces
        occupiedPlaces[std::make_pair(player.getName(), startPoint)] = "Road";
        occupiedPlaces[std::make_pair(player.getName(), endPoint)] = "Road";
        
        std::cout << "Placing road from " << startPoint << " to " << endPoint << std::endl;
        
        // Other logic for placing road
        
        return true;
    } else {
        std::cout << "Invalid road placement from " << startPoint << " to " << endPoint << std::endl;
        return false;
    }
}

// bool Board::canAddCity(int point) const {
//     for (const auto& settlement : settlements) {
//         if (settlement.getPoint() == point && !settlement.getIsCity()) {
//             std::cout << "Found a settlement at point " << point << " that can be upgraded to a city." << std::endl;
//             return true; // Found a settlement that can be upgraded to a city
//         }
//     }
//     std::cout << "No settlement found at point " << point << " that can be upgraded to a city." << std::endl;
//     return false; // No settlement found at the specified point
// }

bool Board::canAddCity(int point) const {
    for (const auto& settlement : settlements) {
        if (settlement.getPoint() == point && !settlement.getIsCity()) {
            std::cout << "Found a settlement at point " << point << " that can be upgraded to a city." << std::endl;
            return true; // Found a settlement that can be upgraded to a city
        }
    }
    std::cout << "No settlement found at point " << point << " that can be upgraded to a city." << std::endl;
    return false; // No settlement found at the specified point
}


//  void Board::upgradeSettlementToCity(int point, const std::string& playerName) {
//         // Update the occupiedPlaces map
//         auto it = occupiedPlaces.find(std::make_pair(playerName, point));
//         if (it != occupiedPlaces.end() && it->second == "Settlement") {
//             it->second = "City";
//             std::cout << "Upgraded settlement at point " << point << " to a city for player " << playerName << std::endl;
//         } else {
//             std::cerr << "Error: No settlement found at point " << point << " for player " << playerName << std::endl;
//         }

//         // Update the corresponding settlement in the settlements vector
//         for (auto& settlement : settlements) {
//             if (settlement.getPoint() == point && settlement.getOwner() == playerName) {
//                 settlement.setIsCity(true);
//                 return;
//             }
//         }
//     }
void Board::upgradeSettlementToCity(int point, const std::string& playerName) {
    // Update occupiedPlaces
    for (auto& entry : occupiedPlaces) {
        if (entry.first.second == point && entry.second == "Settlement") {
            entry.second = "City";
            break;
        }
    }

    // Find and update settlements vector
    for (auto& settlement : settlements) {
        if (settlement.getPoint() == point && settlement.getPlace() == playerName) {
            settlement.upgradeToCity();
            break;
        }
    }
}

    bool Board::hasSettlementOrCity(int point, const std::string& playerName) const {
    std::cout << "Checking settlements and cities for player " << playerName << " at point " << point << std::endl;

    bool foundSettlementOrCity = false;

    for (const auto& settlement : settlements) {
        if (settlement.getPoint() == point && settlement.getOwner() == playerName) {
            std::cout << "Found settlement for player " << playerName << " at point " << point << std::endl;
            foundSettlementOrCity = true;
            break;
        }
    }

    if (!foundSettlementOrCity) {
        for (const auto& city : cities) {
            if (city.getPoint() == point && city.getOwner() == playerName) {
                std::cout << "Found city for player " << playerName << " at point " << point << std::endl;
                foundSettlementOrCity = true;
                break;
            }
        }
    }

    if (!foundSettlementOrCity) {
        std::cout << "No settlement or city for player " << playerName << " at point " << point << std::endl;
    }

    return foundSettlementOrCity;
}

void Board::printBoardState() const {
    std::cout << "Occupied Places:" << std::endl;
    for (const auto& entry : occupiedPlaces) {
        std::cout << "Player: " << entry.first.first << ", Point: " << entry.first.second << ", Type: " << entry.second << std::endl;
    }

    // Print settlements
    std::cout << "Settlements:" << std::endl;
    for (const auto& settlement : settlements) {
        std::cout << "Player: " << settlement.getPlace() << ", Point: " << settlement.getPoint() << ", Is City: " << (settlement.getIsCity() ? "Yes" : "No") << std::endl;
    }
}


// void addSettlement(int point){
//     this.settlements.emplace_push()
// }

 
        // Other methods of the Board class
    


    // bool Board::isValidPosition(int row, int col) const {
    //     return row >= 0 && row < ROWS && col >= 0 && col < COLUMNS;
    // }


} // namespace ariel


