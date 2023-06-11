#include <bits/stdc++.h>
using namespace std;

// TC= O(N^2)

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int maxLen=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=A[i];int j=i+1;
            for(;j<n;j++){
                if(sum==0)maxLen=max(maxLen,j-i);
                sum+=A[j];
            }
            if(sum==0)maxLen=max(maxLen,j-i);
        }
        return maxLen;
    }
};