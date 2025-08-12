// Question Link - https://leetcode.com/problems/network-delay-time/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    // we have to fidn the shortest distance/time -> dijkstra's algo

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1); vector<int> dist(n+1, INT_MAX); dist[0]=0;
        for(int i=0; i<times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});    // {time, node}
        dist[k]=0;

        while(!pq.empty()) {
            pair<int, int> p=pq.top(); pq.pop();
            for(auto it : adj[p.second]) {
                int t_time=p.first+it.second;
                if(t_time<dist[it.first]) {
                    dist[it.first] = t_time;
                    pq.push({t_time, it.first});
                }
            }
        }

        int res=0;
        for(int i=1; i<dist.size(); i++) res=max(res, dist[i]);

        if(res==INT_MAX) return -1;
        else return res;
    }
};