#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // We need to know the min-weight each time, so use a priority_queue
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // min heap

        // If we need to know which edges are there in MST, then use vector<pair<int, int>> mst;
        vector<pair<int, int>> mst;
        
        // Minimum sum value of MST
        int sum = 0;
        pq.push({0, {0, -1}}); // {weight, {node, parent}}
        vector<int> visited(V, 0);

        // Traverse the graph level-wise and check for the minimum weight possible neighbor
        while (!pq.empty()) {
            auto fnt = pq.top();
            int node = fnt.second.first;
            int parent = fnt.second.second;
            int weight = fnt.first;
            pq.pop();

            // If node is already visited, skip it
            if (visited[node])
                continue;

            visited[node] = 1;
            sum += weight;
            mst.push_back({node, parent});
            
            for (auto neighbor : adj[node]) {
                int tempNode = neighbor[0];
                int tempWeight = neighbor[1];
                // If neighbor is not visited
                if (!visited[tempNode]) {
                    pq.push({tempWeight, {tempNode, node}});
                }
            }
        }
        
        return sum;
    }
};
