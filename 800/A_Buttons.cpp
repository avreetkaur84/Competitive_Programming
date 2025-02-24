// Question Link - https://codeforces.com/problemset/problem/1858/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll a, b, c;
    cin>>a>>b>>c;

    // if((a+b+c)%2==0)    cout<<"Second"<<endl;
    // else cout<<"First"<<endl;
    if(a>b) cout<<"First"<<endl;
    else if(b>a)    cout<<"Second"<<endl;
    else if(a==b) {
        if(c%2==0) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
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