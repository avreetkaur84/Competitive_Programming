// Question Link - https://leetcode.com/problems/house-robber-ii/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    int memoization(vector<int> &nums, vector<int> &dp, int start, int n)
    {
        // cout<<n<<"  ";
        if (n == start)
            return nums[start];
        if (n < start)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int pick = nums[n] + memoization(nums, dp, start, n - 2);
        int nonPick = memoization(nums, dp, start, n - 1);

        dp[n] = max(pick, nonPick);

        return dp[n];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // cout<<"Round 1: n values: ";
        int round1 = memoization(nums, dp1, 0, n - 2);
        // cout<<"dp[n]: "<<round1<<endl;
        // cout<<"Round 1: n values: ";
        int round2 = memoization(nums, dp2, 1, n - 1);
        // cout<<"dp[n]: "<<round2<<endl;

        return max(round1, round2);
    }
};