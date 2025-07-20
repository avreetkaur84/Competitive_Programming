// Question Link - http://geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

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


// dfs
class Solution {
  public:
    void dfs(int node, int parent, bool &flag, vector<vector<int>> &adj, vector<int> &vt) {
        if(flag==true) return;
        
        for(auto it : adj[node]) {
            if(it!=parent && vt[it]==1) {
                // cout<<vt[it]<<" parent: "<<parent<<"    node: "<<node<<endl;
                flag=true; return;
            } 
            
            if(!vt[it]) {
                vt[it]=1;
                dfs(it, node, flag, adj, vt);   
            }
        }
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V); vector<int> vt(V, 0);
        bool flag=false;
        
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        // for(int i=0; i<adj[3].size(); i++) cout<<adj[3][i]<<"   ";
        // cout<<endl;
        
        for(int i=0; i<V; i++) {
            if(vt[i]!=1 && adj[i].size()>0) {
                // vt[i]=1;
                flag=false; vt[i]=1;
                dfs(i, -1, flag, adj, vt);
                if(flag==true) return true;
            }
        }
        
        return flag;
    }
};