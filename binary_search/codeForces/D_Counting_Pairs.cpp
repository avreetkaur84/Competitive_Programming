// Question Link - https://codeforces.com/problemset/problem/2051/D

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

/*
    a -> x & y
    i,j -> i<j -> remove i & j -> sum in range x & y.
*/

void inArr(vector<ll> &arr, ll n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<ll> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void solve() {
    ll n, x, y;  cin>>n>>x>>y;
    vector<ll> arr(n); inArr(arr, n);
    ll sum = accumulate(arr.begin(), arr.end(), 0ll);
    // cout<<sum<<"\n";
    ll pairs=0;

    sort(arr.begin(), arr.end());
    // outArr(arr); cout<<"\n";
    for(int i=0; i<n; i++) {
        ll first=sum-arr[i]-y;     // 
        ll last=sum-arr[i]-x;   
        // if(last<arr[i]) continue;

        // i+1 to avoid duplicates
        auto p = lower_bound(arr.begin()+i+1, arr.end(), first); 
        auto m = upper_bound(arr.begin()+i+1, arr.end(), last);                  
        pairs+=m-p;
        // cout<<arr[i]<<" "<<first<<" "<<last<<" "<<m-p<<" "<<pairs<<"\n";

    }

    cout<<pairs<<"\n";
    // cout<<"\n";
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