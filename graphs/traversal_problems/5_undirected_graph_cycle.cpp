// Question Link - http://geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;


// dfs solution
class Solution {
  public:
    vector<int> vis;
    vector<vector<int>> adj;
    bool dfs(int node, int par) {
        for(auto it : adj[node]) {
            if(vis[it] && it!=par) return true;
            if(vis[it]) continue;
            vis[it]=1;
            bool flag = dfs(it, node);
            if(flag) return true;
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        adj.resize(V);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vis.resize(V,0); 
        for(int i=0; i<V; i++) {
            if(vis[i]) continue;
            vis[i]=1;
            bool flag = dfs(i, -1);
            if(flag) return true;
        }
        
        return false;
    }
};

// take of unconnected graph case
// bfs
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V); vector<int> vt(V, 0);
        
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        // do bfs traversal 
        queue<vector<int>> q;
        
        for(int i=0; i<V; i++) {
            if(vt[i]!=1) {
                q.push({i, -1}); vt[i]=1;
                while(!q.empty()) {
                    for(auto it : adj[q.front()[0]]) {
                        if(it!=q.front()[1]) {
                            if(vt[it]==1) return true;
                            else {
                                vt[it]=1;
                                q.push({it, q.front()[0]});
                            }
                        }
                    }
                    
                    q.pop();
                }
            }
        }
        
        return false;
    }
};