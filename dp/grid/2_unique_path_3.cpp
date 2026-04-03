// Question Link: https://leetcode.com/problems/unique-paths-iii/description/

#include <bits/stdc++.h>
using namespace std;


// Backtracking: 21 March, 2026
class Solution {
public:
    struct Point {
        int x, y;
    };

    int uniquePathsIII(vector<vector<int>>& grid) {
        Point start, end;
        start.x=-1; start.y=-1;
        end.x=-1; end.y=-1;
        int n=grid.size(), m=grid[0].size(), vis_cnt=0, res=0;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1) {
                    start.x=i; start.y=j;
                }
                if(grid[i][j]==2) {
                    end.x=i; end.y=j;
                }
                if(grid[i][j]==0 || grid[i][j]==1)  vis_cnt++;
            }
        }        

        auto rec = [&](auto &&self, int i, int j, int cnt) -> void {
            if(i<0 || j<0 || i>=n || j>=m) return;
            if(grid[i][j]==-1) return;
            if(grid[i][j]==2 && cnt==vis_cnt) {                
                res++; return;           
            }

            int temp=grid[i][j];
            grid[i][j]=-1;
            for(auto d : dir) {
                int x=d[0]+i, y=d[1]+j;
                self(self, x, y, cnt+1);
            }
            grid[i][j]=temp;
        };

        rec(rec, start.x, start.y, 0);
        return res;
    }
};


// Tried long time ago - Unable to form full solution
class Solution {
public:
    /*
        simple bfs -> all unique paths
        prune -> 20*20*20*20
    */

    int uniquePathsIII(vector<vector<int>>& grid) {
        int start=1, end=2, n=grid.size(), m=grid[0].size();
        pair<int, int> st_cor={-1, -1}, end_cor={-1, -1};
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==start) st_cor = {i, j};
                if(grid[i][j]==end) end_cor = {i, j};
                if(st_cor.first!=-1 && st_cor.second!=-1 && end_cor.first!=-1 && end_cor.second!=-1)  break;
            }
        }

        int res=0;
        queue<pair<int, int>> q; 
        q.push(st_cor);
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        // how to deal with visited duplicacy -> bit masking use hogga
        //  we cant make global visited as we haev to cnt max possible path, so already visited cell for that path can result in unique path.
        // How can I use bit mask here, for a particular path, I dont want to visit the cells that are already visited, but cells are tracked by x and y cordinates, so, I need to create n*m size masks for each path but it will result in MLE. I think no, as m and n maxx would be 20.
        // vector<vector<string>> temp(n, vector<string> (m, m times 0)); ummm, I think  not feasible.

        while(!q.empty()) {
            int x = q.front().first, y=q.front().second; 
            q.pop();
            if(x==end_cor.first && y==end_cor.second) {
                res++; continue;
            }

            for(int i=0; i<4; i++) {
                int xt=x+dir[i][0], yt=y+dir[i][1];
                if(xt<n && xt>=0 && yt<m && yt>=0) {
                    q.push({xt, yt});
                }
            }
        }

        return res;
    }
};
