// Question Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int memo(int idx, int buy, vector<vector<int>> &dp, vector<int>& prices, int fee) {
        if(idx>=prices.size()) return 0;

        if(dp[idx][buy]!=-1) return dp[idx][buy];

        if(buy==1) {
            // buy
            dp[idx][buy] = max(-prices[idx]+memo(idx+1, 0, dp, prices, fee), 
                                memo(idx+1, 1, dp, prices, fee));
        } else {
            // sell -> add fees
            dp[idx][buy] = max(prices[idx]+memo(idx+1, 1, dp, prices, fee)-fee, 
                                memo(idx+1, 0, dp, prices, fee));
        }

        return dp[idx][buy];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // vector<vector<int>> dp(n, vector<int> (2, -1));
        // return memo(0, 1, dp, prices, fee);

        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=1; j++) {
                if(j==1) {
                    dp[i][j] = max(-prices[i]+dp[i+1][0], dp[i+1][j]);
                } else {
                    dp[i][j] = max(prices[i]+dp[i+1][1]-fee, dp[i+1][j]);
                }
            }
        }

        return dp[0][1];
    }
};