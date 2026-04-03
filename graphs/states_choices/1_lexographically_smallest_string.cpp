// Question Link - https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> vis;
        queue<string> q;
        q.push(s); vis.insert(s);
        string mn=s;

        auto add = [&](string y) -> string {
            for(int i=1; i<y.size(); i+=2) {
                y[i]=((y[i]-'0'+a)%10)+'0';
            }
            return y;
        };

        auto rotate = [&](string y) -> string {
            int n=y.size();
            reverse(y.begin(), y.begin()+n-b);
            reverse(y.begin()+n-b, y.end());
            reverse(y.begin(), y.end());
            return y;
        };

        while(!q.empty()) {
            string x = q.front();  q.pop();
            mn=min(x, mn);
            string y = add(x);
            if(!vis.count(y)) {
                q.push(y); vis.insert(y);
            }

            y = rotate(x);
            if(!vis.count(y)) {
                q.push(y); vis.insert(y);
            }  
        }

        return mn;
    }
};