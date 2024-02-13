#include <iostream>
#include "graph.h"

void cl()
{
    std::cout << std::endl
              << std::endl;
}

void traversalTests()
{
    std::cout << "--------START OF BFS AND DFS TEST--------" << std::endl;

    auto g1 = new Graph(5);
    g1->addEdge(0, 1);
    g1->addEdge(1, 2);
    g1->addEdge(2, 3);
    g1->addEdge(2, 4);
    g1->BFS(0); // BFS with 0 as starting vertex, should output [ 0 1 2 3 4 ]

    cl();

    auto g2 = new Graph(6);
    g2->addEdge(0, 2); // Add 2 first to test if it prints out before 1
    g2->addEdge(0, 1); //     1 - 3
    g2->addEdge(1, 3); //   /     | \ 
    g2->addEdge(2, 4); // 0       |  5
    g2->addEdge(3, 4); //   \     | /
    g2->addEdge(3, 5); //     2 - 4
    g2->addEdge(4, 3);
    g2->BFS(0); // BFS with 0 as starting vertex, should output [ 0 2 1 3 4 5 ]
    // 2 does print before 1 :)

    cl();

    g2->BFS(3); // BFS with 3 as starting vertex, should output [ 3 4 5 ]

    cl();

    auto g3 = new Graph(16);
    g3->addEdge(0, 1);
    g3->addEdge(0, 2);
    g3->addEdge(0, 3);

    g3->addEdge(1, 4);
    g3->addEdge(4, 5);
    g3->addEdge(5, 6);
    g3->addEdge(6, 7);

    g3->addEdge(2, 8);
    g3->addEdge(8, 9);
    g3->addEdge(9, 10);
    g3->addEdge(10, 11);

    g3->addEdge(3, 12);
    g3->addEdge(12, 13);
    g3->addEdge(13, 14);
    g3->addEdge(14, 15);

    //     1 - 4 - 5 - 6 - 7
    //   /
    // 0 - 2 - 8 - 9 - 10 - 11
    //   \ 
    //     3 - 12 - 13 - 14 - 15

    g3->DFS(0); // DFS with 0 as starting vertex, should output [ 0 3 12 13 14 15 2 8 9 10 11 1 4 5 6 7 ]
    // It did not start with 1 after 0, even though 1 was inserted first
    // This is because of FILO handling:
    // For each neighbour, push it into the stack: 1, 2, 3

    // STACK
    // 3
    // 2
    // 1

    // Therefore it will start with the last inserted neighbour

    cl();

    g3->BFS(0); // BFS with 0 as starting vertex, should output [ 0 1 2 3 4 8 12 5 9 13 6 10 14 7 11 15 ]

    std::cout << std::endl
              << "--------END OF BFS AND DFS TEST--------" << std::endl;
    cl();
}

void cycleDetectionTests()
{
    // Pretty self-explanatory stuff
    std::cout << "--------START OF CYCLE DETECTION TEST--------" << std::endl;

    auto g1 = new Graph(5);
    g1->addEdge(0, 1); //    1 - -
    g1->addEdge(0, 2); //   /    |
    g1->addEdge(0, 3); // 0 - 2  |
    g1->addEdge(3, 4); //   \    |
    g1->addEdge(4, 1); //    3 - 4
    std::cout << std::boolalpha << g1->hasCycle();

    cl();

    auto g2 = new Graph(6);
    g2->addEdge(0, 1);
    g2->addEdge(1, 2);
    g2->addEdge(2, 3);
    g2->addEdge(3, 4);
    g2->addEdge(4, 5); // 0 - 1 - 2 - 3 - 4 - 5
    std::cout << std::boolalpha << g2->hasCycle();

    std::cout << std::endl
              << "--------END OF CYCLE DETECTION TEST--------" << std::endl;
    cl();
}

void bipartiteTests()
{
    std::cout << "--------START OF BIPARTITE TEST--------" << std::endl;

    auto g1 = new Graph(6);
    g1->addEdge(0, 1);
    g1->addEdge(1, 2);
    g1->addEdge(2, 3);
    g1->addEdge(3, 4);
    g1->addEdge(4, 5);
    std::cout << std::boolalpha << g1->isBipartite(); // Should output true

    cl();

    auto g2 = new Graph(6);
    g2->addEdge(0, 1);                                //         3
    g2->addEdge(1, 2);                                //       / |
    g2->addEdge(1, 3);                                // 0 - 1 - 2
    g2->addEdge(2, 3);                                //
    std::cout << std::boolalpha << g2->isBipartite(); // Should output false

    std::cout << std::endl
              << "--------END OF BIPARTITE TEST--------" << std::endl;
    cl();
}

int main()
{
    traversalTests();
    cycleDetectionTests();
    bipartiteTests();
    return 0;
}
