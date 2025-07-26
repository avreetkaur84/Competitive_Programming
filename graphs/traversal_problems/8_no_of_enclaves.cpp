// Question Link - https://leetcode.com/problems/number-of-enclaves/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    // we will return those 1's that are surrouned by zeros
    void bfs(set<pair<int, int>> &st, vector<vector<int>>& grid, pair<int, int> cur) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<int, int>> q; q.push(cur); st.erase(cur);

        while(!q.empty()) {
            pair<int, int> p = q.front(); q.pop();

            if(p.first+1<n && grid[p.first+1][p.second]==1 && st.find({p.first+1, p.second})!=st.end()) {
                q.push({p.first+1, p.second}); st.erase({p.first+1, p.second});
            }
            if(p.first-1>=0 && grid[p.first-1][p.second]==1 && st.find({p.first-1, p.second})!=st.end()) {
                q.push({p.first-1, p.second}); st.erase({p.first-1, p.second});
            }
            if(p.second+1<m && grid[p.first][p.second+1]==1 && st.find({p.first, p.second+1})!=st.end()) {
                q.push({p.first, p.second+1}); st.erase({p.first, p.second+1});
            }
            if(p.second-1>=0 && grid[p.first][p.second-1]==1 && st.find({p.first, p.second-1})!=st.end()) {
                q.push({p.first, p.second-1}); st.erase({p.first, p.second-1});
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if(m==1 || n==1) return 0;
        set<pair<int, int>> st; // set will store 1 indexes

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1) st.insert({i, j});
            }
        }

        for(int i=0; i<n; i++) if(grid[i][0]==1) bfs(st, grid, {i, 0});
        for(int i=0; i<m; i++) if(grid[0][i]==1) bfs(st, grid, {0, i});
        for(int i=0; i<n; i++) if(grid[i][m-1]==1) bfs(st, grid, {i, m-1});
        for(int i=0; i<m; i++) if(grid[n-1][i]==1) bfs(st, grid, {n-1, i});

        return st.size();
    }
};