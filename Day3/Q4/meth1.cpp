#include <bits/stdc++.h>
using namespace std;
// TC: O(N*log(n)) and SC: O(N)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto val:nums){
            mp[val]++;
        }
        vector<int> ans;
        int n=nums.size();
        for(auto val:mp){
            if(val.second>n/3)ans.push_back(val.first);
        }
        return ans;
    }
};