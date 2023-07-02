#include<bits/stdc++.h>
bool detect(vector<int> adj[],vector<int> &visited,int i,int parent){
    // dfs
    visited[i]=true;
    for(auto val:adj[i]){
        if(!visited[val]){
            // visited[val]=true;
            if(detect(adj,visited,val,i))
            return true;

        }
        else if(val!=parent){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    // bfs
    vector<int> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(detect(adj,visited,i,-1))return "Yes";
        }
    }
    return "No";
}
