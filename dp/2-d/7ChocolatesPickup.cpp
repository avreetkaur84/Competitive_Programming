// Question Link - https://www.geeksforgeeks.org/problems/chocolates-pickup/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=chocolates-pickup

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

int solve(int n, int m, vector<vector<int>>& grid) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int res=0, sum=0;
    
    for(int j=0; j<m; j++) {
        dp[0][j]=grid[0][j];
    }
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            int r1_left=INT_MIN, r1_center=INT_MIN, r1_right=INT_MIN;
            
            if(j-1>0) r1_left = grid[i][j]+dp[i-1][j-1];
            if(j+1<m) r1_right = grid[i][j]+dp[i-1][j+1];
            r1_center = grid[i][j]+dp[i-1][j];

            int r1_max = max(r1_left, max(r1_right, r1_center));
            dp[i][j]=r1_max;
            
            int rj = m-j-1;
            int r2_left=INT_MIN, r2_center=INT_MIN, r2_right=INT_MIN;
            
            if(rj-1>0) r2_left = grid[i][rj]+dp[i-1][rj-1];
            if(rj+1<m) r2_right = grid[i][rj]+dp[i-1][rj+1];
            r2_center = grid[i][rj]+dp[i-1][rj];
            
            int r2_max = max(r2_left, max(r2_right, r2_center));
            dp[i][rj]=r2_max;
            
            if(j==rj) {
                int r2_smax = max(r2_right, r2_center);
                int r1_sum = r1_max+r2_smax;
                
                int r1_smax = max(r1_left, r1_center);
                int r2_sum = r2_max+r1_smax;
                
                res = max(r1_sum, r2_sum);
                if(res==r1_sum) {
                    r1_max = res;
                    r2_max = r2_smax;
                } else {
                    r2_max = res;
                    r1_max = r1_smax;
                }
                
                dp[i][j]=res;
            }
            
            sum = r1_max+r2_max;
        }
    }
    
    print2DVector(dp);
    return sum;
}