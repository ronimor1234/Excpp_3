//ID: 208018028, Mail: ronimordechai70@gmail.com
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"

using namespace std;
using namespace ariel;

int main() {
    cout << "Starting a round of Catan...\n";

    // Create players
    Player p1("Yossi");
    Player p2("Amit");
    Player p3("Dana");
 
    Catan catan(p1, p2, p3);

    cout << "\nStarting the game...\n";

    // Starting the game. Every player places two settlements and two roads.
    catan.chooseStartingPlayer();   
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

    //revers order
    // Second settlements - the third player
    catan.placeSecondSettlement(p3, 11, 12, board); // Settlement at 16, Road from 16 to 18
    cout << "\n";

    // Second settlements - the second player
    catan.placeSecondSettlement(p2, 28, 29, board); // Settlement at 28, Road from 28 to 30
    cout << "\n";

    // Second settlements - the first player
    catan.placeSecondSettlement(p1, 44, 45, board); // Settlement at 43, Road from 43 to 45
    cout << "\n";

    // Example: Players take turns
    for (int turn = 1; turn <= 3; ++turn) {
        cout << "\n### TURN " << turn << " ###\n";

        // Player 1 turn
        if (turn == 1) {
            catan.rollDice(p1);
            int settlementPoint1= 41;
            int roadPoint1= 40;
            p1.placeRoad(settlementPoint1, roadPoint1, board);
            p1.endTurn();
        }

        // Player 2 turn
        else if (turn == 2) {
            catan.rollDice(p2);
            int settlementPoint2= 26;
            int roadPoint2= 25;
            p2.placeRoad(settlementPoint2, roadPoint2, board);
            p2.endTurn();
        }

        // Player 3 turn
        else if (turn == 3) {
            catan.rollDice(p3);
            int settlementPoint3= 11;
            int roadPoint3= 10;
            p3.placeRoad(settlementPoint3, roadPoint3, board);
            p3.endTurn();
        }

        cout << "\nPlayer 1's status after turn " << turn << ":\n";
        p1.printStatus();

        cout << "\nPlayer 2's status after turn " << turn << ":\n";
        p2.printStatus();

        cout << "\nPlayer 3's status after turn " << turn << ":\n";
        p3.printStatus();
    }

    // End of the round
    cout << "\nEnd of the round.\n";

    return 0;
}
