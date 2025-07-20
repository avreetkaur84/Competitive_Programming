// Question Link - https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Its easy peasy lemon squezy!!! ;)

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> visited(adj.size(), 0);
        queue<int> q; vector<int> res;
        q.push(0); visited[0]=1;
        
        while(!q.empty()) {
            int node = q.front();
            for(auto it : adj[node]) {
                if(!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
            
            res.push_back(node); q.pop();
        }
        
        return res;
    }
};