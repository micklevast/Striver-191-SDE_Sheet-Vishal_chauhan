#include<bits/stdc++.h>
using namespace std;

// here i have used an extra space of  SC:numRows*(sum of 1 to numRows)=n*n
// TC=SC

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> pasTri(numRows) ;
       for(int i=0;i<numRows;i++){
           pasTri[i].resize(i+1,1); //making the size of paricular row to it maximum size of pascal row 
                                    //and filled all with 1
            for(int j=1;j<i;j++){
                pasTri[i][j]=pasTri[i-1][j]+pasTri[i-1][j-1];
            }
       }
       
       return pasTri;
    }
};

