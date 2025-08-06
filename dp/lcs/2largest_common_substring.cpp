// Question Link - https://www.naukri.com/code360/problems/longest-common-substring_1214702

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void memo(string &s1, string &s2, int m, int n, int cnt, int &maxx) {
    maxx = max(maxx, cnt);
    
    // base case
    if(m==0 || n==0) {
        return;
    }

    if(s1[m-1]==s2[n-1]) {
        memo(s1, s2, m-1, n-1, cnt+1, maxx);
    } else {
        memo(s1, s2, m-1, n, 0, maxx);
        memo(s1, s2, m, n-1, 0, maxx);
    }
}

int LCSubStr(string str1, string str2)
{
    int maxx=0;
    memo(str1, str2, str1.length(), str2.length(), 0, maxx);
    return maxx;

}

int tabulation(string str1, string str2)
{
    int m=str1.length(), n=str2.length(), maxx=0;
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(str1[i-1]==str2[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
                maxx = max(maxx, dp[i][j]);
            } else {
                dp[i][j] = 0;
                // dp[i][j-1] = 0;
            }
        }
    }
    
    return maxx;
}

int main() {
    cout<<tabulation("hello", "helo")<<endl;
    cout<<tabulation("olleh", "oleh")<<endl;
    cout<<LCSubStr("olleh", "oleh")<<endl;
    cout<<LCSubStr("hello", "helo")<<endl;
}