//ID: 208018028, Mail: ronimordechai70@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
using namespace ariel;
TEST_CASE("Test placing settlement") {
    // Create players
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");

    // Create a Catan game instance
    Catan catan(p1, p2, p3);

    // Get the board of the game
    Board board = catan.getBoard();

    // Place a settlement for player p1
    SUBCASE("Player p1 places a settlement") {
        CHECK_NOTHROW(p1.placeSettlement({"Forest", "Hills"}, {5, 6}, board));
    }
}



// TEST_CASE("Test graph addition")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph1 = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph1);
    
//     ariel::Graph g2;
//     vector<vector<int>> graph2 = {
//         {0, 1, 1},
//         {1, 0, 2},
//         {1, 2, 0}};
//     g2.loadGraph(graph2);
//     ariel::Graph g3 = g1 + g2;
//     ostringstream oss;// Using std::ostringstream to capture output from operator<<
//     oss << g3; // This call the operator<< for Graph
//     CHECK(oss.str() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]\n");
    
//     ariel::Graph g4 = g3 + g1;
//     ostringstream oss1;
//     oss1 << g4;
//     CHECK(oss1.str() == "[0, 3, 1]\n[3, 0, 4]\n[1, 4, 0]\n");
    
//     ariel::Graph g5;
//     vector<vector<int>> smallGraph = {
//         {1, 0},
//         {0, 1}};
//     g5.loadGraph(smallGraph);

//     ariel::Graph g6;
//     vector<vector<int>> largeGraph = {
//         {1, 2, 0},
//         {2, 1, 3},
//         {0, 3, 1}};
//     g6.loadGraph(largeGraph);

//     CHECK_THROWS_WITH(g5 + g6, "Graphs must be the same size to add them.");
    
//     ariel::Graph g7 = g6 + g4;
//     ostringstream oss2;
//     oss2 << g7;
//     CHECK(oss2.str() == "[1, 5, 1]\n[5, 1, 7]\n[1, 7, 1]\n");

//     ariel::Graph g8;
//     vector<vector<int>> negativeGraph = {
//         {-1, -2, 0},
//         {-2, -1, -3},
//         {0, -3, -1}};
//     g8.loadGraph(negativeGraph);
//     ariel::Graph g9 = g8 + g6;
//     ostringstream oss3;
//     oss3 << g9;
//     CHECK(oss3.str() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]\n");

//     ariel::Graph g10 = g9 += 10;
//     ostringstream oss4;
//     oss4 << g10;
//     CHECK(oss4.str() == "[10, 10, 10]\n[10, 10, 10]\n[10, 10, 10]\n");

//     ariel::Graph g11 = +g10; // Unary plus
//     ostringstream oss5;
//     oss5 << g11;
//     CHECK(oss5.str() == "[10, 10, 10]\n[10, 10, 10]\n[10, 10, 10]\n");

//     ariel::Graph g12 = ++g11;
//     ostringstream oss6;
//     oss6 << g12;
//     CHECK(oss6.str() == "[11, 11, 11]\n[11, 11, 11]\n[11, 11, 11]\n");

//     ariel::Graph g13 = g12 += -11;
//     ostringstream oss7;
//     oss7 << g13;
//     CHECK(oss7.str() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]\n");

// }

// TEST_CASE("Test graph subtraction")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph1 = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph1);
    
//     ariel::Graph g2;
//     vector<vector<int>> graph2 = {
//         {0, 1, 1},
//         {1, 0, 2},
//         {1, 2, 0}};
//     g2.loadGraph(graph2);
//     ariel::Graph g3 = g1 - g2;
//     ostringstream oss;// Using std::ostringstream to capture output from operator<<
//     oss << g3; // This call the operator<< for Graph
//     CHECK(oss.str() == "[0, 0, -1]\n[0, 0, -1]\n[-1, -1, 0]\n");
    
//     ariel::Graph g4 = g3 - g1;
//     ostringstream oss1;
//     oss1 << g4;
//     CHECK(oss1.str() == "[0, -1, -1]\n[-1, 0, -2]\n[-1, -2, 0]\n");
    
//     ariel::Graph g5;
//     vector<vector<int>> smallGraph = {
//         {1, 0},
//         {0, 1}};
//     g5.loadGraph(smallGraph);

