#include <bits/stdc++.h>
using namespace std;

/*
    CC - A    - 2 
    SD - A    - 3 
    FS - A    - 3
    CC - A    - 3
    NM - B    - 4 
    TC - B+   - 3
    AI - B+   - 2
    PJ - B+   - 1
*/

/*
    - nodes, adjacency, start from any node
    - for that node, check for all colors that can be assigned to it.
    - next, call its next adjacent node which is uncolored
    - if all the nodes are colored in this branch, return 1, else return 0
    - if 0 is returned, we will chek for next color
    - but, if final result is zero, then answer is false
    
*/

class Solution {
  public:
    vector<vector<int>> adj;
    vector<int> color;
    
    int rec(int node, vector<int> &node_col) {
        set<int> col;
        for(auto neigh : adj[node]) {
            if(node_col[neigh]!=-1) col.insert(node_col[neigh]);
        }
        
        for(auto it : color) {
            if(col.count(it)) continue;
            node_col[node] = it;
            int res=1;
            for(auto neigh : adj[node]) {
                if(node_col[neigh]!=-1) continue;
                res &= rec(neigh, node_col);
            }
            if(res==1) return res;
            node_col[node]=-1;
        }
        
        return 0;
    }
  
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        adj.resize(v);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        color.resize(m);
        vector<int> node_col(v, -1);
        for(int i=0; i<m; i++) color[i]=i;
        for(int i=0; i<v; i++) {
           if(node_col[i]!=-1) continue;
           int res = rec(i, node_col);
           if(res==0) return res;
        }
        return 1;
    }
};