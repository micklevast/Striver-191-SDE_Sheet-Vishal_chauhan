#include <bits/stdc++.h>
using namespace std;

// getting TL over leetcode has to be optimised.
// SC: O(((m+n)))
// TC: O(2^(m+n))
class Solution {
public:
    void find(int r,int c,int m,int n,int &ans){
        if(r==m && c==n)ans++;
        if(r+1<=m)
        find(r+1,c,m,n,ans);
        if(c+1<=n)
        find(r,c+1,m,n,ans);
    }
    int uniquePaths(int m, int n) {
        int ans=0;
        find(1,1,m,n,ans);
        return ans;
    }
};