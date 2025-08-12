// Question Link - https://codeforces.com/contest/2131/problem/C

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Key Idea -
    1. Here, x+k and x-k operation will result in same remainder. So, if two numbers have same remainder, then we can construct one numer from another.
    2. Therefore, if remainders are equal in oth sets, they can haev same numbers.
    3. Here is a catch when, |x-k| -> x<k -> here, remainder will change to (k-(x%k)) -> so, we take the min of both, x%k and k-(x%k) to keep consistency.
*/

void rem_min(vector<ll> &a, ll k) {
    for(int i=0; i<a.size(); i++) {
        ll x = a[i]%k;
        a[i]=min(x, k-x);
    }
}

void solve() {
    ll n, k;  cin>>n>>k;
    vector<ll> a(n); vector<ll> b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    
    rem_min(a, k); rem_min(b, k);
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    if(a!=b) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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