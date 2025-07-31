// Question Link - https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// DFS
class Solution {
  public:
    void arr2adj(vector<vector<int>> &edges, vector<vector<int>> &adj) {
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
    }
    
    bool dfs(int i, vector<int> &vt, vector<int> &pth, vector<vector<int>> &adj) {
        for(auto it : adj[i]) {
            if(vt[it]==1 && pth[it]==1) return true;
            if(!vt[it]) {
                vt[it]=1; pth[it]=1;
                bool flag = dfs(it, vt, pth, adj);
                if(flag) return true;
                pth[it]=0;
            }
        }
        
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        arr2adj(edges, adj);
        vector<int> vt(V, 0); vector<int> pth(V, 0);
        bool flag=false;
        
        for(int i=0; i<adj.size(); i++) {
            if(!vt[i]) {
                vt[i]=1; pth[i]=1;
                flag = dfs(i, vt, pth, adj);
                if(flag) return true;
                pth[i]=0;
            }
        }
        
        return flag;
    }
};



// BFS
class Solution {
  public:
    void arr2adj(vector<vector<int>> &edges, vector<vector<int>> &adj) {
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
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        arr2adj(edges, adj);
        
        vector<int> indegree(V, 0); vector<int> vt(V, 0);
        indegree_cal(adj, indegree); int cnt=0;
        queue<int> q;
        
        for(int i=0; i<V; i++) {
            if(indegree[i]==0) {
                q.push(i); vt[i]=1; cnt++;
            }
        }
            
        while(!q.empty()) {
            int x=q.front();
            for(auto it : adj[x]) {
                indegree[it]--;
                if(indegree[it]==0) {
                    q.push(it); vt[it]=1; cnt++;
                }
            }
            q.pop();
        }
        
        if(cnt!=V) return true;
        return false;
    }
};