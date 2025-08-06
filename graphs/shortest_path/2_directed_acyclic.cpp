// Question Link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Date - 5 Aug, 2025
    - This code can be optimised futher. 
*/

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);     // {0 - {node1, weight}, {node1, weight}}
        
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        queue<int> st; vector<int> dist(V, INT_MAX);
        st.push(0); dist[0]=0;
        
        while(!st.empty()) {
            int node=st.front(); st.pop();
            for(auto it : adj[node]) {
                if(dist[node]+it.second<dist[it.first]) {
                    dist[it.first]=dist[node]+it.second;
                    st.push(it.first);
                }
            }
        }
        
        for(int i=0; i<dist.size(); i++) {
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        
        return dist;
    }
};