// Question Link - https://leetcode.com/problems/distinct-subsequences/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    /*
        we need to generate all subsequences and check which equals t
        for smart prunning, we can cut the branch where lenght is greater than t
        but this will still give TLE, lets try
        We have to store all subsequences in order to check, or I can stote only index and then from these I can make string.
        one more thing, I can cancel subsequences where s[i]!=t[i]
        so, what should be dp states: idx, subseq. 
        At each index we will have different subsequence and different cnt. 
        But, now subseq, I should store it as string or what? 
        wait, I can store idx and valid_idx, means till thsi idx, how much valid t string we are having. like we have made till 3 index, now we need next remaning string.
        We won't be taking those strings who are not matching t.
        I have to cal total sub till ith index which equal t.

        dp[idx][val_t] = cnt

        when pick -> when (s[idx]==t[val_idx]) -> 
    */

    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        if(n<m) return 0;
        vector<vector<int>> dp(n, vector<int> (m, -1));

        auto helper = [&](auto &&self, int idx, int val_idx) {
            if(val_idx>=m) return 1;
            if(idx>=n) return 0;
            if(dp[idx][val_idx]!=-1) return dp[idx][val_idx];

            int pick=0, non_pick=0;
            if(s[idx]==t[val_idx]) pick = self(self, idx+1, val_idx+1);            
            non_pick = self(self, idx+1, val_idx);

            return dp[idx][val_idx] = pick+non_pick;
        };

        return helper(helper, 0, 0);
    }
};