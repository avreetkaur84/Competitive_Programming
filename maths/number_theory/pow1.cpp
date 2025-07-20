// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// a -> no; b->power
ll solve(ll a, ll b) {
    if(b==0)    return 1;

    ll p = solve(a, b/2);
    if(b%2==0) {
        return p*p;
    } else {
        return p*p*a;
    }
}



int main()
{
    ll a=5, b=7;   
    // cin>>a>>b;
    ll res = solve(a, b);
    cout<<res<<endl;
}