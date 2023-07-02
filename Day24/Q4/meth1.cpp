#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int m=matrix.size();
	    int n=matrix[0].size();
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e8;
	            }
	       
	        }
	    }
	    for(int k=0;k<m;k++){ //this will relax it m time
	        
    	    for(int i=0;i<m;i++){ //relaxing all the matrix value passing through fron k
    	        for(int j=0;j<n;j++){
    	            if(matrix[i][j] > (matrix[i][k]+matrix[k][j])){
    	                matrix[i][j]=matrix[i][k]+matrix[k][j];
    	            }
    	        }
    	    }
	    }
	        
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e8){
	                matrix[i][j]=-1;
	            }
	       
	        }
	    }
	}
};