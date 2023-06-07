#include<bits/stdc++.h>
using namespace std;

// here i have used an extra space of  SC:numRows*(sum of 1 to numRows)=n*n
// TC=SC

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> pasTri(numRows) ;
       for(int i=0;i<numRows;i++){
           pasTri[i].push_back(1);
       }
       if(numRows>1)//if only one row was there then return them
       pasTri[1].push_back(1);
       else return pasTri;
       
       int j=1;
       for(int i=2;i<numRows;i++){
           int k=1;
           while(k<=j){
               pasTri[i].push_back(pasTri[i-1][k-1]+pasTri[i-1][k]);
               k++;
           }
           pasTri[i].push_back(1);
           j++;
       }
       return pasTri;
    }
};