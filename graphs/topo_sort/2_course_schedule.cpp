// Question Link - https://leetcode.com/problems/course-schedule-ii/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    void arr2adj(vector<vector<int>>& edges, vector<vector<int>>& adj) {
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
    }

    bool dfs(int i, vector<int> &vt, vector<int> &pth, queue<int> &q, vector<vector<int>> &adj) {
        for(auto it : adj[i]) {
            if(vt[it]==1 && pth[it]==1) return true;
            if(!vt[it]) {
                vt[it]=1; pth[it]=1;
                bool flag = dfs(it, vt, pth, q, adj);
                if(flag) return true;
                q.push(it); pth[it]=0;
            }
        }

        return false;
    }

    // topo sort but reverse order - stack no - queue yes - rest same
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<vector<int>> adj(V);
        arr2adj(prerequisites, adj);

        vector<int> vt(V, 0); vector<int> pth(V, 0); queue<int> q;
        bool flag=false;

        for(int i=0; i<V; i++) {
            if(!vt[i]) {
                vt[i]=1; pth[i]=1;
                flag = dfs(i, vt, pth, q, adj);
                if(flag) return {};
                pth[i]=0; q.push(i);
            }
        }

        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front()); q.pop();
        }

        return res;
    }
};