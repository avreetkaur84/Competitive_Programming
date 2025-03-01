// Question Link - https://leetcode.com/problems/generate-parentheses/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
    public:
        void generate(vector<string> &res, int open, int close, string s, int n) {
            if(open==n && close==n) {
                res.push_back(s);
                return;
            }
    
            if(open<n) {
                string op = s+'('; 
                // cout<<"Open: "<<open<<endl;
                generate(res, open+1, close, op, n);
            }
    
            if(close<open) {
                string op = s+')'; 
                // cout<<"Close: "<<close<<endl;
                generate(res, open, close+1, op, n);
            }
        }
    
        vector<string> generateParenthesis(int n) {
            vector<string> res;
            string s="";
    
            if(n==0)    return res;
    
            generate(res, 0, 0, s, n);
            return res;
        }
    };