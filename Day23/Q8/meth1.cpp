#include<bits/stdc++.h>

// topo sort using kahn's algo (based on bfs - technique)
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> inDeg(V);
	    for(int i=0;i<V;i++){
	        for(auto ngh:adj[i]){
	            inDeg[ngh]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(inDeg[i]==0){
	            q.push(i);
	        }
	    }
	   // topo sort using bfs
	   vector<int> ans;
	    while(!q.empty()){
	        int fnt=q.front();q.pop();
	        ans.push_back(fnt);
	        for(auto ngh:adj[fnt]){
	            inDeg[ngh]--;
	            if(inDeg[ngh]==0){
	                q.push(ngh);
	            }
	        }
	    }
	    return ans;
	}
};