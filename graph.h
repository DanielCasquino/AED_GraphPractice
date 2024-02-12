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
};