// Question Link - https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// RECURSIVE - 1ST - 1 JULY, 2025
class Solution {
  public:
    int helper(int idx, int w, vector<int> &wt, vector<int> &val) {
        // BASE CASE - 
        // FIRST - I am startng from 0 idx and till n-1
        // Second - Weight can't go beyond 0 - we will subtract weight
        if(idx>=wt.size() || w<=0) return 0;
        
        // CHOICE DIAGRAM - 
        // FIRST - only choose that item whose weight is less than bag limit
        // SECOND - pick and non-pick - try both
        if(wt[idx]<=w) {
            int pick = val[idx] + helper(idx+1, w-wt[idx], wt, val);
            int non_pick = helper(idx+1, w, wt, val);
            return max(pick, non_pick);
        } else {
            return helper(idx+1, w, wt, val);
        }
        
        // I think I should return some value here too, or I will get default error
        
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        return helper(0, W, wt, val);
    }
};

// MEMOIZATION
class Solution {
  public:
    /*
        for memoization - I will make dp array of idx and weight, here idx is changing with each call and also the weight of the bag.
        So, by tracking idx and weight, we can find the max value.
        We won't take wt array or val array, as they are considered in idx only.
    */
  
    int helper(int idx, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
        // BASE CASE - 
        // FIRST - I am startng from 0 idx and till n-1
        // Second - Weight can't go beyond 0 - we will subtract weight
        if(idx>=wt.size() || w<=0) return 0;
        
        if(dp[idx][w] != -1) return dp[idx][w];
        
        // CHOICE DIAGRAM - 
        // FIRST - only choose that item whose weight is less than bag limit
        // SECOND - pick and non-pick - try both
        if(wt[idx]<=w) {
            int pick = val[idx] + helper(idx+1, w-wt[idx], wt, val, dp);
            int non_pick = helper(idx+1, w, wt, val, dp);
            return dp[idx][w] = max(pick, non_pick);
        } else {
            return dp[idx][w] = helper(idx+1, w, wt, val, dp);
        }
        
        // I think I should return some value here too, or I will get default error
        
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int> (W+1, -1));
        return helper(0, W, wt, val, dp);
    }
};


// TABULATION
// It isvery important to dry run the code on notebbok, like make the box and fill it
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=W; j++) {
                if(j>=wt[i-1]) {
                    int non_pick = dp[i-1][j];
                    int pick = val[i-1]+dp[i-1][j-wt[i-1]];
                    dp[i][j] = max(non_pick, pick);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][W];
        
    }
};