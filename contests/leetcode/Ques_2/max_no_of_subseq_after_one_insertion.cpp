// Question Link - https://leetcode.com/problems/maximum-number-of-subsequences-after-one-inserting/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 


// My first try with DP - incomplete solution
class Solution {
public:
    // dp for calculating subsequences
    long long memo(int i, int j, string s, string req, vector<vector<int>> &dp) {
        if(j==req.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int non_pick = memo(i+1, j, s, req, dp);
        int pick=0;
        if(s[i]==req[j]) {
            pick = memo(i+1, j+1, s, req, dp);
        }

        return dp[i][j] = pick+non_pick;
    }
    
    long long numOfSubsequences(string s) {
        s='L'+s; int n=s.size();
        unordered_map <char, int> mp;
        vector<int> prefix(n, 0); vector<int> sufix(n, 0);
        
        for(int i=0; i<n; i++) {
            if(s[i]=='L') mp[s[i]]++;
            if(s[i]=='C') mp[s[i]]++;
            if(s[i]=='T') mp[s[i]]++;
        }

        // we have to insert C where before C, L appreas max times and after it T apperas max time, to increase no of subsequence
        
        int l = mp['L'], c=mp['C'], t=mp['T'];
        if(min(l, min(c, t))==l) s='L'+s;
        else if(min(l, min(c, t))==t) s=s+'T';
        else 
        
        vector<vector<int>> dp(n, vector<int>(3, -1));
        // return memo(0, 0, s, "LCT");
    }
};