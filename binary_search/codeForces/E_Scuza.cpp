// Question Link - https://codeforces.com/problemset/problem/1742/E

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    1. Handle edge cases properly!!
*/

void inArr(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void solve() {
    ll n, q;  cin>>n>>q;
    vector<int> arr(n); inArr(arr, n);
    vector<int> qrr(q); inArr(qrr, q);
    vector<long long> pf(n); pf[0]=arr[0];
    for(int i=1; i<n; i++) pf[i]=pf[i-1]+arr[i];  // max height
    vector<int> lg(n); lg[0]=arr[0];
    for(int i=1; i<n; i++) lg[i]=max(lg[i-1], arr[i]);  // leg height
    // outArr(lg);

    for(int i=0; i<q; i++) {
        if(qrr[i]<lg[0]) {
            cout<<0<<" ";
        } else {
            auto it = upper_bound(lg.begin(), lg.end(), qrr[i]);   // k>=a 
            int idx = it-lg.begin();   // idx of last idx
            idx = (idx==0) ? 0 : idx-1;
            cout<<pf[idx]<<" ";
        }
    }
    cout<<"\n";
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