#include <iostream>
#include <vector>
#include <string>
class Solution {
public:
    vector<int> di{1, 0, 0, -1};
    vector<int> dj{0, 1, -1, 0};
    
    void find(vector<string>& ans, vector<vector<int>>& mat, int n, int r, int c, string str) {
        if (r < 0 || r >= n || c < 0 || c >= n || mat[r][c] == 0)
            return;
        
        if (r == n - 1 && c == n - 1) {
            ans.push_back(str);
            return;
        }
        
        int temp = mat[r][c];  // Store the current cell value
        
        mat[r][c] = 0;  // Mark the current cell as visited
        
        string move = "DRLU";
        for (int i = 0; i < 4; i++) {
            find(ans, mat, n, r + di[i], c + dj[i], str + move[i]);
        }
        
        mat[r][c] = temp;  // Restore the current cell
    }
    
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;
        int r = 0, c = 0;
        string str = "";
        find(ans, m, n, r, c, str);
        return ans;
    }
};