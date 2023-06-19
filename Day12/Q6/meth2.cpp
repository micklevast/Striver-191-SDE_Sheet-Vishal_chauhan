#include <bits/stdc++.h> 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto val:nums){
            mp[val]++;
        }
        priority_queue<pair<int,int>> pq; //maxheap
        for(auto pr:mp){
            pq.push({pr.second,pr.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};