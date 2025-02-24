// Question Link - https://codeforces.com/problemset/problem/1857/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n; cin>>n;
    int cnt=0;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        if((arr[i]%2)!=0)   cnt++;
    }

    if(cnt%2==0)    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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