// Question Link - https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
  public:
    struct compare {
        bool operator()(const vector<int> &a, const vector<int> &b) const {
            return a[1]<b[1];
        }
    };
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<vector<int>> res;
        int n = start.size(), cnt=0, freeTime=-1;
        
        for(int i=0; i<n; i++) {
            res.push_back({start[i], end[i], i});
        }
        
        // sort according to meeting end time
        sort(res.begin(), res.end(), compare());
        
        // for(int i=0; i<res.size(); i++) cout<<res[i][2]<<"  ";
        // cout<<endl;
        
        for(int i=0; i<res.size(); i++) {
            if(res[i][0]>freeTime) {
                cnt++; freeTime=res[i][1];
            }
        }
        
        return cnt;
    }
};