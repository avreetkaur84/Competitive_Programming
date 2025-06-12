// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int memo(int idx, int buy, vector<vector<int>> &dp, vector<int>& prices) {
        if(idx>=prices.size()) return 0;

        if(dp[idx][buy]!=-1) return dp[idx][buy];

        if(buy==1) {
            // buy -> take or not take
            dp[idx][buy] = max(-prices[idx]+memo(idx+1, 0, dp, prices), 
                                memo(idx+1, 1, dp, prices));
        } else {
            // sell -> take or not take
            dp[idx][buy] = max(prices[idx]+memo(idx+2, 1, dp, prices), 
                                memo(idx+1, 0, dp, prices));
        }

        return dp[idx][buy];
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return memo(0, 1, dp, prices);
    }
};


// TABULATION
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return memo(0, 1, dp, prices);

        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=1; j++) {
                if(j==1) {
                    // buy
                    dp[i][j] = max(-prices[i]+dp[i+1][0], dp[i+1][j]);
                } else {
                    // sell
                    dp[i][j] = max(prices[i]+dp[i+2][1], dp[i+1][j]);
                }
            }
        }

        return dp[0][1];
    }