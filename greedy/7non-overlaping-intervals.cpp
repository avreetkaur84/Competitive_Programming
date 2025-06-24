// Question Link - https://leetcode.com/problems/non-overlapping-intervals/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    struct compareSecond {
        bool operator()(const vector<int> a, const vector<int> b) {
            return a[1]<b[1];
        }
    };

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort on basis of start time ->brutual mistake -> very bad
        // sort on basis of end time
        if(intervals.size()<=1) return 0;
        sort(intervals.begin(), intervals.end(), compareSecond());

        int cnt=0, n=intervals.size();
        int i=0, j=1, et=-1, st=-1;

        // for(int i=0; i<n; i++) {
        //     cout<<intervals[i][0]<<" : "<<intervals[i][1]<<endl;
        // }
        
        while(i<n && j<n) {
            et=intervals[i][1];
            st=intervals[j][0];
            if(et>st) cnt++;
            else i=j;

            j++;
        }

        return cnt;
    }
};