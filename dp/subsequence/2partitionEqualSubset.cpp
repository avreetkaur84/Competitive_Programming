// Question Link - https://leetcode.com/problems/partition-equal-subset-sum/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

    bool cal(vector<int>& nums, int idx, int target, int n, vector<vector<int>> &dp) {
        if(target==0)   return true;
        if(idx>=n)   return false;

        if(dp[idx][target]!=-1) return dp[idx][target];

        bool nonPick = cal(nums, idx+1, target, n, dp);
        bool pick = false;
        if(target>=nums[idx]) {
            pick = cal(nums, idx+1, target-nums[idx], n, dp);
        }

        return dp[idx][target]=pick||nonPick;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int summ = accumulate(nums.begin(), nums.end(), 0);
        if(summ%2!=0)   return false;
        summ/=2;

        vector<vector<bool>> dp(n, vector<bool>(summ+1, false));

        // TABULATION
        for(int i=0; i<n; i++)   dp[i][0]=true;
        if(nums[0]<=summ)  dp[0][nums[0]]=true;

        for(int i=1; i<n; i++) {
            for(int tar=1; tar<=summ; tar++) {
                bool nonPick = dp[i-1][tar];
                bool pick=false;
                if(tar>=nums[i]) {
                    pick = dp[i-1][tar-nums[i]];
                }
                dp[i][tar]=pick||nonPick;
            }
        }

        return dp[n-1][summ];

        // bool flag = cal(nums, 0, summ, n, dp);
        // return flag;
    }