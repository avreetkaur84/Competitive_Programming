// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n;   cin>>n;
    ll minn=0, maxx=0;

    if(n%2!=0 || n<4)  {
        cout<<-1<<endl; return;
    }

    // ceil -> (n+x-1)/x

    minn = (n+5)/6;
    maxx = n/4;

    // edge cases
    // if not fully divisible by 4 or 6

    if(n<6) {
        cout<<maxx<<" "<<maxx<<endl;   return;
    }

    
    cout<<minn<<" "<<maxx<<endl;
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