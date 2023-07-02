#include<bits/stdc++.h>
using namespace std;
// make correct-->
vector<int>rank(101,0);
vector<int>parent(101);
int find(int X)
{
       //add code here
       if(parent[X]==X)return X;
       
       return parent[X]=find(parent[X]);
}
void unionSet(int X,int Z)
{
	//add code here.
// 	aking the union set using the rank method
    for(auto i=0;i<101;i++){
        parent[i]=i;
    }
    int parx=find(X);
    int parz=find(Z);
    if(rank[parx]==rank[parz]){
        parent[parx]=parz;
        rank[parz]++;//increase in rank
    }
    else if(rank[parx]<rank[parz]){
        // no increase in rank
        parent[parx]=parz;//smaller one will become child
    }
	else{
	    parent[parz]=parx;
	}
}