#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[],int i,vector<bool> &visited,vector<int> &ans){
        visited[i]=true;
        for(auto neighbour:adj[i]){
            if(!visited[neighbour]){
                // cout<<"ngh:"<<neighbour<<endl;
                // visited[neighbour]=true;
                ans.push_back(neighbour);
                dfs(adj,neighbour,visited,ans);
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        ans.push_back(0);
        vector<bool> visited(V,false);
        // visited[0]=true;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,i,visited,ans);
            }
        }
        return ans;
    }
};