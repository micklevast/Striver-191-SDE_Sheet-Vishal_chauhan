#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int nd=pq.top().second;
            int wgh=pq.top().first;
            pq.pop();
            
            for(auto vec:adj[nd]){
                int val=vec[1];
                int node=vec[0];
                if(dist[nd]+val < dist[node]){
                    dist[node]=dist[nd]+val;
                    pq.push({dist[node],node});
                }
            }
        }
        return dist;
    }
};