#include<bits/stdc++.h>
using namespace std;


// here i have used an extra space of  SC:(r+c)
// TC:(r*c) -->r*c for traversing and (r+c) for to update that row and column

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        unordered_set<int> row,col;


        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                // if paricular row=i and column=j is zero then just insert them into paricular set 
                // for to remember which r and c has to set to 0
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        // updating  the original matrix
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(row.count(i)>0 || col.count(j)>0){
                    matrix[i][j]=0;
                }
            }
        }

    }
};