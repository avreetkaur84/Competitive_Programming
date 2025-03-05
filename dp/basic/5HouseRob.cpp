// Question Link - https://leetcode.com/problems/house-robber/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// In this question, earlier I only took pick case and ignored non-pick case. So, I need to store the result of every index in the dp array.

class Solution {
    public:
        int memoization(vector<int>& nums, vector<int>& dp, int n) {
            if(n==0)    return nums[0];
            if(n<0) return 0;
    
            if(dp[n]!=-1)   return dp[n];
            
            int pick = nums[n] + memoization(nums, dp, n-2);
            int nonPick = memoization(nums, dp, n-1);
    
            dp[n] = max(pick, nonPick);
            // cout<<"dp[n]: "<<dp[n]<<"   ";
    
            return dp[n];
        }

        int tabulation(vector<int>& nums) {
            int n=nums.size();
            vector<int> dp(n, -1);

            if(n==1)    return nums[0];

            dp[0]=nums[0];
            dp[1]=max(nums[0], nums[1]);

            for(int i=2; i<n; i++) {
                int pick = nums[i]+dp[i-2];
                int nonPick = dp[i-1];
                dp[i] = max(pick, nonPick);
            }
            
            return dp[n-1];
        }
    
        int rob(vector<int>& nums) {
            int n=nums.size();
            vector<int> dp(n, -1);
            // dp[0]=nums[0];
    
            int res = memoization(nums, dp, n-1);
            return res;
        }
    };