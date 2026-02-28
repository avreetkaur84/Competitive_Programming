// Question Link - https://leetcode.com/problems/palindrome-partitioning-ii/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    /*
        TLE: Simple backtracking
        convert to dp
        we will have (i,j) -> to check if (i,j) is palindrome -> still TLE
        i to j ko palindrome banane ke liye min kitne cur req will be stored
    */

    int minCut(string s) {
        int minn=INT_MAX, n=s.size();        
        vector<string> cur;
        vector<int> dp(n, -1);
        vector<vector<int>> pal(n, vector<int> (n, -1));

        auto isPalindrome = [&](int i, int j) -> bool {
            while(i<j) {
                if(s[i]!=s[j]) return false;
                i++; j--;
            }
            return true;
        };

        auto rec = [&](auto &&self, int st) -> int {
            if(st==n) return 0;            
            if(dp[st]!=-1) return dp[st];            

            int x=INT_MAX;
            for(int i=st; i<n; i++) {
                if(pal[st][i]==-1) pal[st][i]=isPalindrome(st, i);
                if(pal[st][i]) {
                    x = min(1+self(self, i+1), x);
                }
            }

            return dp[st]=x;
        };

        minn = rec(rec, 0);

        return minn-1;
    }
};