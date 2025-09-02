// Question Link - https://codeforces.com/problemset/problem/961/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    1. Misunderstood the question :(
    2. All ones will be counted in sum -> so simply make the prefix sum of zeros only. Then add the ones and k size zero prefix sum range to get the maximum out of all.
*/

void inArr(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void solve() {
    int n, k;  cin>>n>>k;
    vector<int> a(n); inArr(a, n);
    vector<int> b(n); inArr(b, n);
    vector<int> pf(n+1, 0); 
    ll one_sum=0, maxx=0;

    for(int i=0; i<n; i++) {
        pf[i+1] = (b[i]==0) ? pf[i]+a[i] : pf[i];
        if(b[i]==1) one_sum+=a[i];
    }

    // outArr(pf);
    for(int i=k; i<=n; i++) {
        ll sum = one_sum+(pf[i]-pf[i-k]);
        maxx = max(maxx, sum);
    }
    
    cout<<maxx<<"\n";
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