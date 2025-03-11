// Question Link - https://leetcode.com/problems/triangle/description/

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

int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size();
    int n = triangle[m-1].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

    dp[0][0]=triangle[0][0];
    for(int i=1; i<m; i++) {
        dp[i][0] = triangle[i][0]+dp[i-1][0];
    }

    for(int i=1; i<m; i++) {
        for(int j=1; j<i+1; j++) {
            // if(triangle[i][j]==INT_MAX) continue;
            int top = dp[i-1][j];
            int topleft = dp[i-1][j-1];
            
            dp[i][j] = triangle[i][j]+min(top, topleft);
        }
    }

    // print2DVector(dp);

    int minn=INT_MAX;
    for(int j=0; j<n; j++) {
        minn = min(minn, dp[m-1][j]);
    }

    return minn;
}