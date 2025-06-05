// Question Link - https://leetcode.com/problems/hand-of-straights/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    struct compare {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.first>b.first;
        }
    };

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        unordered_map<int, int> mp;

        for(int i=0; i<hand.size(); i++) mp[hand[i]]++;
        for(const auto& p : mp) {
            pq.push({p.first, p.second});
        }

        while(!pq.empty()) {
            vector<pair<int, int>> arr;
            int j=0;
            while(j<groupSize && !pq.empty()) {
                arr.push_back(pq.top()); pq.pop(); j++;
            }
            if(arr.size()!=groupSize) return false;

            for(int i=0; i<arr.size(); i++) {
                if(i<arr.size()-1 && arr[i].first+1 != arr[i+1].first) return false;
                if(arr[i].second>1) {
                    arr[i].second--; pq.push(arr[i]);
                }
            }
        }

        return true;
    }
};