// Question Link - https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// FINALLY!!! AFTER TWO DAYS!!! FINALLY GOT AC!!

// Memo - GOT TLE
class Solution {
public:
    int helper(int idx, int cur, vector<int> &coins, vector<vector<int>> &dp) {
        if(idx<=0) {
            if(cur%coins[idx]==0) return cur/coins[idx];
            else return 1e9;
        }

        int pick = 1e9;
        if(cur>=coins[idx]) {
            pick = 1+helper(idx, cur-coins[idx], coins, dp);
        }
        int non_pick = helper(idx-1, cur, coins, dp);

        return dp[idx][cur] = min(pick, non_pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int res = helper(n-1, amount, coins, dp);
        
        if(res==1e9) return -1;
        else return res;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, INT_MAX-1));
        
        for(int i=0; i<n; i++) dp[i][0]=0;
        for(int j=1; j<=amount; j++) {
            if(j%coins[0]==0) dp[0][j]=j/coins[0];
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<=amount; j++) {
                int pick = 1e9;
                if(coins[i]<=j) {
                    pick = 1+dp[i][j-coins[i]];
                }
                int non_pick = dp[i-1][j];
                dp[i][j] = min(pick, non_pick);
            }
        }

        if(dp[n-1][amount]>=1e9) return -1;
        else return dp[n-1][amount];
    }
};