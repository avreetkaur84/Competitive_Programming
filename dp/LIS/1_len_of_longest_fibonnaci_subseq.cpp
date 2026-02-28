// Question Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/?envType=problem-list-v2&envId=wwa0cvsi

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// MLE
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& nums) {
        int n=nums.size(); 
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1,-1)));

        auto rec = [&](auto &&self, int prev_1, int prev_2, int idx) -> int {
            if(idx>=n) return 0;
            if(dp[prev_1+1][prev_2+1][idx+1]!=-1) return dp[prev_1+1][prev_2+1][idx+1];

            int non_pick=0, pick=0;
            non_pick = self(self, prev_1, prev_2, idx+1);
            if(prev_1!=-1 && prev_2!=-1 && (nums[prev_1]+nums[prev_2]==nums[idx])) {
                pick = 1+self(self, prev_2, idx, idx+1);
            } else if(prev_2==-1 || prev_1==-1) {
                pick = 1+self(self, prev_2, idx, idx+1);
            }

            // cout<<prev_1<<" "<<prev_2<<" "<<idx<<" ";
            // cout<<pick<<" "<<non_pick<<" "<<max(pick, non_pick)<<"\n";
            return dp[prev_1+1][prev_2+1][idx+1] = max(pick, non_pick);
        };

        // for(int )

        int res = rec(rec, -1, -1, 0);        
        return (res<=2)?0:res;
    }
};