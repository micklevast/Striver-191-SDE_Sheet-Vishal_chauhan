
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
bool checkValid(vector<string> &board, int row, int col, int size) {
    // Check straight up
    int i = row - 1;
    while (i >= 0) {
        if (board[i][col] == 'Q') {
            return false;
        }
        i--;
    }

    // Check left diagonal
    i = 1;
    while (row - i >= 0 && col - i >= 0) {
        if (board[row - i][col - i] == 'Q') {
            return false;
        }
        i++;
    }

    // Check right diagonal
    i = 1;
    while (row - i >= 0 && col + i < size) {
        if (board[row - i][col + i] == 'Q') {
            return false;
        }
        i++;
    }

    return true;
}

    vector<string> store(vector<string>& ans) {
        return ans;
    }

    void solve(vector<string>& chess, int n, int r, vector<vector<string>>& ans) {
        if (r == n) {
            vector<string> ans1 = store(chess);
            ans.push_back(ans1);
        }
        for (int c = 0; c < n; c++) {
            if (checkValid(chess, r, c, n)) {
                chess[r][c] = 'Q';
                solve(chess, n, r + 1, ans);
                chess[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chess(n, string(n, '.'));
        int r = 0;
        vector<vector<string>> ans;
        solve(chess, n, r, ans);
        return ans;
    }
};

// int main() {
//     Solution solution;
//     int n = 4;
//     vector<vector<string>> result = solution.solveNQueens(n);

//     // Print the result
//     for (const auto& solution : result) {
//         for (const auto& row : solution) {
//             cout << row << endl;
//         }
//         cout << endl;
//     }

//     return 0;
// }