// Question Link - https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // check 8-direction, so craete array for 8 D
        vector<vector<int>> arr = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
        int n=grid.size();
        if(grid[0][0]==1) return -1;
        if(grid[0][0]==0 && n==1) return 1;
        vector<vector<int>> vt(n, vector<int> (n,0));
        queue<vector<int>> q; q.push({0,0,1});  vt[0][0]=1;

        while(!q.empty()) {
            vector<int> p=q.front(); q.pop();
            int i=p[0], j=p[1], dist=p[2];
            for(int w=0; w<arr.size(); w++) {
                int g=arr[w][0], h=arr[w][1];
                if(i+g<0 || i+g>=n) continue;
                if(j+h<0 || j+h>=n) continue;
                if(grid[i+g][j+h]==0 && vt[i+g][j+h]==0) {
                    if(i+g==n-1 && j+h==n-1) return dist+1;
                    q.push({i+g, j+h, dist+1}); vt[i+g][j+h]=1;
                }
            }
        }

        return -1;

    }
};