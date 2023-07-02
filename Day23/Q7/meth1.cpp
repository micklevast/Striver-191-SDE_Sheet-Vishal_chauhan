#include<bits/stdc++.h>
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<int> adj[],vector<int>&vis,int node,stack<int>& q){
	    vis[node]=1;
	    for(auto ngh:adj[node]){
	        if(vis[ngh]==0){
	            dfs(adj,vis,ngh,q);
	        }
	    }
	    q.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> visited(V,0);
	    vector<int> ans;
	    stack<int> qAns;
	   // using dfs
	   for(int i=0;i<V;i++){
	       if(!visited[i]){
	           dfs(adj,visited,i,qAns);
	       }
	   }
	   while(!qAns.empty()){
	       ans.push_back(qAns.top());
	       qAns.pop();
	   }

	   return ans;
	}
};