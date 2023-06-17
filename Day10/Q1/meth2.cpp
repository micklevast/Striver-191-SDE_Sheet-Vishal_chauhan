#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        // only when nums vector has been sorted in increasing order than only next_permutation will work perfectly fine.
    sort(nums.begin(),nums.end());
      vector<vector<int>> ans;
      do{
          ans.push_back(nums);
      }while(next_permutation(nums.begin(),nums.end()));
      return ans;  
    }
};

