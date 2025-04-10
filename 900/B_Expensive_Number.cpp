// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// zero not present - min from all
// if zero present - min sum - min steps -> cal

int zero_count(string s, int n) {
    int zero_cnt=0;
    for(int i=0; i<n; i++) {
        if(s[i]=='0') zero_cnt++;
    }

    return zero_cnt;
}


void solve() {
    // ll n;   cin>>n;
    // string s = to_string(n);

    string s; cin>>s;

    int size = s.length();
    ll zero_cnt=0;

    if(size==1) {
        cout<<0<<endl;  return;
    }

    zero_cnt = zero_count(s, size);

    // cout<<zero_cnt<<"   ";

    if(zero_cnt==0) {
        cout<<size-1<<endl;    return;
    }

    // last zeeros
    int m=size-1;   ll moves=0;
    while(s[m]=='0' && m>0) {
        moves++;
        m--;
    }

    int rem_zeros = zero_cnt - moves;

    cout<<size-rem_zeros-1<<endl;

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