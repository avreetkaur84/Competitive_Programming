// Question Link - https://leetcode.com/problems/climbing-stairs/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
    public:
        int climbStairs(int n) {
            // tabulation approach.
            vector<int> dp(n+1);
            dp[0]=1, dp[1]=1;
    
            for(int i=2; i<=n; i++) {
                dp[i] = dp[i-1]+dp[i-2];
            }
    
            return dp[n];
        }
    };