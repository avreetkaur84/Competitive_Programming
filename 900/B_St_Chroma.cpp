// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, x;  cin>>n>>x;

    for(int i=0; i<n-1; i++) {
        if(i<x) {
            cout<<i<<" ";
        } else if(i+1>x && i+1<=n) {
            cout<<i+1<<" ";
        }
    }

    if(x>=n) {
        cout<<n-1<<endl;
    } else cout<<x<<endl;

    // cout<<cnt<<endl;
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