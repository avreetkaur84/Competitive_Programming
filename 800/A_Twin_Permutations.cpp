// Question Link - https://codeforces.com/problemset/problem/1831/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> arr(n); int maxx=INT_MIN;
    for(int i=0; i<n; i++) {
        cin>>arr[i]; maxx=max(maxx, arr[i]);
    }

    for(int i=0; i<n; i++) {
        cout<<maxx+1-arr[i]<<" ";
    }
    cout<<endl;
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