// Question Link - https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    THE CORE GEOMETRY CONCEPT: Translation Invariance
    This problem boils down to one big idea from geometry: Two shapes are the same if one can be translated (shifted) to match the other — no rotation, no flipping, just shifting. That’s called translation invariance.

    
*/

// Tried on 18 sep, 2025 again.
// gfg: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
class Solution {
  public:
    /*
        G: no of islands
        bfs -> traversal -> find connected comp. no.
    */
    using pi = pair<int, int>;
    
    void trav(pi cur, vector<vector<char>>& grid, queue<pi> &q, vector<vector<int>> &vt) {
        vector<pi> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        int n=grid.size(), m=grid[0].size();
        
        for(auto it : dir) {
            int i = cur.first+it.first, j=cur.second+it.second;
            if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='W' || vt[i][j]==1) continue;
            vt[i][j]=1; q.push({i, j}); 
        }
    }
    
  
    int countIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vt(n, vector<int> (m, 0));
        int cnt=0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='W' || vt[i][j]==1) continue;
                cnt++; queue<pi> q; q.push({i, j}); vt[i][j]=1;
                
                while(!q.empty()) {
                    pi cur = q.front(); q.pop();
                    trav(cur, grid, q, vt);
                }
            }
        }
        
        return cnt;
        
    }
};


class Solution {
  public:
    /*
        1. Finding no of number of connected components in graph
    */
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vt) {
        if(grid[i][j]==0) return;
        int n=grid.size(), m=grid[0].size();
        
        if(i+1<n && grid[i+1][j]==1 && vt[i+1][j]!=1) {
            vt[i+1][j]=1; dfs(i+1, j, grid, vt);
        }
        if(i-1>=0 && grid[i-1][j]==1 && vt[i-1][j]!=1) {
            vt[i-1][j]=1; dfs(i-1, j, grid, vt);
        }
        if(j+1<m && grid[i][j+1]==1 && vt[i][j+1]!=1) {
            vt[i][j+1]=1; dfs(i, j+1, grid, vt);
        }
        if(j-1>=0 && grid[i][j-1]==1 && vt[i][j-1]!=1) {
            vt[i][j-1]=1; dfs(i, j-1, grid, vt);
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), cnt=0;
        vector<vector<int>> vt(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1 && vt[i][j]!=1) {
                    cnt++; 
                    dfs(i, j, grid, vt);
                }
            }
        }
        
        return cnt;
    }
};
