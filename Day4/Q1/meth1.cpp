#include <bits/stdc++.h>
using namespace std;
// O(N)  & O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            // at each position we check that our answer is present in mp or not if yes then simply return
            //  else push that number into mp
            if(mp.find(target-nums[i])==mp.end()){
                mp[nums[i]]=i;
            }
            else{
                return {i,mp[target-nums[i]]};
            }
        }
        return {};
    }
};