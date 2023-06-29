#include<bits/stdc++.h>
bool bfs(vector<int> adj[],vector<bool> &vis,int i){
    vis[i]=true;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int fnt=q.front();q.pop();
        for(auto ngh:adj[fnt]){
            if(!vis[ngh]){
                q.push(ngh);
                vis[ngh]=true;
            }
            else{
                return true;
            }
        }
    }
    return false;
}

// getting wrong over some of the testcases

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int> adj[n+1];
  for(int i=0;i<edges.size();i++){
      adj[edges[i].first].push_back(edges[i].second);
  }
  vector<bool> &visited(n+1,false);
  for(int i=1;i<n+1;i++){
      if(!visited[i]){
          if(bfs(adj,visited,i))return true;
      }
  }
  return false;
  
}