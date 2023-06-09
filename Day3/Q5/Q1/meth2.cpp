#include <bits/stdc++.h>
using namespace std;


// getting TL over leetcode has to be optimised.
// SC: O(((m+n)))
// TC: O(2^(m+n))
class Solution {
public:
    int find(int r,int c,int m,int n){
        if(r>m || c>n)return 0;

        if(r==m && c==n)return 1;

        int row=find(r+1,c,m,n);

        int col=find(r,c+1,m,n);
        
        return row+col;
    }
    int uniquePaths(int m, int n) {

        return find(1,1,m,n);

    }
};