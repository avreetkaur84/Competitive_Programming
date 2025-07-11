// Question Link - https://leetcode.com/problems/coin-change-ii/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    I am fucking done with this question - for the 30th case I ma getting integer overflow error!!!!!!!!
    - This question ran successfully with memoization but gave interger overflow error for tabulation!! weired

    We will first see if we can generate amount from coin[0], then from coin[1] and coin[0], coin[1] combination/ IN this way we will move forward and will keep on adding the ways.
    -Either I will become insane, or I will rise above the level of sanity after doing this DSA.
    - So, I am pretty confused now. Here we have to calculate the number of ways in which we can obtain the given amount. But, I am confusing ut with minimum number of coins needed to obtain the given amount. 
    - I am juggling between these two questions and confusing both with each other.
    - For obtaining no. of ways, we have to add pick and non pick result. We don't hvave to think uch for non-pick result. 
    - For pick result - we will do 1+dp[i][j-nums[i]], thne add pick and non-pick, won't it give wrong results, I am fucking confused
    - let's code:
    - for tabulaiton, we ddon't have to explicitly add 1.
    - FISHHHH - Code worked, passed 29/30 cases!!! 
*/


class Solution {
public:
    // void PArray(vector<vector<int>> &dp) {
    //     for(int i=0; i<dp.size(); i++) {
    //         for(int j=0; j<dp[0].size(); j++) {
    //             cout<<dp[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }

    int helper(int idx, int cur, vector<int> &coins, vector<vector<int>> &dp) {
        if(cur==0) return 1;
        if(idx<=0) return 0;

        if(dp[idx][cur]!=-1) return dp[idx][cur];

        int pick=0;
        if(cur>=coins[idx-1]) {
            pick = helper(idx, cur-coins[idx-1], coins, dp);
        }
        int non_pick = helper(idx-1, cur, coins, dp);
        
        return dp[idx][cur]=pick+non_pick;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        return helper(n, amount, coins, dp);

        // for(int i=0; i<=n; i++) dp[i][0]=1;

        // for(int i=1; i<=n; i++) {
        //     for(int j=1; j<=amount; j++) {
        //         int pick=0;
        //         if(j>=coins[i-1]) {
        //             pick = dp[i][j-coins[i-1]];
        //         }

        //         dp[i][j] = dp[i-1][j]+pick;
        //     }
        // }
        
        // PArray(dp);
        // return dp[n][amount];
    }
};