//ID: 208018028, Mail: ronimordechai70@gmail.com
/*
 * Demo file for Catan Game.
*/

#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
#include "development_card.hpp"
#include "resource.hpp"
#include <random>

using namespace std;
using namespace ariel;

int main() {
    cout << "#### START GAME ####" << endl;

    // Create players
    Player p1("Yossi");
    Player p2("Amit");
    Player p3("Dana");
 
    Catan catan(p1, p2, p3);

    cout << "\nStarting the game...\n";

    // Starting the game. Every player places two settlements and two roads.
    catan.ChooseStartingPlayer();   // Assume it's Amit.
    std::cout << std::endl;
    cout << "\n";

    // Create the board
    Board board;

    // Print the initial board
    board.printBoard();
    cout << "\n";

    
    // First player places initial settlement and roads
    catan.placeInitialSettlement(p1, 41, 42, board); // Settlement at 41, Road from 41 to 42
    cout << "\n";

    // Second player places initial settlement and roads
    catan.placeInitialSettlement(p2, 26, 27, board); // Settlement at 26, Road from 26 to 27
    cout << "\n";

    // Third player places initial settlement and roads
    catan.placeInitialSettlement(p3, 14, 15, board); // Settlement at 14, Road from 14 to 16
    cout << "\n";

    // Second settlements
    catan.placeSecondSettlement(p3, 11, 12, board); // Settlement at 16, Road from 16 to 18
    cout << "\n";

    catan.placeSecondSettlement(p2, 28, 29, board); // Settlement at 28, Road from 28 to 30
    cout << "\n";

    catan.placeSecondSettlement(p1, 44, 45, board); // Settlement at 43, Road from 43 to 45
    cout << "\n";

    // Simulate fewer game turns to speed up the process
    for (int i = 1; i <= 5; ++i) {
        cout << "### ROUND " << i << " ###" << endl;

        // Player 1 turn
        catan.rollDice(p1); // Let's say it's 4.
        // p1.placeRoad({"Forest", "Hills"}, {5, 6}, board);
        p1.endTurn();

        // Player 2 turn
        catan.rollDice(p2); // Let's say it's 9.
        p2.endTurn();

        // Player 3 turn
        catan.rollDice(p3); // Let's say it's 3.
        p3.endTurn();

        // Player 1 turn
        catan.rollDice(p1); // Let's say it's 6.
        p1.trade(p2, "wood", "brick", 1, 1);
        p1.addResource(Resource::Ore, 1);
        p1.addResource(Resource::Sheep, 1);
        p1.addResource(Resource::Wheat, 1);
        std::shared_ptr<DevelopmentCard> knightCard = std::make_shared<KnightCard>();
        p1.buyDevelopmentCard(knightCard);
        try {
            p1.useDevelopmentCard("Knight", catan);
            cout << "Player " << p1.getName() << " used a development card." << endl;
        } catch (const std::invalid_argument& e) {
            cerr << "Cannot use development card: " << e.what() << endl;
        }
        p1.endTurn();

        // Player 2 turn
        catan.rollDice(p2); // Let's say it's 9.
        p2.addResource(Resource::Ore, 1);
        p2.addResource(Resource::Sheep, 1);
        p2.addResource(Resource::Wheat, 1);
        std::shared_ptr<DevelopmentCard> victoryPointCard = std::make_shared<VictoryPointCard>();
        p2.buyDevelopmentCard(victoryPointCard);
        try {
            p2.useDevelopmentCard("Victory Point", catan);
            cout << "Player " << p2.getName() << " used a development card." << endl;
        } catch (const std::invalid_argument& e) {
            cerr << "Cannot use development card: " << e.what() << endl;
        }
        

        p2.endTurn();

       
        p1.addResource(Resource::Ore, 3);
        p1.addResource(Resource::Wheat, 2);
       

         // Debug: Print Player 1's resources
        cout << "Player 1 resources after addition:" << endl;
        cout << "Ore: " << p1.getResource(Resource::Ore) << endl;
        cout << "Wheat: " << p1.getResource(Resource::Wheat) << endl;

        int cityPoint = 41;
        catan.addCityToPlayer(p1, cityPoint, board);

        // Player 2 turn
        catan.rollDice(p3); // Let's say it's 9.
        p3.addResource(Resource::Ore, 1);
        p3.addResource(Resource::Sheep, 1);
        p3.addResource(Resource::Wheat, 1);
        cout << "Player 3 resources before DevelopmentCard Road Construction:" << endl;
        cout << "Brick: " << p3.getResource(Resource::Brick) << endl;
        cout << "Wood: " << p3.getResource(Resource::Wood) << endl;

        std::shared_ptr<DevelopmentCard> roadConstructionCard  = std::make_shared<RoadConstructionCard>();
        p3.buyDevelopmentCard(roadConstructionCard);
        try {
            p3.useDevelopmentCard("Road Construction", catan);
            cout << "Player " << p3.getName() << " used a development card." << endl;
        } catch (const std::invalid_argument& e) {
            cerr << "Cannot use development card: " << e.what() << endl;
        }

        cout << "Player 3 resources after DevelopmentCard Road Construction:" << endl;
        cout << "Brick: " << p3.getResource(Resource::Brick) << endl;
        cout << "Wood: " << p3.getResource(Resource::Wood) << endl;


        // Print points of each player
        p1.printPoints();
        p2.printPoints();
        p3.printPoints();

        // Check for a winner
        if (p1.getPoints() >= 10) {
            cout << "Winner: " << p1.getName() << endl;
            break;
        } else if (p2.getPoints() >= 10) {
            cout << "Winner: " << p2.getName() << endl;
            break;
        } else if (p3.getPoints() >= 10) {
            cout << "Winner: " << p3.getName() << endl;
            break;
        }

        cout << endl;
    }
    // Add resources for demonstration after game turns
    p1.addResource(Resource::Sheep, 3);
    p2.addResource(Resource::Sheep, 2);
    p3.addResource(Resource::Ore, 2);
    p3.addResource(Resource::Sheep, 2);
    p3.addResource(Resource::Wheat, 2);
    cout << "Sheep p1: " << p1.getResource(Resource::Sheep) << endl;
    cout << "Sheep p2: " << p2.getResource(Resource::Sheep) << endl;
    // Print resources before using Monopoly Card
    cout << "Player 3 resources before using Monopoly Card:" << endl;
    cout << "Brick: " << p3.getResource(Resource::Brick) << endl;
    cout << "Wood: " << p3.getResource(Resource::Wood) << endl;
    cout << "Sheep: " << p3.getResource(Resource::Sheep) << endl;
    cout << "Wheat: " << p3.getResource(Resource::Wheat) << endl;
    cout << "Ore: " << p3.getResource(Resource::Ore) << endl;

    std::shared_ptr<DevelopmentCard> monopolyCard = std::make_shared<MonopolyCard>(Resource::Sheep);
    p3.buyDevelopmentCard(monopolyCard);
    // Debug output before applying the card effect
    std::cout << "Player " << p3.getName() << " resources before applying Monopoly Card effect:" << std::endl;
    std::cout << "Sheep: " << p3.getResource(Resource::Sheep) << std::endl;
    try {
        p3.useDevelopmentCard("Monopoly", catan);
        std::cout << "Player " << p3.getName() << " used a development card." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Cannot use development card: " << e.what() << std::endl;
    }

     // Print resources after using Monopoly Card
    cout << "Player 3 resources after using Monopoly Card:" << endl;
    cout << "Brick: " << p3.getResource(Resource::Brick) << endl;
    cout << "Wood: " << p3.getResource(Resource::Wood) << endl;
    cout << "Sheep: " << p3.getResource(Resource::Sheep) << endl;
    cout << "Wheat: " << p3.getResource(Resource::Wheat) << endl;
    cout << "Ore: " << p3.getResource(Resource::Ore) << endl;

    std::shared_ptr<DevelopmentCard> yearOfPlentyCard = std::make_shared<YearOfPlentyCard>(Resource::Wheat, Resource::Wood);
    p3.buyDevelopmentCard(yearOfPlentyCard);

    // Player Dana uses the development card
    try {
        p3.useDevelopmentCard("Year of Plenty", catan);
        std::cout << "Player " << p3.getName() << " used a Year of Plenty card." << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Cannot use development card: " << e.what() << std::endl;
    }

    cout << "Brick: " << p3.getResource(Resource::Brick) << endl;
    cout << "Wood: " << p3.getResource(Resource::Wood) << endl;
    cout << "Sheep: " << p3.getResource(Resource::Sheep) << endl;
    cout << "Wheat: " << p3.getResource(Resource::Wheat) << endl;
    cout << "Ore: " << p3.getResource(Resource::Ore) << endl;

    std:: cout<< "checks the roll dice:" << std:: endl;
        // Print resources of each player after distribution
        cout << "Player 1 resources before distribution:" << endl;
        cout << "Brick: " << p1.getResource(Resource::Brick) << endl;
        cout << "Wood: " << p1.getResource(Resource::Wood) << endl;
        cout << "Sheep: " << p1.getResource(Resource::Sheep) << endl;
        cout << "Wheat: " << p1.getResource(Resource::Wheat) << endl;
        cout << "Ore: " << p1.getResource(Resource::Ore) << endl;

        cout << "Player 2 resources before distribution:" << endl;
        cout << "Brick: " << p2.getResource(Resource::Brick) << endl;
        cout << "Wood: " << p2.getResource(Resource::Wood) << endl;
        cout << "Sheep: " << p2.getResource(Resource::Sheep) << endl;
        cout << "Wheat: " << p2.getResource(Resource::Wheat) << endl;
        cout << "Ore: " << p2.getResource(Resource::Ore) << endl;

        cout << "Player 3 resources before distribution:" << endl;
        cout << "Brick: " << p3.getResource(Resource::Brick) << endl;
        cout << "Wood: " << p3.getResource(Resource::Wood) << endl;
        cout << "Sheep: " << p3.getResource(Resource::Sheep) << endl;
        cout << "Wheat: " << p3.getResource(Resource::Wheat) << endl;
        cout << "Ore: " << p3.getResource(Resource::Ore) << endl;
        // Player 1 turn
        catan.rollDice(p1); // Let's say it's 4.
        p1.endTurn();

        // Player 2 turn
        catan.rollDice(p2); // Let's say it's 9.
        p2.endTurn();

        // Player 3 turn
        catan.rollDice(p3); // Let's say it's 3.
        p3.endTurn();

        // Print resources of each player after distribution
        cout << "Player 1 resources after distribution:" << endl;
        cout << "Brick: " << p1.getResource(Resource::Brick) << endl;
        cout << "Wood: " << p1.getResource(Resource::Wood) << endl;
        cout << "Sheep: " << p1.getResource(Resource::Sheep) << endl;
        cout << "Wheat: " << p1.getResource(Resource::Wheat) << endl;
        cout << "Ore: " << p1.getResource(Resource::Ore) << endl;

        cout << "Player 2 resources after distribution:" << endl;
        cout << "Brick: " << p2.getResource(Resource::Brick) << endl;
        cout << "Wood: " << p2.getResource(Resource::Wood) << endl;
        cout << "Sheep: " << p2.getResource(Resource::Sheep) << endl;
        cout << "Wheat: " << p2.getResource(Resource::Wheat) << endl;
        cout << "Ore: " << p2.getResource(Resource::Ore) << endl;

        cout << "Player 3 resources after distribution:" << endl;
        cout << "Brick: " << p3.getResource(Resource::Brick) << endl;
        cout << "Wood: " << p3.getResource(Resource::Wood) << endl;
        cout << "Sheep: " << p3.getResource(Resource::Sheep) << endl;
        cout << "Wheat: " << p3.getResource(Resource::Wheat) << endl;
        cout << "Ore: " << p3.getResource(Resource::Ore) << endl;

        cout << endl;
    
    return 0;
}