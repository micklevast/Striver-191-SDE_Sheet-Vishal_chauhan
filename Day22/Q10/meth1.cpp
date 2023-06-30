#include<bits/stdc++.h>
// full of bfs
class Solution {
public:
    bool bfs(vector<int> adj[],int node,vector<bool> &visited,vector<int> &biColor){
        visited[node]=true;
        biColor[node]=0;
        queue<pair<int,int>> q;
        q.push({node,0});

        while(!q.empty()){
            int fnt=q.front().first;
            int color=q.front().second;
            q.pop();

            for(auto ngh:adj[fnt]){
                if(!visited[ngh]){
                    visited[ngh]=true;
                    biColor[ngh]=color==1?-1:1;
                    q.push({ngh,biColor[ngh]});
                }
                else if(biColor[ngh]!=0){
                    if(biColor[ngh]==color){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> adj[V];
        for(int i=0;i<graph.size();i++){
            for(auto ngh:graph[i]){
                adj[i].push_back(ngh);
            }
        }
        vector<int> biColor(V,0);
        // using bfs
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(adj,i,visited,biColor)==true){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};