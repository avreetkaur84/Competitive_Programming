// Question Link - https://codeforces.com/contest/2086/problem/B

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(n);

    ll sum = 0;
    ll d = x;
    ll ans = n*k;   //total indes in the array
    // we are gonna subtract the invalid index from ans, that wont help us make the subrray with x sum

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    if(k*sum<x) {
        cout<<0<<endl; return;
    }

    // counting the invalid index in the copies of array
    while(d>sum && k>0) {
        d -=  sum;
        ans -= n;
        k--;
    }

    // counting the invalid indexes in the array
    for(int i=n-1; i>=0; i--) {
        if(d-arr[i]>0) {
            d -= arr[i];
            ans--;
        } else break;
    }

    // to avoid negatives in edge cases
    cout<<max(ans, 0ll)<<endl;;

}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}