// /**
//  * Demo file for Catan Game.
//  */

// #include <iostream>
// #include <stdexcept>
// #include <vector>
// #include <memory>
// #include "catan.hpp"
// #include "player.hpp"
// #include "board.hpp"
// #include "development_card.hpp"

// using namespace std;
// using namespace ariel;

// int main() {
//     cout << "#### START GAME ####" << endl;

//     // Create players
//     Player p1("Yossi");
//     Player p2("Amit");
//     Player p3("Dana");

//     // Create Catan game instance
//     Catan catan(p1, p2, p3);

//     cout << "\nStarting the game...\n";

//     // Starting the game. Every player places two settlements and two roads.
//     catan.ChooseStartingPlayer();   // Assume it's Amit.
//     cout << "\n";

//     // Create the board
//     Board board;

//     // Print the initial board
//     board.printBoard();

//     // First player places settlements and roads
//     vector<string> places1_1 = {"Forest", "Hills", "Pasture Land"};
//     vector<int> placesNum1_1 = {5, 6, 3};
//     catan.placeInitialSettlement(p1, places1_1, placesNum1_1, board);
//     cout << "\n";

//     vector<string> places1_2 = {"Forest", "Hills", "Pasture Land"};
//     vector<int> placesNum1_2 = {5, 6, 3};
//     catan.placeSecondSettlement(p1, places1_2, placesNum1_2, board);
//     cout << "\n";

//     // Second player places settlements and roads
//     vector<string> places2_1 = {"Forest", "Pasture Land"};
//     vector<int> placesNum2_1 = {5, 3};
//     catan.placeInitialSettlement(p2, places2_1, placesNum2_1, board);
//     cout << "\n";

//     vector<string> places2_2 = {"Mountains", "Mountains", "Hills"};
//     vector<int> placesNum2_2 = {8, 5, 6};
//     catan.placeSecondSettlement(p2, places2_2, placesNum2_2, board);
//     cout << "\n";

//     // Third player places settlements and roads
//     vector<string> places3_1 = {"Agricultural Land", "Forest"};
//     vector<int> placesNum3_1 = {10, 11};
//     catan.placeInitialSettlement(p3, places3_1, placesNum3_1, board);
//     cout << "\n";

//     vector<string> places3_2 = {"Mountains", "Forest", "Pasture Land"};
//     vector<int> placesNum3_2 = {8, 11, 9};
//     catan.placeSecondSettlement(p3, places3_2, placesNum3_2, board);
//     cout << "\n";

//     // Simulate fewer game turns to speed up the process
//     for (int i = 1; i <= 5; ++i) {
//         cout << "### ROUND " << i << " ###" << endl;

//         // Player 1 turn
//         p1.rollDice(); // Let's say it's 4.
//         // p1.placeRoad({5, 6}, board);
//         p1.endTurn();

//         // Player 2 turn
//         p2.rollDice(); // Let's say it's 9.
//         p2.endTurn();

//         // Player 3 turn
//         p3.rollDice(); // Let's say it's 3.
//         p3.endTurn();

//         // Player 1 turn
//         p1.rollDice(); // Let's say it's 6.
//         p1.trade(p2, "wood", "brick", 1, 1);
//         p1.endTurn();

//         // Player 2 turn
//         p2.rollDice(); // Let's say it's 9.
//         std::shared_ptr<ariel::DevelopmentCard> card = std::make_shared<ariel::VictoryPointCard>();
//         p2.buyDevelopmentCard(card);
//         p2.endTurn();

//         // Print points of each player
//         p1.printPoints();
//         p2.printPoints();
//         p3.printPoints();

//         // Check for a winner
//         if (p1.getPoints() >= 10) {
//             cout << "Winner: " << p1.getName() << endl;
//             break;
//         } else if (p2.getPoints() >= 10) {
//             cout << "Winner: " << p2.getName() << endl;
//             break;
//         } else if (p3.getPoints() >= 10) {
//             cout << "Winner: " << p3.getName() << endl;
//             break;
//         }

//         cout << endl;
//     }

//     return 0;
// }

// Demo.cpp

// Demo.cpp

#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
#include "development_card.hpp"
#include "resource.hpp"

using namespace std;
using namespace ariel;

int main() {
    cout << "#### START GAME ####" << endl;

    // Create players
    Player p1("Yossi");
    Player p2("Amit");
    Player p3("Dana");

    // Create Catan game instance
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
    catan.placeSecondSettlement(p3, 16, 26, board); // Settlement at 16, Road from 16 to 18
    cout << "\n";

    catan.placeSecondSettlement(p2, 28, 29, board); // Settlement at 28, Road from 28 to 30
    cout << "\n";

    catan.placeSecondSettlement(p1, 44, 45, board); // Settlement at 43, Road from 43 to 45
    cout << "\n";

    // Simulate fewer game turns to speed up the process
    for (int i = 1; i <= 5; ++i) {
        cout << "### ROUND " << i << " ###" << endl;

        // Player 1 turn
        p1.rollDice(); // Let's say it's 4.
        // p1.placeRoad({"Forest", "Hills"}, {5, 6}, board);
        p1.endTurn();

        // Player 2 turn
        p2.rollDice(); // Let's say it's 9.
        p2.endTurn();

        // Player 3 turn
        p3.rollDice(); // Let's say it's 3.
        p3.endTurn();

        // Player 1 turn
        p1.rollDice(); // Let's say it's 6.
        p1.trade(p2, "wood", "brick", 1, 1);
        p1.endTurn();

        // Player 2 turn
        p2.rollDice(); // Let's say it's 9.
        p2.addResource(Resource::Ore, 1);
        p2.addResource(Resource::Sheep, 1);
        p2.addResource(Resource::Wheat, 1);
        p2.buyDevelopmentCard();
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

    return 0;
}