// Question Link - https://codeforces.com/contest/2071/problem/0

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll k; cin>>k;

    if(k%3 == 1 || k==1)    cout<<"YES"<<endl;
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