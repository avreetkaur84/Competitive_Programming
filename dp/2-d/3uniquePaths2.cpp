// Question Link - https://leetcode.com/problems/unique-paths-ii/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int memoization(int m, int n, int r, int d, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp) {
    if(d>m || r>n)  return 0;
    if(d==m && r==n)    return 1;
    if(obstacleGrid[d][r]==1)   return 0;  //obstacle

    if(dp[d][r]!=-1)    return dp[d][r];

    int right = memoization(m, n, r+1, d, obstacleGrid, dp);
    int down = memoization(m, n, r, d+1, obstacleGrid, dp);

    return dp[d][r] = right+down;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    if(obstacleGrid[m-1][n-1]==1)   return 0;

    return memoization(m-1, n-1, 0, 0, obstacleGrid, dp);
}

int tabulation(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
        return 0;
    }

    dp[0][0] = 1;

        for(int i=1; i<m; i++) {
            if(obstacleGrid[i][0]==1)  {
                dp[i][0]=0; break;
            }
            else dp[i][0]=1;
            cout<<"dp"<<i<<0<<": "<<dp[i][0]<<"  ";
        }

        for(int j=1; j<n; j++) {
        if(obstacleGrid[0][j]==1) {
             dp[0][j]=0;    break;
        }
        else dp[0][j]=1;
    }
    

    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(obstacleGrid[i][j]==1) dp[i][j]=0;
            else {
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
            // cout<<"dp"<<i<<j<<": "<<dp[i][j]<<"  ";
        }
    }

    return dp[m-1][n-1];
}