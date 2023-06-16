#include<bits/stdc++.h>
using namespace std;
// this method have to improve as i am gettiing wrong answer oer some of the test cases.

class Solution {
public:
    static void find(vector<int> can, int tar, int idx, set<vector<int>>& st, vector<int>& t, int sum) {
        if (sum > tar || idx == can.size()) return;
        else if (sum == tar) {
            st.insert(t);
            return;
        }
        
        t.push_back(can[idx]);
        int s = sum + can[idx];
        find(can, tar, idx + 1, st, t, s);
        t.pop_back(); // backtrack by removing the added element from the vector
        find(can, tar, idx + 1, st, t, sum);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(), can.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> temp;
        int sum = 0;
        int idx = 0;
        find(can, target, idx, st, temp, sum);
        for (auto vec : st) {
            ans.push_back(vec);
        }
        return ans;
    }
};
