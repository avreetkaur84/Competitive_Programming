// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, a, b;    cin>>n>>a>>b;
    if(n==a && a==b) {
        cout<<"Yes"<<endl;   return;
    }

    if((n-(a+b))>=2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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