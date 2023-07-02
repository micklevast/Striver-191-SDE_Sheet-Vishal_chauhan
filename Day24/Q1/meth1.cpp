#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<vector<int>>& edges, int node, stack<int>& st, vector<int>& visited) {
    visited[node] = 1;
    for (int ngh : edges[node]) {
        if (!visited[ngh]) {
            dfs(edges, ngh, st, visited);
        }
    }
    st.push(node);
}

void DFS(vector<vector<int>>& Redges, vector<int>& vis, int node, vector<int>& ans) {
    vis[node] = 1;
    for (int ngh : Redges[node]) {
        if (!vis[ngh]) {
            ans.push_back(ngh); // Add the node to the ans vector
            DFS(Redges, vis, ngh, ans);
        }
    }
}


int kosaraju(int n, vector<vector<int>>& edges)
{
        //code here
    vector<vector<int>> ans;
    stack<int> st;
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(edges, i, st, visited);
        }
    }

    vector<vector<int>> Redges(n);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int ngh : edges[i]) {
            Redges[ngh].push_back(i);
        }
    }
    int ct=0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            ct++;
            vector<int> connected_component;
            connected_component.push_back(node); // Add the node to the connected_component vector
            DFS(Redges, visited, node, connected_component);
            ans.push_back(connected_component);
        }
    }
    // return ans;
    return ct;
}
};