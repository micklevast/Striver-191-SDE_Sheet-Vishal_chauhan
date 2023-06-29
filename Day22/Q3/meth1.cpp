#include<bits/stdc++.h>
bool detect(vector<int> adj[],vector<int> &visited,int i,int parent){
    // bfs
    queue<pair<int,int>> q;
    q.push({i,parent});
    visited[i]=true;
    while(!q.empty()){
        int fnt=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto val:adj[fnt]){
            if(!visited[val]){
                visited[val]=true;
                q.push({val,fnt});
            }
            else if(par!=val){
                return true;
            }
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
