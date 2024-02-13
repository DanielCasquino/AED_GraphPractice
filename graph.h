#pragma once

#include <list>
#include <vector>
#include <queue>
#include <stack>

class Graph
{
    int v; // Number of vertices

    std::vector<std::list<int>> adjacencyList;
    // std::vector  std::list
    // VERTEX       NEIGHBOURS
    // 0            1
    // 1            2
    // 2            3, 4
    // 3
    // 4

public:
    Graph(int _v) : v(_v)
    {
        adjacencyList.resize(v);
    }

    void addEdge(int first, int second)
    {
        adjacencyList[first].push_back(second); // Adds second as a neighbour of first
    }

    void BFS(int startingVertex)
    {
        std::vector<bool> visitedVertex(v, false); // Vec will hold v bools initialized to false, i.e no vertex has been visited yet
        std::queue<int> queue;                     // Queue for BFS traversal

        queue.push(startingVertex);           // Add first vertex to queue, we'll need it to push its neighbours too
        visitedVertex[startingVertex] = true; // Mark starting vertex as visited

        std::cout << "[ ";
        while (queue.empty() == false)
        {
            auto currentVertex = queue.front(); // We take the first vertex in the queue
            std::cout << currentVertex << " ";  // Display its info
            queue.pop();                        // Remove it

            for (auto neighbour : adjacencyList[currentVertex]) // For each neighbour our current vertex has
            {
                if (visitedVertex[neighbour] == false) // If we still haven't visited this neighbour
                {
                    visitedVertex[neighbour] = true; // Mark neighbour as visited
                    queue.push(neighbour);           // Add neighbour to queue
                }
            }
        }
        std::cout << ']';
    }

    void DFS(int startingVertex)
    {
        std::vector<bool> visitedVertex(v, false); // Vec will hold v bools initialized to false, i.e no vertex has been visited yet
        std::stack<int> stack;                     // Stack for DFS traversal

        stack.push(startingVertex);           // Place first neighbour on top, we'll need it to push its neighbours too
        visitedVertex[startingVertex] = true; // Mark starting vertex as visited

        std::cout << "[ ";
        while (stack.empty() == false)
        {
            auto currentVertex = stack.top();  // We take the top vertex
            std::cout << currentVertex << " "; // Display its info
            stack.pop();                       // Remove it

            for (auto neighbour : adjacencyList[currentVertex]) // For each neighbour our current vertex has
            {
                if (visitedVertex[neighbour] == false) // If we still haven't visited this neighbour
                {
                    visitedVertex[neighbour] = true; // Mark neighbour as visited
                    stack.push(neighbour);           // Place neighbour on top
                }
            }
        }
        std::cout << ']';
    }

    bool hasCycle()
    {
        // LOGIC BEFORE IMPLEMENTATION:
        // Visit vertices with BFS, mark them as visited. If at any point we reach a visited vertex, return true.

        std::vector<bool> visitedVertex(v, false);
        std::queue<int> queue;

        queue.push(0);           // Add first vertex to queue, no input this time so first vertex is 0
        visitedVertex[0] = true; // Mark starting vertex as visited

        while (queue.empty() == false)
        {
            auto currentVertex = queue.front(); // We take the first vertex in the queue
            queue.pop();                        // Remove it

            for (auto neighbour : adjacencyList[currentVertex]) // For each neighbour our current vertex has
            {
                if (visitedVertex[neighbour] == false) // If we still haven't visited this neighbour
                {
                    visitedVertex[neighbour] = true; // Mark neighbour as visited
                    queue.push(neighbour);           // Add neighbour to queue
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isBipartite()
    {
        // PRE-IMPLEMENTATION LOGIC:
        // A graph is bipartite if we can paint all vertices in two diferent colors such that no two adjacent vertices are of the same color.
        // Traverse all vertices with BFS. Paint the first vertex red before starting.
        // For each neighbour, if they have not been visited, paint them the opposite color. Mark as visited and add them to queue.
        // If they have been visited, check for color. If it's different from the current vertex color, all good. Else return false.

        std::vector<bool> visitedVertex(v, false);
        std::vector<bool> coloredVertex(v, false);
        std::queue<int> queue;

        queue.push(0);           // Add first vertex to queue, no input this time so first vertex is 0
        visitedVertex[0] = true; // Mark starting vertex as visited
        coloredVertex[0] = true; // Paint it red (true)

        while (queue.empty() == false)
        {
            auto currentVertex = queue.front(); // We take the first vertex in the queue
            queue.pop();                        // Remove it

            for (auto neighbour : adjacencyList[currentVertex]) // For each neighbour our current vertex has
            {
                if (visitedVertex[neighbour] == false) // If we still haven't visited this neighbour
                {
                    visitedVertex[neighbour] = true;                          // Mark neighbour as visited
                    coloredVertex[neighbour] = !coloredVertex[currentVertex]; // Paint it the opposite color
                    queue.push(neighbour);                                    // Add neighbour to queue
                }
                else // If it has already been visited (and painted)
                {
                    if (coloredVertex[neighbour] == coloredVertex[currentVertex]) // If it's the same color
                    {
                        return false; // Not bipartite :(
                    }
                }
            }
        }
        return true; // YYYEAAA
    }
};