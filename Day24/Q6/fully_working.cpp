#include<bits/stdc++.h>
using namespace std;
class union_set {
    vector<int> parent, rank;

public:
    union_set(int V) {
        parent.resize(V + 1);
        rank.resize(V + 1, 0);
        for (int i = 0; i <= V; i++) {
            parent[i] = i;
        }
    }

    int findParent(int n) {
        if (parent[n] == n)
            return n;

        return parent[n] = findParent(parent[n]);
    }

    void unionByRank(int n1, int n2) {
        int ultimate_parent_n1 = findParent(n1);
        int ultimate_parent_n2 = findParent(n2);
        if (ultimate_parent_n2 == ultimate_parent_n1)
            return;

        int r1 = rank[ultimate_parent_n1];
        int r2 = rank[ultimate_parent_n2];

        if (r1 < r2) {
            parent[ultimate_parent_n1] = ultimate_parent_n2;
        } else if (r2 < r1) {
            parent[ultimate_parent_n2] = ultimate_parent_n1;
        } else {
            parent[ultimate_parent_n1] = ultimate_parent_n2;
            rank[ultimate_parent_n2]++;
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        // let's try it using Kruskal's algorithm
        // in Kruskal's algorithm, we will use rank[], parent[], findParent(int node), unionByRank(int n1, int n2)

        // First, we need edges in sorted order of their weight
        vector<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int n1 = i;
                int n2 = it[0];
                int wgh = it[1];
                pq.push_back({wgh, {n1, n2}});
            }
        }
        sort(pq.begin(),pq.end());
        
        int mst_sum = 0;
        union_set us(V);
        // After that, using pq minimum-weight try to make unionByRank if nodes n1 and n2 are not of the same component of the graph
        for(auto val:pq) {
            int wgh = val.first;
            int n1 = val.second.first;
            int n2 = val.second.second;

            if (us.findParent(n1) != us.findParent(n2)) { // if n1, n2 are not the same component, then
                mst_sum += wgh; // include them in MST by adding their weight
                // Then include them in the MST graph
                us.unionByRank(n1, n2);
            }
        }
        return mst_sum;
    }
};
