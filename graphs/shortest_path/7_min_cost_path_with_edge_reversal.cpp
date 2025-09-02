// Question Link - https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    /*
        1. Simply apply dijktra -> now think about twist.
        2. DSA is pure magic, just by adding one more line full question solved!!! :-> adj[edges[i][1]].push_back({edges[i][0], 2*edges[i][2]});
    */
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], 2*edges[i][2]});
        }

        vector<int> dist(n, INT_MAX); dist[0]=0;
        queue<pair<int, int>> q; q.push({0,0}); // q -> {dist, node}

        while(!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            for(auto it : adj[p.second]) {
                int dis = p.first+it.second;
                if(dis<dist[it.first]) {
                    dist[it.first] = dis;
                    q.push({dis, it.first});
                }
            }
        }

        return (dist[n-1]==INT_MAX) ? -1 : dist[n-1];
    }
};