// Question Link - https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Lesson learnt - Try to store the thing that you need in dp array. Here I wanted the ascii sum of characters, so I is optimal to store that in dp array. Creating global variable to track this sum is huge mistake which I made on my part earlier.
*/

class Solution {
public:
    int lcs(int n, int m, string &w1, string &w2, vector<vector<int>> &dp) {
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];

        if(w1[n-1]==w2[m-1]) {
            return dp[n][m] = w1[n-1]+lcs(n-1, m-1, w1, w2, dp);
        } else {
            return dp[n][m] = max(lcs(n-1, m, w1, w2, dp), lcs(n, m-1, w1, w2, dp));
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(), m=s2.size(), c1=0, c2=0, res=0;
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        for(auto it : s1) c1+=it;
        for(auto it : s2) c2+=it;
        res = lcs(n, m, s1, s2, dp);
        // cout<<res<<" "<<c1<<" "<<c2<<" "<<c1+c2<<endl;
        return (c1+c2)-(2*res);
    }
};