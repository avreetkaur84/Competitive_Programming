// Question Link - 

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 1.min freq >=2
// 2. min multiples >=2

// ll gcd(ll a, ll b) {
//     if(b==0)    return a;
//     if(b>a) swap(a, b);
//     return gcd(b, a%b);
// }

void solve() {
    int n;  cin>>n;
    vector<ll> arr(n);
    ll minn = LONG_LONG_MAX;
    vector<ll> fact;
    int cnt = 0;
    ll gcd_ = 0;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
        minn = min(arr[i], minn);
    }

    for(int i=0; i<n; i++) {
        if(arr[i]==minn)    cnt++;
        else if(arr[i]%minn==0) fact.push_back(arr[i]);
    }

    if(cnt>=2) {
        cout<<"Yes"<<endl;  return;
    }

    // checking gcd
    if(fact.size()>0) {
        gcd_ = fact[0];
        for(int i=1; i<fact.size(); i++) {
            gcd_ = __gcd(gcd_, fact[i]);
            // gcd_ = gcd(gcd_, fact[i]);
        }
    }

    if(gcd_==minn) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    // else cout<<"No"<<endl;
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