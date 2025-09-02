// Question Link - https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    MY MISTAKES-
    1. Need to read the quesion throughly first, and should not just focus on technique, but need to focus on solvign the probem.
    To exemplify - I saw the question and thought it is similar to greedy question of meetings that I did nefore, so without even reading teh entire question properly, I just jumped to the solution, so I wasted half an hour in applyign the wrong technique. This question was easy, if I had started to solve it by reading it throughly instead of just focusing in applying techniques.
*/

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int best=INT_MAX; int n=landStartTime.size(), m=waterStartTime.size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int l_end=landStartTime[i]+landDuration[i];
                int w_end=waterStartTime[j]+waterDuration[j];

                if(landStartTime[i]<=waterStartTime[j]) {
                    int x=0;
                    if(waterStartTime[j]<=l_end) x = l_end+waterDuration[j];
                    else x = waterStartTime[j]+waterDuration[j];
                    best = min(best, x);
                } else {
                    int x=0;
                    if(landStartTime[i]<=w_end) x = w_end+landDuration[i];
                    else x = landStartTime[i]+landDuration[i];
                    best = min(best, x);
                }
            }
        }

        return best;
    }
};