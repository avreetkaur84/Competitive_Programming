// Question Link - https://leetcode.com/problems/partition-equal-subset-sum/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// SECOND TRY -> INTUTION AND EVERYTHING DID ON MY OWN
class Recursion {
public:
    /*
        Do the total sum of array, then divide it by 2, and set the resultant as target. If the target is achieved, means array can be divided into two equal subsets.
    */

    bool helper(int idx, int target, vector<int> nums) {
        if(target==0) return true;
        if(idx>=nums.size()) return false;

        bool non_pick = helper(idx+1, target, nums);
        bool pick = false;
        if(target-nums[idx]>=0) {
            pick = helper(idx+1, target-nums[idx], nums);
        }

        return non_pick || pick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;

        return helper(0, sum/2, nums);
    }
};


    bool helper(int idx, int target, vector<int> nums, vector<vector<int>> &dp) {
        if(target==0) return true;
        if(idx>=nums.size()) return false;

        if(dp[idx][target] != -1) return dp[idx][target];

        bool non_pick = helper(idx+1, target, nums, dp);
        bool pick = false;
        if(target-nums[idx]>=0) {
            pick = helper(idx+1, target-nums[idx], nums, dp);
        }

        return dp[idx][target] = non_pick || pick;
    }

    // tabulation
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false; 
        int target = sum/2, n=nums.size();
        vector<vector<bool>> dp(nums.size()+1, vector<bool> (target+1, false));

        for(int i=0; i<=n; i++) dp[i][0]=true;
        // if(nums[0]<=target) dp[0][nums[0]]=true;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=target; j++) {
                bool non_pick = dp[i-1][j];
                bool pick = false;
                if(j-nums[i-1]>=0) {
                    pick = dp[i-1][j-nums[i-1]];
                }

                dp[i][j] = pick || non_pick;
            }
        }

        return dp[n][target];
    }





// FIRST TRY

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