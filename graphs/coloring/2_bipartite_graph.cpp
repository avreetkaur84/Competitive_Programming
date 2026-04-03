// Question Link: https://leetcode.com/problems/is-graph-bipartite/description/

#include <bits/stdc++.h>
using namespace std;

// 28 MARCH, 2026 - Approach 2
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> col = {0, 1};
        vector<int> node_col(v, -1);

        auto rec = [&](auto &&self, int node) -> bool {
            set<int> st;
            for(auto it : graph[node]) {
                if(node_col[it]==-1) continue;
                st.insert(node_col[it]);
            }
            if(st.size()==2) return 0;

            node_col[node] = !(*st.begin());
            int res=1;
            for(auto neigh : graph[node]) {
                if(node_col[neigh]!=-1) continue;
                res &= self(self, neigh);
            }
            if(res) return 1;            
            return 0;
        };

        for(int i=0; i<v; i++) {
            if(node_col[i]!=-1) continue;
            int res = rec(rec, i);
            if(!res) return res;
        }

        return true;
    }
};


// 21 Jan, 2026 - Approach 1
class Solution {
public:
    /*
        split a connected component into two sets 
        I think problem is in how I am returning the values, false state is tracked and returned properly
    */

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n, 0);

        auto check = [&](auto && self, int node, set<int> cur, set<int> alter) {
            for(auto it : graph[node]) {
                if(alter.count(it)) return false;
                if(vis[it]) continue;
                cur.insert(it); vis[it]=1;
                bool res = self(self, it, alter, cur);
                if(!res) return false;
            }

            return true;
        };

        for(int i=0; i<n; i++) {
            if(vis[i]) continue;
            vis[i]=1;
            bool res = check(check, i, {}, {i});
            if(!res) return false;
        }

        return true;
    }
};