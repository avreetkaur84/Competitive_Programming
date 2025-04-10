// Question Link - https://codeforces.com/problemset/problem/1607/B

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Cool one
/*
    Here, pattern is repeated after every four steps and the value becomes initial value after 4 steps, 
    1. If even -> left - right - right - left
    2. If odd ->  right - left - left - right
*/


void solve() {
    // x -> initial point
    // n -> idx / jump no.
    ll x, n;    cin>>x>>n;

    if(n==0) {
        cout<<x<<endl;  return;
    }

    if(n%4==0)  {
        cout<<x<<endl;
        // else cout<<x<<endl;
    }
    else if(n%4==1) {
        if(x%2==0)  cout<<x-n<<endl;
        else cout<<x+n<<endl;
    }
    else if(n%4==2) {
        if(x%2==0)  cout<<x+1<<endl;
        else cout<<x-1<<endl;
    }
    else if(n%4==3) {
        if(x%2==0)  cout<<x+1+n<<endl;
        else cout<<x-1-n<<endl;
    }



    // for(int i=1; i<=n; i++) {
    //     if(x%2==0)  x-=i;
    //     else x+=i;
    // }

    // cout<<x<<endl;
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