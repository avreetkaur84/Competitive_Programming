// Question Link - https://leetcode.com/problems/longest-palindromic-substring/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string mx="";
        vector<vector<int>> dp(n, vector<int> (n, -1));

        auto check = [&](auto &&self, int i, int j) -> bool {
            if(i>=j) return true;
            if(dp[i][j]!=-1) return dp[i][j];

            if(s[i]==s[j]) return self(self, i+1, j-1);
            else return false;
        };

        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=i; j--) {
                if(j-i+1<=mx.size()) break;
                dp[i][j] = check(check, i, j);
                if(dp[i][j] && mx.size()<j-i+1) mx=s.substr(i, j-i+1);
                if(dp[i][j]) break;
            }
        }

        return mx;
    }
};