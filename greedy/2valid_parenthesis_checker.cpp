// Question Link - https://leetcode.com/problems/valid-parenthesis-string/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low=0, high=0, n=s.length(); 
        // bool flag=false;
        cout<<"n: "<<n<<endl; 

        for(int i=0; i<n; i++) {
            if(s[i]=='*') {
                low=max(0, low-1);
                high++;
            }
            else if(s[i]=='(') {
                low++; high++;
            }
            else {
                low=max(0, low-1);
                high--;
            }

            if(high<0) return false;
            // cout<<"i: "<<i<<"   low: "<<low<<"   high: "<<high<<endl;
        }

        if(low==0 && high>=0) return true;
        return false;
    }
};