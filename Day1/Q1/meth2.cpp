#include<bits/stdc++.h>
using namespace std;

// here i have used an extra space of  SC:O(1)
// TC:(r*c)*(r+c) -->r*c for traversing and (r+c) for to update that row and column

class Solution {
public:
    // filling the particular column c on getting that column=0
    void fillc(int c,vector<vector<int>>& matrix){
        int r=matrix.size();
        for(int i=0;i<r;i++){
            if(matrix[i][c]!=0)
            matrix[i][c]=-1111;
        }
    }
    // filling the particular row r on getting that row=0
    void fillr(int r,vector<vector<int>>& matrix){
        int c=matrix[0].size();
        for(int i=0;i<c;i++){
            if(matrix[r][i]!=0)
            matrix[r][i]=-1111;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        vector<vector<int>> mat(r,vector<int>(c,1));
        int  i=0,j=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                // if paricular row=i and column=j is zero the we need to set that row and column to 0
                if(matrix[i][j]==0){
                    fillc(j,matrix);
                    fillr(i,matrix);
                }
            }
        }
        // updating  the original matrix
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(matrix[i][j]==-1111)matrix[i][j]=0;
            }
        }

    }
};