//     ariel::Graph g6;
//     vector<vector<int>> largeGraph = {
//         {1, 2, 0},
//         {2, 1, 3},
//         {0, 3, 1}};
//     g6.loadGraph(largeGraph);

//     CHECK_THROWS_WITH(g5 - g6, "Graphs must be the same size to subtract them.");
    
//     ariel::Graph g7 = g6 - g4;
//     ostringstream oss2;
//     oss2 << g7;
//     CHECK(oss2.str() == "[1, 3, 1]\n[3, 1, 5]\n[1, 5, 1]\n");

//     ariel::Graph g8;
//     vector<vector<int>> negativeGraph = {
//         {-1, -2, 0},
//         {-2, -1, -3},
//         {0, -3, -1}};
//     g8.loadGraph(negativeGraph);
//     ariel::Graph g9 = g8 - g6;
//     ostringstream oss3;
//     oss3 << g9;
//     CHECK(oss3.str() == "[-2, -4, 0]\n[-4, -2, -6]\n[0, -6, -2]\n");

//     ariel::Graph g10 = g9 -= 10;
//     ostringstream oss4;
//     oss4 << g10;
//     CHECK(oss4.str() == "[-12, -14, -10]\n[-14, -12, -16]\n[-10, -16, -12]\n");

//     ariel::Graph g11 = -g10; // Unary minus
//     ostringstream oss5;
//     oss5 << g11;
//     CHECK(oss5.str() == "[12, 14, 10]\n[14, 12, 16]\n[10, 16, 12]\n");

//     ariel::Graph g12 = --g11;
//     ostringstream oss6;
//     oss6 << g12;
//     CHECK(oss6.str() == "[11, 13, 9]\n[13, 11, 15]\n[9, 15, 11]\n");

//     ariel::Graph g13 = g12 -= -10;
//     ostringstream oss7;
//     oss7 << g13;
//     CHECK(oss7.str() == "[21, 23, 19]\n[23, 21, 25]\n[19, 25, 21]\n");

// }

// TEST_CASE("Test graph multiplication")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph);
    
//     ariel::Graph g2;
//     vector<vector<int>> weightedGraph = {
//         {0, 1, 1},
//         {1, 0, 2},
//         {1, 2, 0}};
//     g2.loadGraph(weightedGraph);
    
//     ariel::Graph g3 = g1 * g2;
//     ostringstream oss;
//     oss << g3;
//     CHECK(oss.str() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]\n");

//     ariel::Graph g4;
//     vector<vector<int>> identityMatrix = {
//         {1, 0, 0},
//         {0, 1, 0},
//         {0, 0, 1}};
//     g4.loadGraph(identityMatrix);

//     ariel::Graph g5 = g4 * g3;
//     ostringstream oss1;
//     oss1 << g5;
//     CHECK(oss1.str() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]\n");

//     ariel::Graph g6;
//     vector<vector<int>> matrix3 = {
//         {1, 2},
//         {4, 5}};
//     g6.loadGraph(matrix3);
//     CHECK_THROWS_WITH(g1 * g6, "The number of columns in the first matrix must be equal to the number of rows in the second matrix.");

//     ariel::Graph g7;
//     vector<vector<int>> negativeMatrix = {
//         {-1, -2},
//         {-3, -4}};
//     g7.loadGraph(negativeMatrix);
//     ariel::Graph g8 = g7 * g6;
//     ostringstream oss2;
//     oss2 << g8;
//     CHECK(oss2.str() == "[-9, -12]\n[-19, -26]\n");

// }

// TEST_CASE("Invalid operations")
// {
//     ariel::Graph g1;
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph);
//     ariel::Graph g2;
//     vector<vector<int>> weightedGraph = {
//         {0, 1, 1, 1},
//         {1, 0, 2, 1},
//         {1, 0, 2, 1},
//         {1, 2, 0, 1}};
//     g2.loadGraph(weightedGraph);
//     ariel::Graph g5;
//     vector<vector<int>> graph2 = {
//         {0, 1, 0, 0, 1},
//         {1, 0, 1, 0, 0},
//         {0, 1, 0, 1, 0},
//         {0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 0}};
//     g5.loadGraph(graph2);
//     CHECK_THROWS(g5 * g1);
//     CHECK_THROWS(g1 * g2);

