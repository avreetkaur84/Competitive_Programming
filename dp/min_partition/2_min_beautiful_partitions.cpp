// Question Link - https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    /*
        one idx -> partition flags
        each substr beautiful
    */

    int minimumBeautifulSubstrings(string s) {
        int n = s.size(), num=1, x=1, res=0;
        set<int> st;
        vector<int> dp(n, INT_MAX-1);

        auto btod = [&](int i, int j) -> int {
            while(i<=j && s[i]=='0') i++;
            int num=1; i++;
            while(i<=j) {
                bool odd=(s[i]=='1');
                num*=2;
                num+=odd;
                i++;
            }
            return num;
        };

        num=btod(0, n-1);
        while(x<=num) {
            st.insert(x);
            x*=5;
        }

        // how to partition the string : rec ?? kaise
        auto rec = [&](auto &&self, int idx) -> int {
            if(idx==n) return 0;
            if(dp[idx]!=INT_MAX-1) return dp[idx];

            int x = dp[idx];
            for(int i=idx; i<n; i++) {
                if(s[idx]=='0') continue;
                int temp = btod(idx, i);
                // cout<<s.substr(idx, i-idx+1)<<": "<<temp<<"\n";
                if(st.count(temp)) {
                    x = min(1+self(self, i+1), x);
                }
            }

            return dp[idx] = x;
        };

        res = rec(rec, 0);
        return (res==INT_MAX-1)?-1:res;
    }
};