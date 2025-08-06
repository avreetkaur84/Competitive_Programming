// Question Link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        vector<int> dist(n, -1);
        queue<pair<int, int>> q; q.push({src, 0}); // {node, dist}
        dist[src]=0;
        
        while(!q.empty()) {
            pair<int, int> p=q.front(); q.pop();
            // cout<<p.first<<" "<<p.second<<endl;
            for(auto it : adj[p.first]) {
                if(dist[it]==-1) {
                    dist[it]=p.second+1; q.push({it, p.second+1});
                }
            }
        }
        
        return dist;
    }
};