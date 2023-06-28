
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        queue<int> q;
        vector<bool> visited(V,false);
        visited[0]=true;
        q.push(0);
        while(!q.empty()){
                int tp=q.front();q.pop();
                ans.push_back(tp);
                for(auto ngh:adj[tp]){
                    if(!visited[ngh])
                    {
                        visited[ngh]=true;
                        q.push(ngh);
                    }
                }
        }
        return ans;
    }
};