// Question Link - https://leetcode.com/problems/find-number-of-coins-to-place-in-tree-nodes/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    /*
        subtree size < 3 -> 1 : means have to cal total children for all nodes
        cost of nodes already provided, we have to choose 3 nodes cost subtree
        how to cal the max prod of 3 nodes from n nodes?
            - we only req top 3 pos and top 2 neg
            - a = prod of 2 neg * 1 pos
            - b = prod of 3 pos
            - if no pos -> 0  
    */

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n);
        vector<long long> res(n);
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        auto mergeArr = [&](vector<int> arr) -> vector<int> {
            sort(arr.begin(), arr.end());
            if(arr.size()<=5) return arr;
            vector<int> final(5);
            int n=arr.size();
            final[0]=arr[0]; final[1]=arr[1];
            final[2]=arr[n-3]; final[3]=arr[n-2]; final[4]=arr[n-1];
            return final;
        };

        auto nodeCost = [&](vector<int> arr) -> long long {
            int n=arr.size();
            long long x=1ll*arr[n-1]*arr[n-2]*arr[n-3];  // all largest
            long long y=1ll*arr[0]*arr[1];     // 2 neg
            return max(max(x, 1ll*arr[n-1]*y), 0ll);
        };

        auto helper = [&](auto &&self, int node, int parent) -> pair<int, vector<int>> {
            int size=1;
            vector<int> val = {cost[node]};

            for(auto it : adj[node]) {
                if(it==parent) continue;
                auto [child, arr] = self(self, it, node);
                size+=child;
                for(auto it : arr) val.push_back(it);
            }

            vector<int> final = mergeArr(val);
            if(size<3) res[node] = 1;
            else res[node] = nodeCost(final);
            return {size, final};
        };

        helper(helper, 0, -1);
        return res;
    };
};