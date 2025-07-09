// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
  public:
    int helper(int idx, int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
        if(idx<=0 || capacity==0) return 0;
        
        if(dp[idx][capacity] != -1) return dp[idx][capacity];
        
        if(capacity>=wt[idx-1]) {
            int pick = val[idx-1]+helper(idx, capacity-wt[idx-1], val, wt, dp);
            int non_pick = helper(idx-1, capacity, val, wt, dp);
            dp[idx][capacity] = max(pick, non_pick);
        } else {
            dp[idx][capacity] = helper(idx-1, capacity, val, wt, dp);
        }
        
        return dp[idx][capacity];
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<vector<int>> dp(n+1, vector<int> (capacity+1, -1));
        return helper(n, capacity, val, wt, dp);
    }
};


// TABULATION
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<vector<int>> dp(n+1, vector<int> (capacity+1, 0));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=capacity; j++) {
                if(j>=wt[i-1]) {
                    int pick = val[i-1]+dp[i][j-wt[i-1]];
                    int non_pick = dp[i-1][j];
                    dp[i][j] = max(pick, non_pick);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][capacity];
    }
};