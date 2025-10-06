// Question Link - https://leetcode.com/problems/target-sum/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Built everything from scratch 
/*
    This sum used offset based dp, means sum can go from range -sum to +sum and as indices can't be negative, so we took sum offset, and now both positive and negative values can be accomodated
*/


class Solution {
public:
    int helper(int idx, int cur, int target, vector<int> &nums, vector<vector<int>> &dp, int summ) {
        if(idx<0) return cur==target ? 1 : 0;
        if(dp[idx][cur+summ] != -1) return dp[idx][cur+summ];

        int pick_pos = helper(idx-1, cur+nums[idx], target, nums, dp, summ);
        int pick_neg = helper(idx-1, cur-nums[idx], target, nums, dp, summ);

        return dp[idx][cur+summ] = pick_pos+pick_neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int summ = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n, vector<int> (2*summ+1, -1));
        return helper(n-1, 0, target, nums, dp, summ);
    }
};