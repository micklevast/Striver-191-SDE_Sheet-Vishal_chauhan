
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }

        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]-1)>0){
                mp[nums[i]]=0;
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]){
                int j=0;int cnt=0;
                while(mp.count(nums[i]+j)>0){
                    j++;cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};