//     // Addition of two graphs with different dimensions
//     ariel::Graph g6;
//     vector<vector<int>> graph3 = {
//         {0, 1, 0, 0, 1},
//         {1, 0, 1, 0, 0},
//         {0, 1, 0, 1, 0},
//         {0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 0}};
//     g6.loadGraph(graph3);
//     CHECK_THROWS(g1 + g6);
// }
// TEST_CASE("Test comparison operators") {
//     // Set up basic graph structures for testing
//     ariel::Graph g1;
//     vector<vector<int>> graph1 = {
//         {0, 1, 2},
//         {1, 0, 3},
//         {2, 3, 0}};
//     g1.loadGraph(graph1);

//     ariel::Graph g2;
//     vector<vector<int>> graph2 = {
//         {0, 2, 1},
//         {2, 0, 3},
//         {1, 3, 0}};
//     g2.loadGraph(graph2);

//     ariel::Graph g3;
//     vector<vector<int>> graph3 = {
//         {0, 1, 2},
//         {1, 0, 3},
//         {2, 3, 0}};
//     g3.loadGraph(graph3);

//     // Test equality operator
//     CHECK(g1 == g3);  // Same graphs, should be true
//     CHECK(g1 == g2);  // It is true becouse the other condition that say: (!(g2 > g1) && !(g1 > g2))

//     // Test inequality operator
//     CHECK_FALSE(g1 != g2);  // Becouse we get equal g1==g2. so it is false
//     CHECK_FALSE(g1 != g3);  // Same graphs, should be false

//     // Test less than operator
//     CHECK_FALSE(g1 < g2);  // They the same count of edges and the same size, so it false
//     CHECK_FALSE(g2 < g1);  // They the same count of edges and the same size, so it false

//     // Test greater than operator
//     CHECK_FALSE(g2 > g1);  // They the same count of edges and the same size, so it false
//     CHECK_FALSE(g1 > g2);  // They the same count of edges and the same size, so it false
//     // Test less than or equal to operator
//     CHECK(g1 <= g3);  // Same graphs, so it true
//     CHECK(g1 <= g2);  // g1 has fewer edges/weight, should be true

//     // Test greater than or equal to operator
//     CHECK(g3 >= g1);  // Same graphs, should be true
//     CHECK(g2 >= g1);  // g2 has more edges/weight, should be true
// }
// TEST_CASE("Test graph multiplication by scalar") {
//     // Test case 1: Multiply a graph by a positive scalar
//     SUBCASE("Positive Scalar") {
//         ariel::Graph g1;
//         vector<vector<int>> adjacencyMatrix = {
//             {0, 1, 0},
//             {1, 0, 1},
//             {0, 1, 0}};
//         g1.loadGraph(adjacencyMatrix);
//         int scalar = 2;
//         ariel::Graph result1 = g1 *= scalar;
//         ostringstream oss1;
//         oss1 << result1;
//         CHECK(oss1.str() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]\n");
//     }

//     // Test case 2: Multiply a graph by a negative scalar
//     SUBCASE("Negative Scalar") {
//         ariel::Graph g2;
//         vector<vector<int>> adjacencyMatrix = {
//             {0, 1, 0},
//             {1, 0, 1},
//             {0, 1, 0}};
//         g2.loadGraph(adjacencyMatrix);
//         int scalar = -2;
//         ariel::Graph result2 = g2 *= scalar;
//         std::ostringstream oss2;
//         oss2 << result2;
//         CHECK(oss2.str() == "[0, -2, 0]\n[-2, 0, -2]\n[0, -2, 0]\n" );
//     }

//     // Test case 3: Multiply a graph by zero
//     SUBCASE("Zero Scalar") {
//         ariel::Graph g3;
//         vector<vector<int>> adjacencyMatrix = {
//             {0, 1, 0},
//             {1, 0, 1},
//             {0, 1, 0}};
//         g3.loadGraph(adjacencyMatrix);
//         int scalar = 0;
//         ariel::Graph result3 = g3 *= scalar;
//         ostringstream oss3;
//         oss3 << result3;
//         CHECK(oss3.str() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]\n");
//     }

//     // Test case 4: Multiply a graph by a scalar when the graph is empty
//     SUBCASE("Empty Graph") {
//         ariel::Graph g4;
//         int scalar = 5;
//         ariel::Graph result4 = g4 *= scalar;
//         ostringstream oss4;
//         oss4 << result4;
//         CHECK(oss4.str() == "");
//     }
// }

