#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool check(bool g[101][101], int node,int N, int color, vector<int>& clr) {
        for(int i=0;i<N;i++){
            if(i!=N && g[i][node]==1){
                if(clr[i]==color)return false;
            }
        }
        return true;
    }

    bool solution(bool g[101][101], int m, int n, int node, vector<int>& clr) {
        if (node == n) {
            return true;
        }

        for (int i = 1; i <= m; i++) {
            if (check(g, node,n, i, clr)) {
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
        int node = 0;
        vector<int> clr(n , 0);
        return solution(graph, m, n, node, clr);
    }
};