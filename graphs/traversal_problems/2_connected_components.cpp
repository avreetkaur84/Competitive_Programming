// Question Link - https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;


class Solution {
  public:
    
    void dfs(int node, vector<vector<int>> &adj, vector<int> &cur, vector<int> &vt) {
        cur.push_back(node);
        
        for(auto it : adj[node]) {
            if(!vt[it]) {
                vt[it]=1;
                dfs(it, adj, cur, vt);
            }
        }
        
    }
    
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> vt(V, 0);
        vector<vector<int>> res; 
        
        for(int i=0; i<V; i++) {
            if(!vt[i]) {
                vector<int> cur;
                vt[i]=1; 
                dfs(i, adj, cur, vt);
                res.push_back(cur);
            }
        }
        
        return res;
    }
};
