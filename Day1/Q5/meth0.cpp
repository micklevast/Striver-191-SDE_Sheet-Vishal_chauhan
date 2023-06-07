#include <bits/stdc++.h>
using namespace std;
// TC:O(N)
class Solution {
public:

    void sortColors(vector<int>& nums) {
        int c0=0,c1=0,c2=0;
        for(auto val:nums){
            if(val==1)c1++;
            else if(val==0)c0++;
            else c2++;
        }
        int i=0;
        while(c0-- && i<nums.size())nums[i++]=0;
        while(c1-- && i<nums.size())nums[i++]=1;
        while(c2-- && i<nums.size())nums[i++]=2;
    }
};