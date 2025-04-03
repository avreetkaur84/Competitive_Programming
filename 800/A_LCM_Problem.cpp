// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// gcd -> n/2
// lcm -> x*2

void solve() {
    ll l, r;   cin>>l>>r;

    if(2*l>r) {
        cout<<-1<<" "<<-1<<endl;
        return;
    }

    cout<<l<<" "<<2*l<<endl;


    // for(ll i=r; i>l; i--) {
    //     if(i%l==0)  {
    //         cout<<l<<" "<<i<<endl;
    //         return;
    //     }
    // }

    
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