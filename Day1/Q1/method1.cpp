#include<bits/stdc++.h>
using namespace std;

// here i have used an extra space of  SC:r*c
// TC:(r*c)*(r+c) -->r*c for traversing and (r+c) for to update that row and column


class Solution {
public:
    // filling the particular column c on getting that column=0
    void fillc(int c,vector<vector<int>>& matrix){
        int r=matrix.size();
        for(int i=0;i<r;i++){
            matrix[i][c]=0;
        }
    }
    // filling the particular row r on getting that row=0
    void fillr(int r,vector<vector<int>>& matrix){
        int c=matrix[0].size();
        for(int i=0;i<c;i++){
            matrix[r][i]=0;
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
                    fillc(j,mat);
                    fillr(i,mat);
                }
            }
        }
        // updating  the original matrix
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(mat[i][j]==0)matrix[i][j]=0;
            }
        }

    }
};