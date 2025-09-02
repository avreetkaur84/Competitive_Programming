// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void outArr(vector<ll> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<"\n";
}

int main() {
    ll n, q; cin>>n>>q;
    vector<int> arr(n); vector<ll> pf(n+1, 0);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        pf[i+1] = pf[i]+arr[i];
    }

    vector<ll> ans;

    for(int i=0; i<q; i++) {
        int l, r; cin>>l>>r;
        ans.push_back(pf[r]-pf[l]);
    }

    outArr(ans);

    return 0;
}