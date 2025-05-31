// Question Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int memo(int idx, int n, int buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp) {
        if(idx==n || k==0) return 0;

        if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];

        if(buy==1) {
            // buy
            dp[idx][buy][k] = max(-prices[idx]+memo(idx+1, n, 0, k, prices, dp),
                                    memo(idx+1, n, 1, k, prices, dp));
        } else {
            // sell
            dp[idx][buy][k] = max(prices[idx]+memo(idx+1, n, 1, k-1, prices, dp),
                                    memo(idx+1, n, 0, k, prices, dp));
        }

        return dp[idx][buy][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=1; j++) {
                for(int l=1; l<=k; l++) {
                    if(j==1) {
                        // buy
                        dp[i][j][l]=max(-prices[i]+dp[i+1][0][l], dp[i+1][j][l]);
                    } else {
                        // sell
                        dp[i][j][l]=max(prices[i]+dp[i+1][1][l-1], dp[i+1][j][l]);
                    }
                }
            }
        }
        
        return dp[0][1][k];
    }
};