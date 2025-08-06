// Question Link - https://codeforces.com/problemset/problem/1506/C

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int tab_dp(string &a, string &b) {
    int m=a.size(), n=b.size();
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    int maxx=0;

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(a[i-1]==b[j-1]) {
                dp[i][j]=1+dp[i-1][j-1];
                maxx=max(maxx, dp[i][j]);
            } else {
                dp[i][j]=0;
            }
        }
    }

    return maxx;
}

void solve() {
    string a; string b;
    cin>>a>>b;

    int maxx=tab_dp(a, b);
    // cout<<maxx<<" ";
    cout<<a.size()+b.size()-(2*maxx)<<endl;
}

int main()
{
    int t;
    cin >> t;

    
    while(t--)
    {
        solve();
    }
}