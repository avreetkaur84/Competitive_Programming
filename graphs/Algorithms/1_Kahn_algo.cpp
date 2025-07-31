#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Kahn's Algorithm is sued to find the topo sort in Directed graphs using BFS traversal
    That’s the whole beauty of Kahn’s Algorithm (BFS for cycle detection):

    Acyclic graph → eventually, every node’s indegree hits 0, so they all get processed.
    Cyclic graph → at least one node keeps its indegree > 0 forever, so your queue empties early and cnt < V. Boom, cycle detected.
*/


class Solution {
  public:
    void arr2adj(vector<vector<int>>& edges, vector<vector<int>>& adj) {
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
    }
    
    void indegree_cal(vector<vector<int>> &adj, vector<int> &indegree) {
        for(int i=0; i<adj.size(); i++) {
            for(int j=0; j<adj[i].size(); j++) {
                indegree[adj[i][j]]++;
            }
        }
    }
 
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V); 
        arr2adj(edges, adj); 
        
        queue<int> q; vector<int> res; vector<int> indegree(V, 0);
        indegree_cal(adj, indegree);
        
        for(int i=0; i<V; i++) {
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()) {
            int x=q.front();
            
            for(auto it : adj[x]) {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            
            q.pop(); res.push_back(x);
        }
        
        
        return res;
    }
};