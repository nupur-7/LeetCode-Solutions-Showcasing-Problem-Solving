/*
LeetCode 1971. Find if Path Exists in Graph

This DFS approach to this question efficiently explores the graph to determine if there exists a valid path from the source to the destination node.
> Graph Representation: Represent the undirected graph using an adjacency list, where each node's neighbors are stored in a vector.
> DFS Function: Implement a DFS function to recursively traverse the graph from the source node to the destination node.
> Visited Array: Maintain a visited array to keep track of visited nodes during the DFS traversal to avoid revisiting the same node and getting stuck in cycles.
> Path Search: During DFS traversal, check if the current node is the destination node. If so, return true, indicating that a path from source to destination exists.
> Recursive Exploration: Explore each neighbor of the current node recursively using DFS, marking nodes as visited to prevent revisiting, and return true if a path is found.
*/

class Solution {
public:
    // Function to check if there exists a path from source to destination
    //(DFS)Helper Fucntion
    bool checkforpath(unordered_map<int, vector<int>> &mp, int s, int d, vector<bool> &visited) {
        // If source equals destination, a path is found
        if (s == d) {
            return true;
        }

        // If source node has already been visited, return false (to avoid cycles)
        if (visited[s] == true) {
            return false;
        }

        // Mark current node as visited
        visited[s] = true;

        // Recursively check for path from current node to destination
        for (int &node : mp[s]) {
            if (checkforpath(mp, node, d, visited) == true) {
                return true; // If path found, return true
            }
        }
        
        return false; // If no path found, return false
    }
    
    // Function to validate if there exists a path from source to destination in the graph
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Create adjacency list representation of the graph
        unordered_map<int, vector<int>> mp;
        for (vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v); // Add edge from u to v
            mp[v].push_back(u); // Add edge from v to u (undirected graph)
        }

        // Initialize visited array to keep track of visited nodes
        vector<bool> visited(n, false);

        // Check for path from source to destination
        return checkforpath(mp, source, destination, visited);
    }
};
