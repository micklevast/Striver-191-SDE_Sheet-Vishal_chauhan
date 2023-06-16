#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static void find(vector<int> can, int tar, vector<vector<int>>& ans, set<vector<int>>& st, vector<int>& t, int sum) {
        if (sum > tar) return;
        else if (sum == tar) {
            vector<int> temp=t;
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        for (int i = 0; i < can.size(); i++) {
            sum += can[i];
            t.push_back(can[i]);
            find(can, tar, ans, st, t, sum);
            sum -= can[i]; // backtrack by subtracting the added element from the sum
            t.pop_back(); // backtrack by removing the added element from the vector
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        sort(can.begin(), can.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> temp;
        int sum = 0;
        find(can, target, ans, st, temp, sum);
        for (auto vec : st) {
            ans.push_back(vec);
        }
        return ans;
    }
};