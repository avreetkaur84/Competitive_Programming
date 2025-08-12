// Question Link - https://codeforces.com/problemset/problem/1418/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// I hate Maths :( ------

void solve() {
    ll x, y, k; cin>>x>>y>>k;
    ll req_sticks = (y*k)+k-1;
    ll moves=(req_sticks+x-2)/(x-1);   // ceil
    // x-1 -> net change = gain-loss 
    moves+=k;
    cout<<moves<<endl;
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