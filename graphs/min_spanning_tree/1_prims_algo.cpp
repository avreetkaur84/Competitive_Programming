#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    1. Make an visited array, min heap {edge, node1, node2}, edge array -> store the final edges
    2. Put any starting node in the priority queue.
    3. Remove the top node from priority queue, make the parent node as visited. Then, push all the edges that are connected with this node in the min heap. You can avoid visited nodes edges. 
    4. Also, add the edge that is removed from the prority queue into the edge array.
    5. Continue this process until you get n-1 edges, where n is the number of nodes.
    6. The edges stored in the edge array will make up the minimum spanning tree.

    This algo is used a lot in questions like - there are n cities and for each pair of cities we are given the cost to build a road between them (or we know that is physically impossible to build a road between them). We have to build roads, such that we can get from each city to every other city, and the cost for building all roads is minimal.
*/

/*
    1. Start with node 0, mark it visited.
    2. Push all edges from node 0 into the PQ.
    3. While PQ is not empty:
        4. Pop the smallest edge (w, u, v).
        5. If v is already visited, skip it.
        6. Otherwise:
                7. Add (u, v) to MST.
                8. Mark v visited.
                9. Push all edges from v into PQ where the other endpoint is not visited.
*/

class Solution {
  public:
    void adjList(vector<vector<int>>& edges, vector<vector<pair<int, int>>> &adj) {
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
    }
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {edge_weight, parent_node, child_node}
        vector<vector<pair<int, int>>> adj(V);
        adjList(edges, adj); int sum=0;
        vector<int> vt(V, 0); vector<vector<int>> edg; // {node1, node2, weight}
        
        vt[0]=1; 
        for(auto it : adj[0]) pq.push({it.second, 0, it.first}); 
        
        while(!pq.empty()) {
            vector<int> p = pq.top(); pq.pop();
            if(vt[p[2]]==1) continue;
            edg.push_back({p[1], p[2], p[0]}); sum+=p[0];
            vt[p[2]]=1;
            for(auto it : adj[p[2]]) pq.push({it.second, p[2], it.first}); 
        }
        
        return sum;
    }
};