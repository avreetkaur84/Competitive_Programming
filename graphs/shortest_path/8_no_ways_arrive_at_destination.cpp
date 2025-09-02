// Question Link - https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LONG_LONG_MAX);
        vector<long long> cnt(n, 0);
        dist[0]=0; pq.push({0, 0}); // {dist, node} 
        cnt[0]=1;

        // duplicates avoid karne hai -> agar already
        while(!pq.empty()) {
            pair<long long, int> p = pq.top(); pq.pop();
            for(auto it : adj[p.second]) {
                long long cur_dis = p.first+it.second;
                if(cur_dis>dist[it.first]) continue;
                if(cur_dis<dist[it.first]) {
                    dist[it.first] = cur_dis;
                    cnt[it.first] = cnt[p.second];
                    pq.push({cur_dis, it.first});
                } else if(cur_dis==dist[it.first]) cnt[it.first]= (cnt[it.first]+cnt[p.second])%MOD;
            }
        }

        // cout<<minn<<endl;
        return cnt[n-1];
    }
};