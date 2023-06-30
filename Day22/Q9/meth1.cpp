#include<bits/stdc++.h>
// using bfs founded the no. of islands
class Solution {
public:
    vector<int> dr{-1,0,1,0};
    vector<int> dc{0,1,0,-1};
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& visited){
        int r=grid.size(),c=grid[0].size();
        visited[i][j]=true;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int cr=q.front().first;
            int cc=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=cr+dr[k];
                int nc=cc+dc[k];
                if(nr>=0 && nr<r && nc>=0 && nc<c && !visited[nr][nc] && grid[nr][nc]=='1'){
                    q.push({nr,nc});
                    visited[nr][nc]=true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int r=grid.size(),c=grid[0].size();
        vector<vector<bool>> visited(r,vector<bool>(c,false));

        int cnt_of_islands=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cnt_of_islands++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return cnt_of_islands;
    }
};