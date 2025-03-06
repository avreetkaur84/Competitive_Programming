// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    ll min_no = 1e9;

    for(ll i=0; i<n; i++) {
        cin>>a[i];
        if(i>0) {
            min_no=min(min_no, (a[i]-a[i-1]));
        }
    }

    // cout<<"min_no: "<<min_no<<" ";

    if(!is_sorted(a.begin(), a.end()))  {
        cout<<0<<endl;
        return;
    }

    cout << (min_no / 2) + 1 << endl;
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