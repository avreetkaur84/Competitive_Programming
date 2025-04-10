// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// simple recursion
class Solution {
    public:
        int lcsCnt(string x, string y, int m, int n) {
            if(m==0 || n==0) return 0;
    
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