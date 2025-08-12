// Question Link - https://leetcode.com/problems/path-with-minimum-effort/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> arr = {{0,-1}, {0,1}, {-1,0}, {1,0}};
        int n=heights.size(), m=heights[0].size();
        if(n==1 && m==1) return 0;
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> hp;
        hp.push({0,0,0}); dist[0][0]=0;

        while(!hp.empty()) {
            vector<int> p=hp.top(); hp.pop();
            for(auto it : arr) {
                int i=it[0]+p[1], j=it[1]+p[2], cur_dif=p[0];
                if(i<0 || i>=n || j<0 || j>=m) continue;
                int diff=abs(heights[i][j]-heights[p[1]][p[2]]);
                diff=max(diff, cur_dif);
                if(diff<dist[i][j]) {
                    dist[i][j]=diff;
                    hp.push({diff, i, j});
                }
            }
        }

        return dist[n-1][m-1];
    }
};