// Question Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// greedy

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0; 

        for(int i=1; i<prices.size(); i++) {
            if(prices[i-1]<prices[i]) {
                p+=(prices[i]-prices[i-1]);
            }
        }


        // missed the main line, I can buy and sell the stock on same day, means I just can't hold more than one stock but can buy and sell both on same day, missed this point in below solution.

        // while(j<prices.size()) {
        //     if(prices[i]<prices[j]) {
        //         if(prices[j]-prices[i] < prices[j+1]-prices[i]) {
        //             j++;
        //         } else {
        //             p += prices[j]-prices[i];
        //             i=j+1; j=i+1;
        //         }
        //         // cout<<prices[i]<<"  "<<prices[j]<<"  "<<p<<endl;
        //     } 
        //     else {
        //         i++; j++;
        //         // cout<<prices[i]<<"  "<<prices[j]<<"  "<<p<<endl;
        //     }

            
        //     // cout<<i<<"  "<<j<<"  "<<p<<endl;
        // }

        return p;
    }
};


// memoization
class Solution {
public:
    int rec(int idx, int n, int buy, vector<int>& prices,  vector<vector<int>> &dp) {
        if(idx==n) return 0;

        if(dp[idx][buy]!=-1)    return dp[idx][buy];

        if(buy==1) {
            // buy -> take/not take
            dp[idx][buy] = max(-prices[idx]+rec(idx+1, n, 0, prices, dp), 
                        0+rec(idx+1, n, 1, prices, dp));
        } else {
            // sell -> take/not take
            dp[idx][buy] = max(prices[idx]+rec(idx+1, n, 1, prices, dp), 
                        0+rec(idx+1, n, 0, prices, dp));
        }

        return dp[idx][buy]; 
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return rec(0, n, 1, prices, dp);
    }
};

// tabulation
    int tabulation(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        dp[n][0] = dp[n][1] = 0;

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=1; j++) {
                if(j==0) {
                    // sell
                    dp[i][0] = max(prices[i]+dp[i+1][1], dp[i+1][0]);
                } else {
                    // buy
                    dp[i][1] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
                }
            }
        }

        return dp[0][1];
    }