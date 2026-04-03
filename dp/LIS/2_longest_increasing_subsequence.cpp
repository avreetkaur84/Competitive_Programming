// Question Link: https://leetcode.com/problems/longest-increasing-subsequence/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Greedy Approach: when we only need length
    Intution: [2, 5] is better than [2, 10]
    so, we are having a tails array that keeps the smallest elements that can end till ith
    means, if we encounter a element smaller than already present elements in tail at any index, then we replace that element with cur smallest. 
    1 3 5 7 8 -> cur = 6 -> (7>6) -> so we will replace 7 with 6
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> tails;

        for(auto it : nums) {
            if(tails.empty() || tails.back()<it) tails.push_back(it);
            else {
                int idx = lower_bound(tails.begin(), tails.end(), it)-tails.begin();
                tails[idx]=it;
            } 
        }

        return tails.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        auto rec = [&](auto &&self, int prev, int idx) -> int {
            if(idx>=n) return 0;
            if(dp[prev+1][idx+1]!=-1) return dp[prev+1][idx+1];

            int pick=0, non_pick=0;
            non_pick = self(self, prev, idx+1);
            if(prev==-1 || nums[prev]<nums[idx]) {
                pick = 1+self(self, idx, idx+1);
            }

            return dp[prev+1][idx+1]=max(pick, non_pick);
        };

        return rec(rec, -1, 0);
    }
};