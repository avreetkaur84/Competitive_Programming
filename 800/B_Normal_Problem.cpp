// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string a; cin>>a;
    string b = a;
    reverse(b.begin(), b.end());

    for(int i=0; i<b.length(); i++) {
        if(b[i]=='p')   b[i]='q';
        else if(b[i]=='q')   b[i]='p';
    }

    cout<<b<<endl;
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