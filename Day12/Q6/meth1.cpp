#include <bits/stdc++.h> 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto val:nums){
            mp[val]++;
        }
        vector<pair<int,int>> pq;
        for(auto val:mp){
            pq.push_back({val.second,val.first});
        }
        sort(pq.begin(),pq.end());
        vector<int> ans;
        int n=pq.size()-1;
        while(k--){
            ans.push_back(pq[n].second);
            n--;
        }
        return ans;
    }
};