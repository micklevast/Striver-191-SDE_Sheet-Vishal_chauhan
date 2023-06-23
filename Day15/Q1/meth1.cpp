#include <bits/stdc++.h> 
class Solution {
public:
    void find(vector<string>& s, int i, string& ans) {
        if (i >= s.size()) {
            return;
        }
        find(s, i + 1, ans);
        ans += s[i] + " ";
    }

    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> vec;
        string str;
        while (ss >> str) {
            vec.push_back(str);
        }
        string ans = "";
        find(vec, 0, ans);
        if (!ans.empty()) {
            ans.pop_back(); // Remove the trailing space
        }
        return ans;
    }
};