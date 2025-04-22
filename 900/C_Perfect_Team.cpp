// Question Link - https://codeforces.com/problemset/problem/1221/C

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll c, m, x; cin>>c>>m>>x;

    cout<<min(min(c, m), (c+m+x)/3)<<endl;;
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