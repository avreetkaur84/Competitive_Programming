// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

class Solution {
  public:
    void display(vector<int> arr) {
        for(auto it : arr) cout<<it<<" ";
        cout<<"\n";
    }
  
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src]=0; 
        set<int> st; st.insert(src);
        // display(dist);
        
        for(int i=1; i<=V; i++) {
            for(int j=0; j<edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                
                if(st.find(u)!=st.end()) st.insert(v);
                
                if(st.find(u)!=st.end()) {
                    if(i==V && dist[u]!=10e8 && (dist[u]+w < dist[v])) return {-1};
                    if(dist[u]!=10e8 && dist[u]+w < dist[v]) dist[v]=dist[u]+w;
                }
            }
            // display(dist);
        }
        
        return dist;
    }
};
