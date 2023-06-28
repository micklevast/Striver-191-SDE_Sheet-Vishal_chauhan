#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<int> adj[],int i,vector<int> &ans,vector<bool> &vis){
        vis[i]=true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int fnt=q.front();q.pop();
            ans.push_back(fnt);
            for(auto ngh:adj[fnt]){
                if(!vis[ngh]){
                    vis[ngh]=true;
                    q.push(ngh);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<bool> visited(V,false);
        // for(int i=0;i<V;i++){
        //     if(!visited[i]){
                bfs(adj,0,ans,visited);
        //     }
        // }
        return ans;
    }
};