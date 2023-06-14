#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len=0;
        int maxi=INT_MIN;
        for(auto val:nums){
            if(val==1)len++;
            else{
                maxi=max(maxi,len);
                len=0;
            }
        }
        maxi=max(maxi,len);
        return maxi;
    }
};