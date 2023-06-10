#include <bits/stdc++.h>
using namespace std;

// O(N^3)  & O(1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        // break;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;  //avoid the duplikacy ,that work does by set in previous solution
                        while(low < high && nums[high] == nums[tempIndex2]) high--;  //avoid the duplikacy
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;  //avoid the duplikacy
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;  //avoid the duplikacy
        }
        return output;
    }
};

