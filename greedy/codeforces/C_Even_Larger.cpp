// Question Link - https://codeforces.com/contest/2134/problem/C

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void inArr(vector<ll> &arr, ll n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<ll> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void solve() {
    ll n;  cin>>n;
    vector<ll> arr(n); inArr(arr, n);
    ll res=0;

    for(int i=1; i<n; i+=2) {
        if(i==n-1) {
            if(arr[i]<arr[i-1]) res+=arr[i-1]-arr[i];
            continue;
        }

        ll x = arr[i-1]+arr[i+1]-arr[i];
        if(x<=0)  continue;
        res+=x;
        arr[i+1] =  (arr[i+1]-x < 0) ? 0 : arr[i+1]-x;
    }

    // outArr(arr);

    cout<<res<<"\n";
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