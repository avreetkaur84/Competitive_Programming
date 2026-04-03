// Question Link - https://leetcode.com/problems/count-nodes-with-the-highest-score/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:    
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size(), cnt=0;
        long long mx=0;
        vector<int> child(n);
        vector<vector<int>> adj(n);

        for(int i=1; i<n; i++) {
            adj[parents[i]].push_back(i);
        }

        auto cal = [&](auto &&self, int node) -> int {
            int x=0;
            for(auto it : adj[node]) {
                x += self(self, it);
            }
            child[node]=x;
            return x+1;
        };

        cal(cal, 0);

        for(int i=0; i<n; i++) {
            long long ans=0, nodes=0;
            for(auto it : adj[i]) {
                nodes+=child[it]+1;
                if(ans==0) ans=child[it]+1;
                else ans=1ll*ans*(child[it]+1);
            }

            if(i!=0) {
                ans=(ans==0)?1:ans;
                ans=1ll*ans*(n-nodes-1);
            }

            if(ans>mx) {
                mx=ans; cnt=1;
            } else if(ans==mx) cnt++;
        }

        return cnt;
    }
};