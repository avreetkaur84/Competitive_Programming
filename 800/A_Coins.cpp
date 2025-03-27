// Question Link - https://codeforces.com/problemset/problem/1829/B

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n,k; cin>>n>>k;
    // k!=2
    if(n%2==0 || (n-k)%2==0)    cout<<"YES"<<endl;
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