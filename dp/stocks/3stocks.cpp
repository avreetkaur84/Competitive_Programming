// Question Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Memoization {
public:
    int rec(int idx, int n, int buy, int cap, vector<int>& prices,  vector<vector<vector<int>>> &dp) {
        if(idx==n || cap==0) return 0;

        if(dp[idx][buy][cap]!=-1)    return dp[idx][buy][cap];

        if(buy==1) {
            dp[idx][buy][cap] = max(-prices[idx]+rec(idx+1, n, 0, cap, prices, dp), rec(idx+1, n, 1, cap, prices, dp));
        } else {
            dp[idx][buy][cap] = max(prices[idx]+rec(idx+1, n, 1, cap-1, prices, dp), rec(idx+1, n, 0, cap, prices, dp));
        }

        return dp[idx][buy][cap]; 
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>
                                (2, vector<int>(3, -1)));
        return rec(0, n, 1, 2, prices, dp);
    }
};

int tabulation(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>
                                (2, vector<int>(3, 0)));

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=1; j++) {
                for(int k=1; k<=2; k++) {
                    if(j==0) {
                        // sell
                        dp[i][j][k]=max(prices[i]+dp[i+1][1][k-1], dp[i+1][j][k]);
                    } else {
                        dp[i][j][k]=max(-prices[i]+dp[i+1][0][k], dp[i+1][j][k]);
                    }
                }
            }
        }
        
        return dp[0][1][2];
    }