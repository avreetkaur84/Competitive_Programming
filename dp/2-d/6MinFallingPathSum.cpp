// Question Link - https://leetcode.com/problems/minimum-falling-path-sum/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

    for(int j=0; j<n; j++) {
        dp[0][j] = matrix[0][j];
    }

    for(int i=1; i<m; i++) {
        for(int j=0; j<n; j++) {
            int left=INT_MAX, center=INT_MAX, right=INT_MAX;
            if(j-1>=0)    left = dp[i-1][j-1];
            if(j+1<n)    right = dp[i-1][j+1];
            center = dp[i-1][j];

            dp[i][j] = matrix[i][j]+min(left, min(center, right));
        }
    }

    int minn=INT_MAX;
    for(int j=0; j<n; j++) {
        minn = min(minn, dp[m-1][j]);
    }

    return minn;
}