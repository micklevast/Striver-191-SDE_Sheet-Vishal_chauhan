#include<bits/stdc++.h>

class Solution {
public:
    bool dfs(vector<int> adj[], int node, vector<bool>& visited, vector<int>& biColor, int clr) {
        visited[node] = true;
        biColor[node] = 1 - clr;
        for (auto ngh : adj[node]) {
            if (!visited[ngh]) {
                int nc = 1 - clr;
                if(!dfs(adj, ngh, visited, biColor, nc))
                return false;
            } else if (biColor[ngh] == biColor[node]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        for (int i = 0; i < graph.size(); i++) {
            for (auto ngh : graph[i]) {
                adj[i].push_back(ngh);
            }
        }
        vector<int> biColor(V, -1);
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (!dfs(adj, i, visited, biColor, 1)) {
                    return false;
                }
            }
        }
        return true;
    }
};
