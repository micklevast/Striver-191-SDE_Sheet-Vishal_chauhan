#include <bits/stdc++.h>
using namespace std;
// O(n)  and O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 1){
            return {nums[0]};
        }
        if(nums.size() == 2 && nums[0] != nums[1]){
            return {nums[0], nums[1]};
        }
        sort(nums.begin(),nums.end());
        unordered_set<int> set; //to avoid duplicacy;
        vector<int> ans;
        int n=nums.size();
        int c=1;

        for(int i=1;i<n;i++){
            // cout<<"i:"<<i<<endl;
            if(nums[i]==nums[i-1])c++;
            else{
                // cout<<"setted :"<<1<<endl;
                c=1;
            }
            if(c>n/3){
                    // cout<<"founded: c"<<c<<"  at:"<<i  <<endl;
                    set.insert(nums[i]);
            }
        }
        for(auto val:set){
            ans.push_back(val);
        }
        return ans;
    }
};