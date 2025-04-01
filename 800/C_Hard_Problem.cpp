// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll m, a, b, c; cin>>m>>a>>b>>c;
    ll seats = 0, rem=0;
    
    // a seats
    if(a<m) {
        seats += a;
        rem += m-a;
    } else {
        seats += m;
    }

    if(b<m) {
        seats += b;
        rem += m-b;
    } else {
        seats += m;
    }

    if(c<rem) {
        seats += c;
    } else {
        seats += rem;
    }

    cout<<seats<<endl;
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