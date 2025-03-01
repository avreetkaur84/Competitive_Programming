// Question Link -https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int memoization(vector<int> &height, vector<int> &dp, int n)
    {
        int left = 0, right = 0;
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        left = memoization(height, dp, n - 1) + abs(height[n] - height[n - 1]);

        if (n > 1)
            right = memoization(height, dp, n - 2) + abs(height[n] - height[n - 2]);
        else
            right = left;

        return dp[n] = min(left, right);
    }

    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n, -1);

        return memoization(height, dp, n - 1);
    }

    int Tabulation(vector<int>& height) {
        int n = height.size();
        vector<int> d(n, -1);
        
        d[0]=0;
        d[1]=abs(height[1]-height[0]);
        
        for(int i=2; i<n; i++) {
            int left = d[i-1]+abs(height[i]-height[i-1]);
            int right = d[i-2]+abs(height[i]-height[i-2]);
            d[i] = min(left, right);
        }
        
        return d[n-1];
    }
};