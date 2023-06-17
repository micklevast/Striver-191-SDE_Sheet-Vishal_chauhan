#include <iostream>
#include <vector>
#include <string>
class Solution {
public:
    void find(vector<string>& ans, vector<vector<int>>& mat, int n, int r, int c, string str) {
        if (r < 0 || r >= n || c < 0 || c >= n || mat[r][c] == 0)
            return;

        if (r == n - 1 && c == n - 1) {
            ans.push_back(str);
            return;
        }

        mat[r][c] = 0;  // Mark the current cell as visited

        find(ans, mat, n, r + 1, c, str + 'D');
        find(ans, mat, n, r, c + 1, str + 'R');
        find(ans, mat, n, r, c - 1, str + 'L');
        find(ans, mat, n, r - 1, c, str + 'U');

        mat[r][c] = 1;  // Restore the current cell after the recursive calls
    }

    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;
        int r = 0, c = 0;
        string str = "";
        find(ans, m, n, r, c, str);
        return ans;
    }
};
