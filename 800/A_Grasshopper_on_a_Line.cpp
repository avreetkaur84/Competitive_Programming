// Question Link - https://codeforces.com/problemset/problem/1837/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int x, k; cin>>x>>k;

    if(x%k==0)  {
        cout<<2<<endl;
        cout<<x-1<<" "<<1;
    } else {
        cout<<1<<endl;
        cout<<x;
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