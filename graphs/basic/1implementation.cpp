// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// uisng adjacency list

int main() {
    int n, m; cin>>n>>m;
    // vector<int> arr[] = {{5, 6}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 5}};
    
    vector<int> adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}