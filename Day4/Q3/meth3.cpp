
#include <bits/stdc++.h>
using namespace std;
// not enough optimised but better than meth1
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }

        int ans=0;
        for(auto val:mp){
            int j=0;int cnt=0;
            while(mp.count(val.first+j)>0)cnt++;
            ans=max(ans,cnt);
        }
        return ans;
    }
};