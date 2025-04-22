// Question Link - https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


// MEMOIZATION
int recursive(int day, int last, vector<vector<int>> &points, vector<vector<int>>& dp) {
    if (dp[day][last] != -1) return dp[day][last];
    
    if(day==0) {
        int maxx=0;
        // not to add anything, as in starting, we are only taking first activity, base case
        for(int i=0; i<=2; i++) {
            if(i!=last) {
                maxx = max(maxx, points[day][i]);
            }
        }
        dp[day][last]=maxx;
        return maxx;
    }
    
    int maxx=0;
    // for activity
    for(int i=0; i<=2; i++) {
        if(i!=last) {
            int taskPoint = points[day][i] + recursive(day-1, i, points, dp);
            maxx = max(maxx, taskPoint);
        }
    }
    
    dp[day][last]=maxx;
    return dp[day][last];
}

int maximumPoints(vector<vector<int>>& arr) {
    int n = arr.size();
    // dp[days][activity] 
    vector<vector<int>> dp(n, vector<int> (4, -1));
    int maxx = recursive(n-1, 3, arr, dp);
    return maxx;
}


// TABULATION
int func(int day, int last, vector<vector<int>> &dp) {
    int maxx=0;
    for(int i=0; i<3; i++) {
        if(i!=last) {
            maxx = max(maxx, dp[day-1][i]);
        }
    }
    
    return maxx;
}

int maximumPoints(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (4, -1));
    
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    
    int maxx=0;
    
    for(int day=1; day<n; day++) {
        for(int acti=0; acti<3; acti++) {
            dp[day][acti] = arr[day][acti] + func(day, acti, dp);
        }
    }
    
    // maxx = func(n-1, 3, dp);
    maxx = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    
    return maxx;
}