// // //ID: 208018028, Mail: ronimordechai70@gmail.com
// #include "development_card.hpp"
// #include "player.hpp" 
// #include "catan.hpp" 
// #include <iostream>
// #include <stdexcept> // For std::invalid_argument

// namespace ariel {

//     std::string KnightCard::getType() const {
//         return "Knight";
//     }

//     void KnightCard::applyEffect(Player& player) {
//         std::cout << "Knight card played: Increase knight count." << std::endl;
//         player.addKnightCard();
//     }

//     std::string VictoryPointCard::getType() const {
//         return "Victory Point";
//     }

//     void VictoryPointCard::applyEffect(Player& player) {
//         std::cout << "Victory Point card played: Gain 1 victory point." << std::endl;
//         player.addPoints(1); 
//     }
    
//     std::string MonopolyCard::getType() const {
//         return "Monopoly";
//     }

//     void MonopolyCard::applyEffect(Player& player) {
//         std::cout << "Monopoly card played: Collect all resources of one type from other players." << std::endl;
        
//         // Get the resource type to collect from the player
//         std::cout << "Choose a resource type to collect (1. BRICK, 2. LUMBER, 3. ORE, 4. GRAIN, 5. WOOL): ";
//         int choice;
//         std::cin >> choice;
        
//         Resource chosenResource;
//         switch (choice) {
//             case 1:
//                 chosenResource = Resource::Brick;
//                 break;
//             case 2:
//                 chosenResource = Resource::Wood;
//                 break;
//             case 3:
//                 chosenResource = Resource::Ore;
//                 break;
//             case 4:
//                 chosenResource = Resource::Wheat;
//                 break;
//             case 5:
//                 chosenResource = Resource::Sheep;
//                 break;
//             default:
//                 throw std::invalid_argument("Invalid resource choice.");
//         }
        
//         // Call the Catan class function to handle resource collection
//         Catan.collectMonopolyResources(player, chosenResource);
//     }

//     std::string YearOfPlentyCard::getType() const {
//         return "Year of Plenty";
//     }

//     void YearOfPlentyCard::applyEffect(Player& player) {
//         std::cout << "Year of Plenty card played: Choose and gain two resources of your choice." << std::endl;
        
//         // Ask the player to choose two resources
//         std::cout << "Choose two resources to gain:" << std::endl;
//         std::cout << "1. Brick" << std::endl;
//         std::cout << "2. Ore" << std::endl;
//         std::cout << "3. Wood" << std::endl;
//         std::cout << "4. Wheat" << std::endl;
//         std::cout << "5. Sheep" << std::endl;

//         int choice1, choice2;
//         std::cin >> choice1 >> choice2;

//         Resource resource1, resource2;

//         // Map the choices to resources
//         switch (choice1) {
//             case 1: resource1 = Resource::Brick; break;
//             case 2: resource1 = Resource::Ore; break;
//             case 3: resource1 = Resource::Wood; break;
//             case 4: resource1 = Resource::Wheat; break;
//             case 5: resource1 = Resource::Sheep; break;
//             default: 
//                 std::cout << "Invalid choice. Defaulting to Brick." << std::endl;
//                 resource1 = Resource::Brick; 
//                 break;
//         }

//         switch (choice2) {
//             case 1: resource2 = Resource::Brick; break;
//             case 2: resource2 = Resource::Ore; break;
//             case 3: resource2 = Resource::Wood; break;
//             case 4: resource2 = Resource::Wheat; break;
//             case 5: resource2 = Resource::Sheep; break;
//             default: 
//                 std::cout << "Invalid choice. Defaulting to Ore." << std::endl;
//                 resource2 = Resource::Ore; 
//                 break;
//         }

//         // Gain the chosen resources
//         player.addResource(resource1, 1);
//         player.addResource(resource2, 1);
//     }

//     std::string RoadConstructionCard::getType() const {
//         return "Road Construction";
//     }

//     void RoadConstructionCard::applyEffect(Player& player) {
//         std::cout << "Road Construction card played: Build two roads for free." << std::endl;
        
//         // Get the last placed road's endpoints
//         auto& roads = player.getRoads();
//         if (roads.empty()) {
//             std::cerr << "No previous roads to extend." << std::endl;
//             return;
//         }

//         // Assuming the last road is the one we want to extend
//         auto lastRoad = roads.back();
//         int startPoint = lastRoad.getEnd();
//         int endPoint = lastRoad.getStart();

//         // Find the direction of the last road
//         int dx = (endPoint - startPoint) % 8;

//         // Calculate the next two endpoints based on the last road's direction
//         int nextStartPoint = lastRoad.getEnd().getPoints(); // Assuming getPoint() returns the point
//         int nextEndPoint = lastRoad.getStart().getPoints(); // Assuming getPoint() returns the point

//         // Build two roads for free
//         Catan.getBoard().placeRoad(nextStartPoint, nextEndPoint, player);
//         Catan.getBoard().placeRoad(nextEndPoint, nextStartPoint, player);// Make it bidirectional
//     }

// } // namespace ariel
#include "development_card.hpp"
#include "catan.hpp"

namespace ariel {

std::string MonopolyCard::getType() const {
    return "Monopoly";
}

void MonopolyCard::applyEffect(Player& player, Catan& game) {
    game.collectMonopolyResources(player, chosenResource);
}

std::string YearOfPlentyCard::getType() const {
    return "Year of Plenty";
}

void YearOfPlentyCard::applyEffect(Player& player, Catan& /*game*/) {
    player.addResource(firstResource, 1);
    player.addResource(secondResource, 1);
}

std::string RoadConstructionCard::getType() const {
    return "Road Construction";
}

void RoadConstructionCard::applyEffect(Player& player, Catan& game) {
    int startPoint = *(lastRoad.getEnd().getPoints().begin()); // Assuming getPoints() returns the point
    int endPoint = *(lastRoad.getStart().getPoints().begin()); // Assuming getPoints() returns the point

    game.getBoard().placeRoad(startPoint, endPoint, player);
    game.getBoard().placeRoad(endPoint, startPoint, player); // Make it bidirectional
}

// std::string KnightCard::getType() const {
//     return "Knight";
// }

void KnightCard::applyEffect(Player& /*player*/, Catan& /*game*/) {
    // Implement Knight's effect here
}

// std::string VictoryPointCard::getType() const {
//     return "Victory Point";
// }

void VictoryPointCard::applyEffect(Player& player, Catan& /*game*/) {
    player.addPoints(1);
}

} // namespace ariel
