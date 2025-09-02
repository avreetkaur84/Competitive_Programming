// Question Link - https://leetcode.com/problems/longest-palindromic-substring/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


// I am fucking getting MLE for this. I am done with this DSA!!! 
class Solution {
public:
    int checkPalin(int i, int j, string s, vector<vector<int>> &dp) {
        if(i>j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]) return checkPalin(i+1, j-1, s, dp);
        else return 0;
        // return 1;
    }

    string longestPalindrome(string s) {
        int i=0, j=0, n=s.length();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        int maxLen=0, sp=-1;

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                int x = checkPalin(i, j, s, dp);
                // cout<<i<<" "<<j<<" "<<s.substr(i, j-i+1)<<" "<<x<<" "<<maxLen<<endl;
                if(x==1 && (j-i+1)>maxLen) {
                    maxLen=j-i+1; sp=i;
                }
            }
        }

        return s.substr(sp, maxLen);
    }
};


// TLE -> O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int i=0, j=0, n=s.length();
        string res="";

        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=i; j--) {
                string x = s.substr(i, j-i+1);
                string y = x; reverse(y.begin(), y.end());
                // cout<<i<<" "<<j<<" "<<x<<endl;
                if(x==y && x.length()>res.length()) res=x;
            }
            // cout<<endl<<endl;
        }

        return res;
    }
};


// WA -> BUT NEED TO CORRECT THIS
class Solution {
public:
    string helper(int n, int m, string &s, string &r, string &maxx, vector<vector<string>> &dp) {
        if(n==s.length() || m==r.length()) return "";
        if(dp[n][m]!="") return dp[n][m]; 

        if(s[n]==r[m]) {
            string cur = s[n]+helper(n+1, m+1, s, r, maxx, dp);
            cout<<s[n]<<" "<<cur<<" "<<maxx<<endl;
            if(cur.length()>maxx.length()) maxx=cur;
            return dp[n+1][m+1] = cur;
        } else {
            helper(n+1, m, s, r, maxx, dp);
            helper(n, m+1, s, r, maxx, dp);
            return dp[n+1][m+1]="";
        }
    }

    string longestPalindrome(string s) {
        int i=0, j=0, n=s.length(), m=s.length();
        string res=""; string r=s; reverse(r.begin(), r.end());
        cout<<s<<" "<<r<<endl;
        vector<vector<string>> dp(n+1, vector<string> (n+1, ""));
        helper(0, 0, s, r, res, dp);

        return res;
    }
}; 