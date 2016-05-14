// See the task in main.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <list>

#define DISTANCE 6

std::vector<int> bfs (std::vector<std::list<int> > graph, int graph_size, int start)
{
		// Create arrays to keep distances and to mark visited nodes
        std::vector<bool> visited (graph_size + 1);
		std::vector<int>  distance (graph_size + 1);
		// Set default values
        for(int i = 0; i <= graph_size; i++)
		{
            distance[i] = -1;
            visited[i] = false;
        }
        
        std::queue<int> queue;
        
        visited[start]  = true;
        distance[start] = 0;

        queue.push(start);
        while (!queue.empty())
		{
            int current_vert = queue.front();
            queue.pop();
            std::list<int> lst = graph[current_vert];	// list of nodes, adjacent to current_vert
			// Traverse all the adjacent nodes
            for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
			{
                int adjacent = *it;
                if (!visited[adjacent])
				{
                    visited[adjacent] = true;
                    distance[adjacent] = distance[current_vert] + DISTANCE;
                    queue.push(adjacent);
                }
            }
        }
		return distance;
}

int main()
{
    int nTests = 0, nVertices = 0, nEdges = 0;
    
    std::cin >> nTests;
    for (int i = 0; i < nTests; i++)
    {
        std::cin >> nVertices >> nEdges; 
        std::vector<std::list<int> > graph;
		// Create adjacency list
        for (int i = 0; i <= nVertices; ++i)
            graph.push_back(std::list<int>());
        
		// Insert edges into adjacency list
        for (int i = 0; i < nEdges; ++i)
		{
            int x, y;
            std::cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        int start;		// start vertex
        std::cin >> start;
        
		// Calculate vector of distances
		std::vector<int> distance = bfs (graph, nVertices, start);

		// Print shortest distances from start vertex to every other vertices
		// except start vertex
        for (int i = 1; i <= nVertices; i++)
            if (i != start)
                std::cout << distance[i] << " ";
        std::cout << std::endl;
    }
}