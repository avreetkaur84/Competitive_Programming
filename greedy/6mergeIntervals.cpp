// Question Link - https://leetcode.com/problems/merge-intervals/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return intervals;

        sort(intervals.begin(), intervals.end());
        int n=intervals.size();
        vector<vector<int>> arr;

        // for(vector<int> i : intervals) {
        //     cout<<i[0]<<"   "<<i[1]<<endl;
        // }

        int i=0, j=0, et=intervals[0][1];
        while(j<n) {
            while(i+1<n && intervals[i][0]==intervals[i+1][0]) {
                i++; j++;
                et=intervals[i][1];
            }

            if(et<intervals[j][0]) {
                // et = max(et, intervals[j][1]);
                int st = intervals[i][0];                
                arr.push_back({st, et});
                i=j; et = max(et, intervals[j][1]); j--;
            } 

            et = max(et, intervals[j][1]);
            // cout<<j<<"  "<<intervals[i][1]<<"    "<<et<<endl;
            j++;
        }

        arr.push_back({intervals[i][0], et});

        return arr;
    }
};