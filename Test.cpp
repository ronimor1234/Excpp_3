//ID: 208018028, Mail: ronimordechai70@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
using namespace ariel;

TEST_CASE("Catan game initialization") {
    using namespace ariel;

    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");
    Player p4("Dave");

    SUBCASE("Catan game initialization with exactly 3 players") {
        Catan game(p1, p2, p3);
        CHECK(game.getPlayers().size() == 3);
        CHECK(game.getPlayers()[0].getName() == "Alice");
        CHECK(game.getPlayers()[1].getName() == "Bob");
        CHECK(game.getPlayers()[2].getName() == "Charlie");
    }

    SUBCASE("Catan game throws with more than 3 players") {
        CHECK_THROWS_AS(Catan(p1, p2, p3, p4), std::invalid_argument);
    }

    SUBCASE("Catan initializes with players having the same names") {
        Player p4("Alice");
        Player p5("Alice");
        CHECK_NOTHROW(Catan(p4, p5, p2)); // The game allows players with the same name
    }

    SUBCASE("Initial game resource is correct") {
        Catan game(p1, p2, p3);
        // Verify initial resources or state if applicable
        CHECK(p1.getResource(Resource::Ore) == 0);
        CHECK(p1.getResource(Resource::Brick) == 0);
        CHECK(p1.getResource(Resource::Wheat) == 0);
        CHECK(p1.getResource(Resource::Wood) == 0);
        CHECK(p1.getResource(Resource::Sheep) == 0);

        CHECK(p2.getResource(Resource::Ore) == 0);
        CHECK(p2.getResource(Resource::Brick) == 0);
        CHECK(p2.getResource(Resource::Wheat) == 0);
        CHECK(p2.getResource(Resource::Wood) == 0);
        CHECK(p2.getResource(Resource::Sheep) == 0);

        CHECK(p3.getResource(Resource::Ore) == 0);
        CHECK(p3.getResource(Resource::Brick) == 0);
        CHECK(p3.getResource(Resource::Wheat) == 0);
        CHECK(p3.getResource(Resource::Wood) == 0);
        CHECK(p3.getResource(Resource::Sheep) == 0);
    }
}

TEST_CASE("Initial placement of settlements and roads in the setup") {
    Board board; // Initialize the game board
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");
    Catan game(p1, p2, p3);

    SUBCASE("Place initial settlement and road for each player") {
        game.placeInitialSettlement(p1, 1, 2, board);
        game.placeInitialSettlement(p2, 4, 5, board);
        game.placeInitialSettlement(p3, 7, 8, board);

        // Check that the settlements are correctly placed
        CHECK(p1.hasSettlement(1));
        CHECK(p2.hasSettlement(4));
        CHECK(p3.hasSettlement(7));

        // Check that the roads are correctly placed
        CHECK(p1.hasRoad(1,2));
        CHECK(p2.hasRoad(4,5));
        CHECK(p3.hasRoad(7,8));

        // Check that the settlements are correctly placed on the board
        CHECK(board.isPlaceOccupied(1));
        CHECK(board.isPlaceOccupied(4));
        CHECK(board.isPlaceOccupied(7));
    }

    SUBCASE("Place second settlement and road for each player") {
        // Place second settlement and road for each player
        game.placeSecondSettlement(p1, 10, 11, board);
        game.placeSecondSettlement(p2, 13, 14, board);
        game.placeSecondSettlement(p3, 16, 17, board);

        // Check that the settlements are correctly placed
        CHECK(p1.hasSettlement(10));
        CHECK(p2.hasSettlement(13));
        CHECK(p3.hasSettlement(16));

        // Check that the roads are correctly placed
        CHECK(p1.hasRoad(10,11));
        CHECK(p2.hasRoad(13,14));
        CHECK(p3.hasRoad(16,17));

        // Check that the settlements are correctly placed on the board
        CHECK(board.isPlaceOccupied(10));
        CHECK(board.isPlaceOccupied(13));
        CHECK(board.isPlaceOccupied(16));

        // Check if the player gets his recource according to the last settlement
        CHECK(p1.getResource(Resource::Ore) == 1);
        CHECK(p1.getResource(Resource::Brick) == 1);
        CHECK(p1.getResource(Resource::Wheat) == 1);
        CHECK(p1.getResource(Resource::Wood) == 0);
        CHECK(p1.getResource(Resource::Sheep) == 0);

        CHECK(p2.getResource(Resource::Ore) == 0);
        CHECK(p2.getResource(Resource::Brick) == 0);
        CHECK(p2.getResource(Resource::Wheat) == 0);
        CHECK(p2.getResource(Resource::Wood) == 1);
        CHECK(p2.getResource(Resource::Sheep) == 2);

        CHECK(p3.getResource(Resource::Ore) == 0);
        CHECK(p3.getResource(Resource::Brick) == 1);
        CHECK(p3.getResource(Resource::Wheat) == 0);
        CHECK(p3.getResource(Resource::Wood) == 0);
        CHECK(p3.getResource(Resource::Sheep) == 0);
    }
}

