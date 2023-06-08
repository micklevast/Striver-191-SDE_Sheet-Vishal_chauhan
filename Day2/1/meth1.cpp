#include <bits/stdc++.h>
using namespace std;
// TC:O(nxn)
// SC:O(nxn)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int  r=matrix.size(),c=matrix[0].size();
        vector<vector<int>> ans(r,vector<int>(c,0));
        int k=0;
        for(int i=r-1;i>=0;i--){
            for(int j=0;j<c;j++){
                ans[j][k]=matrix[i][j];
            }
            k++;
        }
        matrix=ans;
    }
};