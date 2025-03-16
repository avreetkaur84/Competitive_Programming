// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll x, y, k;
    cin>>x>>y>>k;
    // ll s=0, m=0, move=0;

    ll x_moves = ceil((double)x/k);
    ll y_moves = ceil((double)y/k);

    ll moves = 2*max(x_moves, y_moves);

    if(x_moves>y_moves) moves--;
    cout<<moves<<endl;

    // if(x==y) {
    //     move = (ceil((double)x/k))*2;
    //     // if(x%k!=0)  move+=2;
    //     cout<<move<<endl; return;
    // }

    // s = min(x, y);
    // move = (ceil((double)s/k))*2;
    // // both x & y equalmoves
    // // x=s, 
    // // if(s==x && s%k!=0)  move++;
    // // if(s==y && s%k!=0)  {
    // //     x-=k; move+=2;
    // // }

    // // if(s%k!=0)  move++;

    // // cout<<"s: "<<s<<"  move: "<<move<<"  ,";
    
    // m = max(x, y)-s;
    // move = move+(ceil((double)m/k))*2;
    // s & m moves ended

    // if(m%k!=0 && m==x-s)  move++;
    // if(m%k!=0 && m==y-s)  move+=2;

    // if(m%k!=0)  move++;
    
    // cout<<"m: "<<m<<"  move: "<<move<<"  "<<endl;

    // if(x<y) move+=2;
    // else move++;
    // if(x>y) move--;

    // cout<<move<<endl;
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