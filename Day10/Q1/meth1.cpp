#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void find(vector<vector<int>> &ans,vector<int> &nums,int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            find(ans,nums,i+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ans;
      int i=0;
      find(ans,nums,i);
      return ans;  
    }
};