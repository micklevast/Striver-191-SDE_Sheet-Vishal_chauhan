#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN,sum=0;
        for(auto val:nums){
            if(val>sum+val)sum=val;
            else sum+=val;

            ans=max(ans,sum);
        }
        return ans;
    }
};