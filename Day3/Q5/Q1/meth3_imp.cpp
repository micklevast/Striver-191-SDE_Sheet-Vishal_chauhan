#include <bits/stdc++.h>
using namespace std;

// In the worst case, the find function will explore all possible cells in the grid of size m x n.
// Therefore, the time complexity of the find function, considering memoization, is O(m * n)
// TC:O(m * n)
// SC:O((m+1)*(n+1))
class Solution {
public:
    int find(int r,int c,int m,int n,vector<vector<int>> &dp){
        if(r>m || c>n)return 0;

        if(r==m && c==n)return 1;
        if(dp[r][c]!=-1)return dp[r][c];
        int row=find(r+1,c,m,n,dp);

        int col=find(r,c+1,m,n,dp);
        dp[r][c]=row+col;
        return row+col;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return find(1,1,m,n,dp);

    }
};