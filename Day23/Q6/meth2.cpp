#include<bits/stdc++.h>
// To detect cycles in a directed graph, you can modify the code to use a modified version of BFS called "Topological Sort." 
// If a cycle exists in a directed graph, it will have at least one node with an indegree greater than 1. 
// By performing a topological sort and checking the indegree of each node, you can detect cycles.
bool detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cnt++;

        for (int neighbor : adj[curr]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return cnt != n;  // If a cycle exists, cnt will be less than n
}
