// Given an undirected graph consisting of nodes (labelled 1 to N) where a specific given node represents the start position
// and an edge between any two nodes is of length 6 units in the graph.

// It is required to calculate the shortest distance from start position (Node S) to all of the other nodes in the graph.

// Note 1: If a node is unreachable , the distance is assumed as -1.
// Note 2: The length of each edge in the graph is 6 units.

// Input Format

// The first line contains T, denoting the number of test cases.
// First line of each test case has two integers N, denoting the number of nodes in the graph and M,
// denoting the number of edges in the graph.
// The next lines each consist of two space separated integers x y, where x and y denote the two nodes
// between which the edge exists.
// The last line of a testcase has an integer S, denoting the starting position. 

// Output Format
// For each of T test cases, print a single line consisting of N - 1 space-separated integers, denoting the shortest
// distances of the N-1 nodes from starting position S. This will be done for all nodes same as in the order of input 1 to N.
// For unreachable nodes, print .

// Sample Input

// 2
// 4 2
// 1 2
// 1 3
// 1
// 3 1
// 2 3
// 2

//Sample Output

// 6 6 -1
// -1 6


#include <iostream>
#include <vector>
#include <queue>
#include <list>
#define DISTANCE 6

int main()
{
    int ntests, vertices, edges;
    
    std::cin >> ntests;
    for(int i = 0; i < ntests; i++)
    {
        std::cin >> vertices >> edges; 
        std::vector<std::list<int> > graph;
		// Create adjacency list
        for(int i = 0; i <= vertices; ++i)
            graph.push_back(std::list<int>());
        
		// Insert edges into adj list
        for(int i = 0; i < edges; ++i) {
            int x, y;
            std::cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
		// Create arrays to keep distances and to mark visited nodes
        int  *distance = new int[vertices + 1];
        bool *visited = new bool[vertices + 1];
        for(int i = 0; i <= vertices; i++) {
            distance[i] = -1;
            visited[i] = false;
        }
        
        std::queue<int> queue;
        
        int start;		// start vertex
        std::cin >> start;
        
        visited[start] = true;
        distance[start] = 0;
        queue.push(start);

        while (!queue.empty()) {
            int current_vert = queue.front();
            queue.pop();
            std::list<int> lst = graph[current_vert];	// list of nodes, adjacent to current_vert
			// Traverse all the adjacent nodes
            for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
                int adjacent = *it;
                if(!visited[adjacent]) {
                    visited[adjacent] = true;
                    distance[adjacent] = distance[current_vert] + DISTANCE;
                    queue.push(adjacent);
                }
            }
        }
		
		// Print shortest distances from start vertex to every other vertices
        for(int i = 1; i <= vertices; i++) {
            if (i != start) {
                std::cout << distance[i] << " ";
            }
        }
        std::cout << std::endl;
    }
}