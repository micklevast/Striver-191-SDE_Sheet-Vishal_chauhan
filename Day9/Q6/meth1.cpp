#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void generatePermutations(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size() - 1) {
        result.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        generatePermutations(nums, start + 1, result);
        swap(nums[start], nums[i]); // backtrack: restore the original order
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    generatePermutations(nums, 0, result);
    return result;
}

    string getPermutation(int n, int k) {
        vector<int> arr(n);
        for(int i=1;i<=n;i++){
            arr[i-1]=i;
        }
        vector<vector<int>> allP=permute(arr);
        sort(allP.begin(),allP.end());
        vector<int> ans=allP[k-1];
        string a="";
        for(auto val:ans){
            a+=to_string(val);
        }
        return a;
    }
};