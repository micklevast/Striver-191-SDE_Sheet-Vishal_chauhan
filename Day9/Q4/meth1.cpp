#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static void find(vector<int>& candidates, int target, int start, vector<vector<int>>& ans, vector<int>& combination) {
        if (target == 0) {
            ans.push_back(combination);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1])
                continue; // skip duplicates
            
            if (candidates[i] <= target) {
                combination.push_back(candidates[i]);
                find(candidates, target - candidates[i], i + 1, ans, combination); // move to the next index
                combination.pop_back(); // backtrack by removing the added element from the combination
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combination;
        find(candidates, target, 0, ans, combination);
        return ans;
    }
};
