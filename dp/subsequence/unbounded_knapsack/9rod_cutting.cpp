// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    So, here we are having the price array, where each index of price[i], tells the price of selling the piece of length i.
    We are given rod of length n and we have to see max price that we can get from selling the wood
    1. DP State -> 
        - rod size - idx - means we will check for size 1, then for 2, 3 and son on 
        - max price we can get - by accumulating all prices, but problem is 1 price[i] can be of range 10^6 and n can be 10^3 -> so, adding all, can result in MLE, so, I am not sure how I should consider tis price range
        
*/


class Solution {
  public:
    int helper(int idx, int len, vector<int> &price, vector<vector<int>> dp)  {
        if(len<=0 || idx<=0) return 0;
        
        if(dp[idx][len]!=-1) return dp[idx][len];
        
        if(len>=idx) {
            int pick = price[idx-1]+helper(idx, len-idx, price, dp);
            int non_pick = helper(idx-1, len, price, dp);
            dp[idx][len] = max(pick, non_pick);
        } else {
            dp[idx][len] = helper(idx-1, len, price, dp);
        }
        
        return dp[idx][len];
    }
  
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(j>=i) {
                    int pick = price[i-1]+dp[i][j-i];
                    int non_pick = dp[i-1][j];
                    dp[i][j] = max(pick, non_pick);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][n];
    }
};