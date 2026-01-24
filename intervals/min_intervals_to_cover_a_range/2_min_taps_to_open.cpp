// Question Link: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        we need area -> then start with maxx area 
        10^4 -> nlogn

    */
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> interval;
        for(int i=0; i<ranges.size(); i++) {
            interval.push_back({max(0, i-ranges[i]), min(i+ranges[i], n)});
        }

        sort(interval.begin(), interval.end());
        // for(auto it : interval) cout<<it.first<<" "<<it.second<<", ";
        // cout<<"\n";

        int tap=0, covered=0, next_end=0;
        for(int i=0; i<interval.size(); i++) {
            // when no chance
            if(next_end<interval[i].first) return -1;
            if(covered<interval[i].first) {
                // open tap -> cant go further
                tap++; covered=next_end; 
            }
            next_end=max(next_end, interval[i].second);
        }

        if(covered<n) {
            if(next_end==n) tap++;
            else return -1;
        }

        return tap;
    }
};