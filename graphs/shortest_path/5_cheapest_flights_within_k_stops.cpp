// Question Link - https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    /*
        1. Create adjacency list
        2. Apply dijkstra's algo -> for calculating min price
        3. At most k stops -> this can be a point of discussion -> we can add stops cnt with each cell, and if k cnt will be more, we won't put that in queue. 
    */
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        vector<int> dist(n, INT_MAX); 
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> hp;
        queue<vector<int>> hp;
        hp.push({0,src,0});  // hp -> {price, node, k}
        dist[src]=0;

        while(!hp.empty()) {
            vector<int> p = hp.front(); hp.pop();
            // cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
            for(auto it : adj[p[1]]) {                 
                int pric = p[0]+it.second;
                if(pric<dist[it.first] && p[2]<=k) {
                    dist[it.first]=pric;
                    hp.push({pric, it.first, p[2]+1});
                    // cout<<pric<<" "<<it.first<<" "<<p[2]+1<<endl;
                }
            }
            // cout<<endl;
        }

        // for(int i=0; i<dist.size(); i++) {
        //     cout<<dist[i]<<"  ";
        // }
        // cout<<endl;

        if(dist[dst]==INT_MAX) return -1;
        else return dist[dst];
    }
};