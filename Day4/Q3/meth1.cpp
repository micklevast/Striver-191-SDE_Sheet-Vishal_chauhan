
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        for(auto val:nums)cout<<val<<" ";cout<<endl;
        int len=1;
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(((nums[i]-1)==nums[i-1]))cnt++;
            else if((nums[i]==nums[i-1]) ){
                // if same consecutive number than need not to increse count of distinct consecutive  number
            }
            else{
                len=max(len,cnt);
                cnt=1;
            }
        }
        len=max(len,cnt);
        return len;
    }
};