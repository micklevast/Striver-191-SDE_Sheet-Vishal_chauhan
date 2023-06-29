#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], vector<bool>& vis, vector<bool>& helper, int i) {
    vis[i] = true;
    helper[i] = true;

    for (auto ngh : adj[i]) {
        if (!vis[ngh]) {
            if (dfs(adj, vis, helper, ngh))
                return true;
        } else if (helper[ngh]) {
            return true;
        }
    }

    helper[i] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    vector<int> adj[n + 1];
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i].first].push_back(edges[i].second); // directed graph
    }

    vector<bool> visited(n + 1, false);
    vector<bool> helper(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(adj, visited, helper, i))
                return true;
        }
    }

    return false;
}
