// Question Link - https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
  public:
    void helper(int node, vector<vector<int>>& adj, vector<int> &res, vector<int> &vt) {
        res.push_back(node);
        for(auto it : adj[node]) {
            if(!vt[it]) {
                vt[it]=1;
                helper(it, adj, res, vt);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> res; vector<int> vt(adj.size(), 0);
        vt[0]=1;
        helper(0, adj, res, vt);
        return res;
    }
};