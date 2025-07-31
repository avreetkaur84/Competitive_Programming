// Question Link - https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    THE CORE GEOMETRY CONCEPT: Translation Invariance
    This problem boils down to one big idea from geometry: Two shapes are the same if one can be translated (shifted) to match the other — no rotation, no flipping, just shifting. That’s called translation invariance.

    
*/

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
