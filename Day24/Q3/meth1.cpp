#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V,1e8);
        // can be implement using dfs
        dist[S]=0;
        for(int i=0;i<V-1;i++){
            for(auto vec:edges){
                int n1=vec[0];
                int n2=vec[1];
                int wgh=vec[2];
                if(dist[n1]!=1e8 && ((dist[n1]+wgh)< dist[n2])){
                    dist[n2]=dist[n1]+wgh;
                }
            }
        }
        // check weather the graph contain neg cycle
        // traversing V time  to check ,and if we further get reduce dist then there must be neg cycle
        for(auto vec:edges){
            int n1=vec[0];
            int n2=vec[1];
            int wgh=vec[2];
            if((dist[n1]+wgh)< dist[n2]){
                return {-1};
            }
        }
        return dist;
    }
};