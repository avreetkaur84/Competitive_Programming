// Question Link - https://leetcode.com/problems/longest-palindromic-subsequence/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// minimum no of insertions to make string plaindromic and minimum number of deletions to make string palindromic are same,
// cal the max length of palindromic sunsequence and subtract it from total string length

class Solution {
    public:
        // TABULATION
        int longestPalindromeSubseq(string s) {
            string op=s;
            reverse(op.begin(), op.end());
            int m = s.length(), n = op.length();
            vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    
            for(int i=1; i<=m; i++) {
                for(int j=1; j<=n; j++) {
                    if(s[i-1]==op[j-1]) {
                        dp[i][j] = 1+dp[i-1][j-1];
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            
            return dp[m][n];
        }
    
        // SOLUTION 2 with LCS - memoization
        int seq(string s, string r, int m, int n, vector<vector<int>> &dp) {
            if(m==0 || n==0) {
                return 0;
            }
    
            if(dp[m][n]!=-1)    return dp[m][n];
    
            if(s[m-1]==r[n-1]) {
                return dp[m][n] = 1+seq(s, r, m-1, n-1, dp);
            } else {
                return dp[m][n] = max(
                    seq(s, r, m-1, n, dp),
                    seq(s, r, m, n-1, dp)
                );
            }
        }
    
        // int longestPalindromeSubseq(string s) {
        //     string op=s;
        //     reverse(op.begin(), op.end());
        //     int m = s.length(), n = op.length();
        //     vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
            
        //     return seq(s, op, m, n, dp);
        // }
    
    
    
        // SOLUTION 1
        // void seq(string ip, string op, int &maxx) {
        //     if(ip.empty()) {
        //         string rev = op;
        //         reverse(rev.begin(), rev.end());
        //         int size = op.length();
        //         if(rev==op) maxx=max(maxx, size);
        //         return;
        //     }
    
        //     string op2 = op+ip[0];
        //     ip = ip.substr(1, ip.length()-1);
    
        //     seq(ip, op, maxx);
        //     seq(ip, op2, maxx);
        // }
    
        // int longestPalindromeSubseq(string s) {
        //     string op="";
        //     int maxx=0;
        //     seq(s, op, maxx);
        //     return maxx;
        // }
    };