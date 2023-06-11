#include <bits/stdc++.h>
using namespace std;
// TC= O(N)  and SC=O(N)
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int sum=0;
        int maxLen=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                maxLen=max(maxLen,i+1);
            }
            else if(mp.count(sum)>0){
                // if previously sum is exit in map then there is a atleast point which will go down to zero from[ 1+mp[sum] to i ]index 
                maxLen=max(maxLen,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return maxLen;
    }
};