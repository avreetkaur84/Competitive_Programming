// Question Link - https://leetcode.com/problems/word-break/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        bool res=false;
        int n=s.size();
        vector<int> vis(n+1, 0);

        auto rec = [&](auto &&self, int idx) {
            if(res) return;
            if(idx>=n) {
                res=true; return;
            }

            string word="";
            for(int i=idx; i<n; i++) {
                word+=s[i];
                if(st.count(word) && vis[i+1]==0) {
                    vis[i+1]=1;
                    self(self, i+1); 
                }
            }
        };

        rec(rec, 0);
        return res;
    }
};