TEST_CASE("Rolling dice") {
    Board board; // Initialize the game board
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Charlie");
    Catan game(p1, p2, p3);

    // Set up initial placements (as shown in the previous example)

    SUBCASE("Rolling dice with a non-7 roll") {
        game.placeInitialSettlement(p1, 25, 24, board);
        game.placeSecondSettlement(p1, 10, 11, board);
        game.rollDice(p1);

        // Check that resources are distributed correctly
        if(game.getLastRoll() == 10){
            CHECK(p1.getResource(Resource::Wood) == 0);
            CHECK(p1.getResource(Resource::Sheep) == 0);
            CHECK(p1.getResource(Resource::Wheat) == 0);
            CHECK(p1.getResource(Resource::Brick) == 1);
            CHECK(p1.getResource(Resource::Ore) == 1); 
        }

        if(game.getLastRoll() == 6){
            CHECK(p1.getResource(Resource::Wood) == 0);
            CHECK(p1.getResource(Resource::Sheep) == 0);
            CHECK(p1.getResource(Resource::Wheat) == 0);
            CHECK(p1.getResource(Resource::Brick) == 1);
            CHECK(p1.getResource(Resource::Ore) == 0); 
        }

        if(game.getLastRoll() == 12){
            CHECK(p1.getResource(Resource::Wood) == 0);
            CHECK(p1.getResource(Resource::Sheep) == 0);
            CHECK(p1.getResource(Resource::Wheat) == 1);
            CHECK(p1.getResource(Resource::Brick) == 0);
            CHECK(p1.getResource(Resource::Ore) == 0); 
        }

        if(game.getLastRoll() == 8){
            CHECK(p1.getResource(Resource::Wood) == 0);
            CHECK(p1.getResource(Resource::Sheep) == 0);
            CHECK(p1.getResource(Resource::Wheat) == 0);
            CHECK(p1.getResource(Resource::Brick) == 0);
            CHECK(p1.getResource(Resource::Ore) == 1); 
        }

        if(game.getLastRoll() == 3){
            CHECK(p1.getResource(Resource::Wood) == 1);
            CHECK(p1.getResource(Resource::Sheep) == 0);
            CHECK(p1.getResource(Resource::Wheat) == 0);
            CHECK(p1.getResource(Resource::Brick) == 0);
            CHECK(p1.getResource(Resource::Ore) == 0); 
        }
        
        // Check that the correct messages are printed
        std::ostringstream output;
        game.rollDice(p1); // Roll again to check output
        CHECK(output.str().find("A 7 was rolled! The robber will be moved.") == std::string::npos); // Should not find this message
    }
    SUBCASE("Rolling dice with numbers no more then 12") {
        // Roll the dice for Alice
        game.rollDice(p1);

        // Check that the last rolled number is between 2 and 12
        int lastRoll1 = game.getLastRoll();
        CHECK(lastRoll1 <= 12);

        // Roll the dice for Bob
        game.rollDice(p2);

        // Check that the last rolled number is between 2 and 12
        int lastRoll2 = game.getLastRoll();
        CHECK(lastRoll2 <= 12);

        // Roll the dice for Charlie
        game.rollDice(p3);

        // Check that the last rolled number is between 2 and 12
        int lastRoll3 = game.getLastRoll();
        CHECK(lastRoll3 <= 12);
        }
}

TEST_CASE("Update settlement to a city") {
    Board board; // Initialize the game board
    Player p1("Yossi");
    Player p2("Amit");
    Player p3("Dana");
    Catan game(p1, p2, p3);

    SUBCASE("Adding cities") {
        game.placeInitialSettlement(p1, 41, 42, board);
        game.placeInitialSettlement(p2, 26, 27, board);
        game.placeInitialSettlement(p3, 14, 15, board);

        game.placeSecondSettlement(p1, 44, 45, board);
        game.placeSecondSettlement(p2, 28, 29, board);
        game.placeSecondSettlement(p3, 11, 10, board);

        p1.addResource(Resource::Ore, 3);
        p1.addResource(Resource::Wheat, 2);
        int cityPoint1 = 41;
        game.addCityToPlayer(p1, cityPoint1, board);

        p2.addResource(Resource::Ore, 3);
        p2.addResource(Resource::Wheat, 2);
        int cityPoint2 = 26;
        game.addCityToPlayer(p2, cityPoint2, board);

        p3.addResource(Resource::Ore, 3);
        p3.addResource(Resource::Wheat, 2);
        int cityPoint3 = 11;
        game.addCityToPlayer(p3, cityPoint3, board);

        // Check if there is a city at the specified points
        bool foundCity41 = false;
        bool foundCity26 = false;
        bool foundCity11 = false;

        for (const auto& settlement : board.getSettlements()) {
            if (settlement.getPoint() == 41 && settlement.getIsCity()) {
                foundCity41 = true;
            }
            if (settlement.getPoint() == 26 && settlement.getIsCity()) {
                foundCity26 = true;
            }
            if (settlement.getPoint() == 11 && settlement.getIsCity()) {
                foundCity11 = true;
            }
        }

        CHECK(foundCity41);
        CHECK(foundCity26);
        CHECK(foundCity11);

        //check the points after the adding city
        CHECK(p1.getPoints()== 3);
        CHECK(p2.getPoints()== 3);
        CHECK(p3.getPoints()== 3);
    }

    // SUBCASE("Adding settlement") {
    //     // First, add a settlement for Bob
    //     game.placeInitialSettlement(p2, 3, 4, board);

    //     // Upgrade the settlement to a city
    //     game.addCityToPlayer(p2, 3, board);

    //     // Verify that the city is added correctly
    //     CHECK(board.hasSettlementOrCity(3, p2.getName()));
    //     CHECK(board.hasSettlementOrCity(4, p2.getName()));
    //     CHECK(board.hasCity(3, p2.getName()));

    //     // Check that the player's resources are correctly deducted
    //     CHECK(p2.getResource(Resource::Ore) == 0);
    //     CHECK(p2.getResource(Resource::Ore) == 0);
    //     CHECK(p2.getResource(Resource::Ore) == 0);
    //     CHECK(p2.getResource(Resource::Ore) == 0);
    //     CHECK(p2.getResource(Resource::Ore) == 0);

    //     // Verify that a city can't be added at the same place again
    //     game.addCityToPlayer(p2, 3, board);
    //     CHECK(board.hasCity(3, p2.getName()));
    // }
}


