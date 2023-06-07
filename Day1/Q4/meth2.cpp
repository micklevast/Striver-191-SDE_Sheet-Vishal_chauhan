#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        for(auto val:nums){
            sum+=val;
            if(sum<0){
                maxi=max(maxi,sum);
                sum=0;
            }
            else{
                
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};