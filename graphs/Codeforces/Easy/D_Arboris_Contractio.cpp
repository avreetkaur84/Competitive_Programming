// Question Link - https://codeforces.com/contest/2131/problem/D

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void inArr(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void outArr2D(vector<vector<int>> &arr) {
    for(int i=0; i<arr.size(); i++) {
        // cout<<i<<": ";
        for(int j=0; j<arr[i].size(); j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}


/*
    1. Node with min. leaf nodes cnt with distance>1 is ans.
    2. Count all leaf nodes -> simply from adjacency matrix
    3. Recurse all nodes to find the node with min. leaf nodes. If a leaf node distance from that node is one, ignore that leaf node.
*/

void solve() {
    int n;  cin>>n; 
    vector<vector<int>> adj(n+1);

    for(int i=0; i<n-1; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n-1==1) {
        cout<<0<<endl; return;
    }

    int st_size=0;
    for(int i=1; i<=n; i++) {
        if(adj[i].size()==1) st_size++;
    }
    
    int cnt=INT_MAX;
    for(int i=1; i<=n; i++) {
        int minn=0;
        for(auto it : adj[i]) {
            if(adj[it].size()==1) minn++;
        }
        cnt=min(st_size-minn, cnt);
    }
    
    cout<<cnt<<endl;
}



int main()
{
    int t;
    cin >> t;

    
    while(t--)
    {
        solve();
    }
}