#include <iostream>
#include <vector>
#include <string>
// giving wrong over somme of the test cases.
class Solution {
public:
    bool check(vector<int> graph[6], int node, int color, vector<int>& clr) {
        for (int val : graph[node]) {
            if (clr[val] == color) {
                return false;
            }
        }
        return true;
    }

    bool solution(vector<int> g[], int m, int n, int node, vector<int>& clr) {
        if (node == n) {
            return true;
        }

        for (int i = 1; i <= m; i++) {
            if (check(g, node, i, clr)) {
                clr[node] = i;
                if (solution(g, m, n, node + 1, clr)) {
                    return true;
                }
                clr[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> g[n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j]) {
                    g[i + 1].push_back(j + 1);
                    g[j + 1].push_back(i + 1);  // add reverse edge for undirected graph
                }
            }
        }

        int node = 1;
        vector<int> clr(n + 1, 0);
        return solution(g, m, n, node, clr);
    }
};