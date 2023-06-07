#include <bits/stdc++.h>
using namespace std;

// solution is not perfect will not work for all case
class Solution
{
public:
    void backtrack(vector<int> &nums, int start, vector<vector<int>> &result)
    {
        if (start == nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i)
        {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

    bool matched(vector<int> vec1,vector<int> vec2){
        for(int  i=0;i<vec1.size();i++){
            if(vec1[i]!=vec2[i])return false;
        }
        return true;
    }
    void nextPermutation(vector<int> &nums)
    {
        vector<int> arr=nums;
        vector<int> ans=nums;
        sort(nums.begin(),nums.end());
        vector<vector<int>> all=permute(nums);
        for(int i=0;i<all.size();i++){
            if(matched(all[i],arr)){
                if(i==all.size()-1)ans=all[0];
                else ans=all[i+1];
            }
        }
        nums=ans;
    }
};