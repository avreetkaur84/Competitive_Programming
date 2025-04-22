// Question Link - https://codeforces.com/contest/2094/problem/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, m, l, r;
    cin>>n>>m>>l>>r;
    
    if(l+m<0) {
        cout<<-m<<" "<<0<<endl;
    } else cout<<l<<" "<<l+m<<endl;
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