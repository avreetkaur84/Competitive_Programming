// Question Link - https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
  public:  
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        priority_queue<vector<int>> pq; // max heap: {sum, idx_a, idx_b}
        set<pair<int, int>> st;   // {idx_a, idx_b}
        vector<int> res;
        int n=a.size(), m=b.size();
        
        pq.push({a[n-1]+b[m-1], n-1, m-1});
        st.insert({n-1, m-1});
        while(res.size()<k) {
            vector<int> x = pq.top(); pq.pop();
            res.push_back(x[0]);
            if(x[1]-1>=0 && !st.count({x[1]-1, x[2]})) {
                pq.push({a[x[1]-1]+b[x[2]], x[1]-1, x[2]});
                st.insert({x[1]-1, x[2]});
            }
            
            if(x[2]-1>=0 && !st.count({x[1], x[2]-1})) {
                pq.push({a[x[1]]+b[x[2]-1], x[1], x[2]-1});
                st.insert({x[1], x[2]-1});
            }
        }
        
        return res;
    }
};