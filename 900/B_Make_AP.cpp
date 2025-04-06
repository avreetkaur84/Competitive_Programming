// Question Link - https://codeforces.com/problemset/problem/1624/B

// AP -> (2b = a+c)   :->  derived from -> (b-a = c-b)


#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll a, b, c; cin>>a>>b>>c;

    // AP equation
    ll ls = 2*b;
    ll rs = a+c;

    // cases, multiply m with any number
    // 1. multiply with b -> 2*b*m = a+c
    if(rs%ls == 0) {
        // cout<<"case 1:  ";
        cout<<"YES"<<endl;  return;
    } 
    
    // 2. multiply with a -> 2*b = a*m + c
    // 3. multiply with c -> 2*b = a + c*m
    // non-negative
    else if(
        ((ls-c)%a == 0 || (ls-a)%c == 0) && 
        (ls-a>0 && ls-c>0) 
    ) {
        // cout<<"case 2:  ";
        cout<<"YES"<<endl;  return;
    }

    else {
        // cout<<"case 3:  ";
        cout<<"NO"<<endl;   return;
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