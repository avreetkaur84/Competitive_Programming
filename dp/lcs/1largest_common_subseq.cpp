// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// simple recursion
class Solution {
    public:
        int lcsCnt(string x, string y, int m, int n) {
            // base case
			if(m==0 || n==0) return 0;
    
			// choice diagram
            if(x[m-1]==y[n-1]) {
                return 1+lcsCnt(x, y, m-1, n-1);
            } else {
                return max(
                    lcsCnt(x, y, m-1, n ),
                    lcsCnt(x, y, m, n-1 )
                );
            }
        }
    
        int longestCommonSubsequence(string text1, string text2) {
            int m = text1.length(), n = text2.length();
            return lcsCnt(text1, text2, m, n );
        }
};

// TABULATION

int tabulation(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    // return lcsCnt(text1, text2, m, n, dp);

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(text1[i-1]==text2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}


// string storage 
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
	vector<vector<string>> dp(n+1, vector<string> (m+1, ""))	;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(s1[i-1]==s2[j-1]) {
				dp[i][j] = dp[i-1][j-1]+s1[i-1];
			} else {
				// how am I supposed to write this, 
				if(dp[i-1][j].length()>=dp[i][j-1].length()) {
					dp[i][j] = dp[i-1][j];
				} else {
					dp[i][j] = dp[i][j-1];
				}
			}
		}
	}

	// cout<<dp[n][m];
	return dp[n][m];
}


// PRINTING LONGEST COMMON SUBSEQUENCE
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
	vector<vector<string>> dp(n+1, vector<string> (m+1, ""))	;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(s1[i-1]==s2[j-1]) {
				dp[i][j] = dp[i-1][j-1]+s1[i-1];
			} else {
				// how am I supposed to write this, 
				if(dp[i-1][j].length()>=dp[i][j-1].length()) {
					dp[i][j] = dp[i-1][j];
				} else {
					dp[i][j] = dp[i][j-1];
				}
			}
		}
	}

	// cout<<dp[n][m];
	return dp[n][m];
}