// Question Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> num(10, "");
        num[2]="abc";
        num[3]="def";
        num[4]="ghi";
        num[5]="jkl";
        num[6]="mno";
        num[7]="pqrs";
        num[8]="tuv";
        num[9]="wxyz";
        vector<string> res;
        int n=digits.size();

        auto rec = [&](auto &&self, int idx, string cur) {
            if(idx>=n) {
                // cout<<cur<<"\n";
                res.push_back(cur); return;
            }

            int j=digits[idx]-'0';
            for(int i=0; i<num[j].size(); i++) {
                cur+=num[j][i];
                self(self, idx+1, cur);
                cur.pop_back();
            }
        };

        rec(rec, 0, "");
        return res;
    }
};