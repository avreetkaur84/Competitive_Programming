// Question Link - https://leetcode.com/problems/palindrome-partitioning/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> res;
        vector<string> cur;

        auto isPalindrome = [&](int i, int j) -> bool {
            while(i<j) {
                if(s[i]!=s[j]) return false;
                i++; j--;
            }
            return true;
        };

        auto rec = [&](auto &&self, int idx) -> void {
            if(idx==n) {
                res.push_back(cur); return;
            }

            for(int i=idx; i<n; i++) {
                if(isPalindrome(idx, i)) {
                    cur.push_back(s.substr(idx, i-idx+1));
                    self(self, i+1);
                    cur.pop_back();
                }
            }
        };

        rec(rec, 0);
        return res;
    }
};