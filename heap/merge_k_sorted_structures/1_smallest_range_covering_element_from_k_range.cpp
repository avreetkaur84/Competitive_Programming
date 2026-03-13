// Question Link - https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        // Merge the k sorted lists
        vector<pair<int, int>> arr;   // {number, list}
        // min heap
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // {number, idx, list}
        for(int i=0; i<nums.size(); i++) {
            pq.push({nums[i][0], 0, i});
        }

        while(!pq.empty()) {
            auto x = pq.top(); pq.pop();
            arr.push_back({x[0], x[2]});
            if(x[1]+1<nums[x[2]].size()) {
                pq.push({nums[x[2]][x[1]+1], x[1]+1, x[2]});
            }
        }

        // find the min range that contain all the lists
        unordered_map<int, int> mp;  // list, fq
        int minn=INT_MAX, st=-1, end=-1;
        int i=0, n=arr.size();
        for(int j=0; j<n; j++) {
            mp[arr[j].second]++;

            while(i<n && mp.size()>=k) {
                if(mp.size()==k && (arr[j].first-arr[i].first+1)<minn) {
                    minn=arr[j].first-arr[i].first+1; 
                    st=arr[i].first; end=arr[j].first;
                }

                mp[arr[i].second]--;
                if(mp[arr[i].second]==0) mp.erase(arr[i].second);
                i++;
            }

            if(mp.size()==k && (j-i+1)<minn) {
                minn=j-i+1; st=arr[i].first; end=arr[j].first;
            }
        }

        return {st, end};
    }
};