// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y; cin>>x>>y;

    if(x+1==y && y%10!=0) cout<<"Yes"<<endl;
    else if((x%9==0) && (y==1)) cout<<"Yes"<<endl;
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