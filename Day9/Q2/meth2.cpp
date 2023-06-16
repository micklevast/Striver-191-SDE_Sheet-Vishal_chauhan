#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void find(vector<int> nums,set<vector<int>>&ans,int idx,vector<int>& vec){
        if(idx==nums.size()){
            vector<int>v=vec;
            sort(v.begin(),v.end());
            ans.insert(v);
            return;
        }
        vec.push_back(nums[idx]);
        find(nums,ans,idx+1,vec);
        vec.pop_back();
        find(nums,ans,idx+1,vec);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> vec;
        int i=0;
        find(nums,ans,i,vec);
        vector<vector<int>> a;
        for(auto val:ans){
            a.push_back(val);
        }
        return a;
    }
};