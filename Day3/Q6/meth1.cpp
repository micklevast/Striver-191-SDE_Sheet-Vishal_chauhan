#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++){
                long long a=nums[i];
                long long b=nums[j];
                if(a>(b*2))
                ans++;
            }
        }
        return ans;
    }
};