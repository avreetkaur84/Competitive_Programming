// Question Link - https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1000000007;

/*
    target -> n
    range -> 1 to 6 -> any combination

*/

void inArr(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void solve() {
    int n;  cin>>n;
    vector<int> dp(n+1, 0);
    dp[0]=1;

    for(int i=1; i<=n ; i++) {
        for(int j=1; j<=6; j++) {
            if(i-j<0) continue;
            dp[i] = (dp[i]+dp[i-j])%MOD;
        }
    }

    cout<<dp[n]<<"\n";
    // outArr(dp);
}


int main()
{
    // int t;
    // cin >> t;

    
    // while(t--)
    // {
    //     solve();
    // }
    solve();
}