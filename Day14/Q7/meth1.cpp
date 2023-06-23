#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rotten(m, vector<int>(n, 0));
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        int Cfresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    Cfresh++;
                }
            }
        }
        vector<int> dr{-1, 0, 1, 0};
        vector<int> dc{0, 1, 0, -1};
        int time = 0;
        while (!q.empty()) {
            int sz = q.size();
            int flag = 0;
            while (sz--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                visited[i][j] = 1;
                for (int k = 0; k < 4; k++) {
                    int rr = i + dr[k];
                    int cc = j + dc[k];
                    if (rr >= 0 && rr < m && cc >= 0 && cc < n && grid[rr][cc] == 1 && visited[rr][cc] == -1) {
                        Cfresh--;
                        flag++;
                        grid[rr][cc] = 2; //rotten
                        visited[rr][cc] = 1;
                        q.push({rr, cc});
                    }
                }
            }
            if (flag > 0 ) {
                time++;
            }
        }
        if (Cfresh == 0) {
            return time;
        } else {
            return -1;
        }
    }
};