// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll a, b, n; cin>>a>>b>>n;
    vector<ll> arr(n);  ll c=0;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        if(arr[i]>a)    c++;
    }
    
    ll moves=b;
    for(int i=0; i<n; i++) {
        moves += min(arr[i], a-1);
        // cout<<i<<" : "<<arr[i]<<", moves: "<<moves<<endl;
    }
    
    cout<<moves<<endl;
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