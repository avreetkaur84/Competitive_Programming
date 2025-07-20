// Question Link - https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// My try on - 17 july, 2025

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vt = grid;
        queue<vector<int>> q; int o_cnt=0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==2) {
                    q.push({i, j, 0});
                } else if(grid[i][j]==1) o_cnt++;
            }
        }

        cout<<o_cnt<<endl;

        int time=0;
        while(!q.empty()) {
            int y=q.size();
            for(int x=0; x<y; x++) {
                vector<int> cur = q.front();
                int i=cur[0], j=cur[1]; time=max(time, cur[2]);
                
                // 4-d check
                if(i-1>=0 && grid[i-1][j]==1 && vt[i-1][j]!=2) {
                    vt[i-1][j]=2; q.push({i-1, j, cur[2]+1}); o_cnt--;
                }
                if(i+1<n && grid[i+1][j]==1 && vt[i+1][j]!=2) {
                    vt[i+1][j]=2; q.push({i+1, j, cur[2]+1}); o_cnt--;
                }
                if(j-1>=0 && grid[i][j-1]==1 && vt[i][j-1]!=2) {
                    vt[i][j-1]=2; q.push({i, j-1, cur[2]+1}); o_cnt--;
                }
                if(j+1<m && grid[i][j+1]==1 && vt[i][j+1]!=2) {
                    vt[i][j+1]=2; q.push({i, j+1, cur[2]+1}); o_cnt--;
                }
                q.pop();
            }
        }

        cout<<o_cnt<<endl;

        return o_cnt>0 ? -1 : time;
    }
};