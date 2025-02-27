// Question Link - https://codeforces.com/contest/2072/problem/0

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, k, p;
    cin>>n>>k>>p;
    
    if(abs(k)>(n*p)) {
        cout<<-1<<endl;
        return;
    }

    int res = ceil(abs((double)k/p));
    cout<<res<<endl;

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