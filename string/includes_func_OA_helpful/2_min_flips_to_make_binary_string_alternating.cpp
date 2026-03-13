// Question Link - https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


// Took me 25 minutes: I thought for 5 minutes, then code for 7 minutes, 13 minutes patching, yet WA.
// After 25 minutes I have realised greedy type dp will not work, so now I will change my approach.
// This approach passed 35/65 test cases, means I was not totally clueless.
class Solution {
public:
    int cal(string t) {
        // two choices: 1010, 0101
        int cnt1=0, cnt2=0, n=t.size();
        for(int i=0; i<n; i++) {
            if((i&1) && t[i]=='1') cnt1++;
            else if(!(i&1) && t[i]=='0') cnt1++;
        }

        for(int i=0; i<n; i++) {
            if((i&1) && t[i]=='0') cnt2++;
            else if(!(i&1) && t[i]=='1') cnt2++;
        }

        // cout<<cnt1<<" "<<cnt2;
        return min(cnt1, cnt2);
    }

    int minFlips(string s) {
        // perform type 1 op
        int n=s.size(), res=n;
        if(n<=1) return 0;
        res=cal(s);
        // cout<<res<<"\n";
        string t = s; 
        int x=0, prev=n-1;
        while(s[x]!=s[prev]) {
            prev=x; x++;
            t = s.substr(x, n-x)+s.substr(0, x);
            res = min(res, cal(t));
            cout<<res<<" ";
        }

        return res;
    }
};