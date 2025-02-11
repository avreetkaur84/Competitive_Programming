// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b; cin>>a>>b;
    pair<int, int> king;    pair<int, int> queen;
    cin>>king.first>>king.second;
    cin>>queen.first>>queen.second;

    if(abs(king.first-queen.first)==2*a || abs(king.second-queen.second)==2*b)    cout<<2<<endl;
    else cout<<0<<endl;
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