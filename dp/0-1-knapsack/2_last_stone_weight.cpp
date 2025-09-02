// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

class Solution {
public:
    int memo(int idx, int cur, int target, vector<int>& stones, vector<vector<int>>& dp) {
        if(idx < 0) return cur; 
        if(dp[idx][cur] != -1) return dp[idx][cur];

        int non_pick = memo(idx-1, cur, target, stones, dp);
        int pick = 0;
        if(cur+stones[idx] <= target) {
            pick = memo(idx-1, cur+stones[idx], target, stones, dp);
        }

        return dp[idx][cur] = max(non_pick, pick);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;

        vector<vector<int>> dp(stones.size(), vector<int>(target+1, -1));
        int best = memo(stones.size()-1, 0, target, stones, dp);

        return abs(sum - 2*best);
    }
};
