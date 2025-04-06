// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n;  cin>>n;
    vector<ll> arr(n);

    unordered_map<ll, ll> fq;
    ll maxx=0;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
        fq[arr[i]]++;

        maxx = max(maxx, fq[arr[i]]);
    }

    if(n==1) {
        cout<<0<<endl;  return;
    }

    ll same = maxx;
    ll pending = n-maxx;
    ll cnt=0;

    while(pending>0) {
        cnt++;
        pending -= same;
        same = same*2;
    }

    cout<<cnt+(n-maxx)<<endl;
    
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