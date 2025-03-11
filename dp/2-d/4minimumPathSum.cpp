// Question Link - https://leetcode.com/problems/minimum-path-sum/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print2DVector(const vector<vector<int>>& vec) {
    for (const auto& row : vec) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int memoization(int m, int n, int down, int right, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if(down==m && right==n) {
        return grid[m][n];
    }

    if(down>m || right>n)   return INT_MAX;

    if(dp[down][right]!=-1) return dp[down][right];

    int downVal = memoization(m, n, down+1, right, grid, dp);
    int rightVal = memoization(m, n, down, right+1, grid, dp);

    return dp[down][right] = grid[down][right] + min(downVal, rightVal);
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // dp[m-1][n-1]=grid[m-1][n-1];

    int res = memoization(m-1, n-1, 0, 0, grid, dp);
    print2DVector(dp);
    return res;
}

int tabulation(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0]=grid[0][0];
    for(int i=1; i<m; i++) {
        dp[i][0] = grid[i][0]+dp[i-1][0];
    }

    for(int j=1; j<n; j++) {
        dp[0][j] = grid[0][j]+dp[0][j-1];
    }

    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            int down = dp[i-1][j];
            int right = dp[i][j-1];

            dp[i][j] = grid[i][j] + min(down, right);
        }
    }

    print2DVector(dp);
    return dp[m-1][n-1];
}