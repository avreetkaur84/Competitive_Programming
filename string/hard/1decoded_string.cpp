// Question Link - https://leetcode.com/problems/decoded-string-at-index/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n=s.size(); long long len=0;

        for(int i=0; i<n; i++) {
            if(isalpha(s[i])) len++;
            else len=len*(s[i]-'0');
        }
        // cout<<len<<endl;
        
        for(int i=n-1; i>=0; i--) {
            // cout<<s[i]<<"   "<<len<<"    "<<k%len<<endl;
            // as length of the string shriks, we haev to shrink k also.
            k %= len;
            if(k==0 && isalpha(s[i])) {
                string a(1, s[i]);
                return a;
            }
            if(isalpha(s[i])) len--;
            else len=len/(s[i]-'0');
        }

        return "";
    }
};