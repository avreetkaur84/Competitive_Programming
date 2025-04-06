// Question Link - https://codeforces.com/problemset/problem/1696/B

// just focus on core operation that needs to be done!!!
// think in all possible directions

// padding vector with 0 at the start - pretty helpful trick

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;  cin>>n;
    vector<ll> arr(n+1, 0);
    int cnt=0;

    for(int i=1; i<=n; i++) {
        cin>>arr[i];
        if(arr[i-1]==0 && arr[i]!=0)   cnt++;
    }

    // if(cnt==0 && arr[0]!=0) cnt++;

    // if(cnt==n)    cout<<0<<endl;
    // else if(cnt==0) cout<<1<<endl;
    // else cout<<2<<endl;
    cout<<min(cnt, 2)<<endl;

    // cout<<cnt<<endl;
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