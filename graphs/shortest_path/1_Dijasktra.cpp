// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define pii pair<ll, int>

// vector<ll> dijkstra(int n, int src, vector<vector<pair<int,int>>>& adj) {
//     const ll INF = 1e18;
//     vector<ll> dist(n, INF);
//     priority_queue<pii, vector<pii>, greater<pii>> pq;

//     dist[src] = 0;
//     pq.push({0, src});

//     while (!pq.empty()) {
//         auto [d, u] = pq.top(); pq.pop();
//         if (d > dist[u]) continue; // stale entry

//         for (auto [v, w] : adj[u]) {
//             if (dist[u] + w < dist[v]) {
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
//     return dist;
// }