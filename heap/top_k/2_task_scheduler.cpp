// Question Link - https://leetcode.com/problems/task-scheduler/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Try to optimise this

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // max heap
        priority_queue<int> pq;
        queue<vector<int>> q;
        int arr[26] = {0};
        for(auto it : tasks) arr[it-'A']++;
        for(int i=0; i<26; i++) {
            if(arr[i]==0) continue;
            // cout<<arr[i]<<" "<<i<<"\n";
            pq.push(arr[i]);
        }

        int cur=0;
        while(!pq.empty() || !q.empty()) {
            while(!q.empty() && q.front()[0]+n<cur) {
                auto arr = q.front(); q.pop();
                pq.push(arr[1]);
            }

            if(!pq.empty()) {
                int u = pq.top(); pq.pop();
                // cout<<cur<<" "<<u<<"\n";
                if(u-1>0) {
                    q.push({cur, u-1});
                }
            }

            cur++;
        }

        return cur;
    }
};