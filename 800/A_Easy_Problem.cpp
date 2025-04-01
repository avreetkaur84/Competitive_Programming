// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n; cin>>n; int cnt=0;
    for(int i=1; i<n; i++) {
        if(n-i <= n) cnt++;
    }

    cout<<cnt<<endl;
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