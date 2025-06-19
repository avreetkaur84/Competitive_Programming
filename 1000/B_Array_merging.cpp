// Question Link - https://codeforces.com/problemset/problem/1831/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, ans=1;  cin>>n;
    vector<ll> a(n); vector<ll> b(n);
    unordered_map<ll, ll> A; unordered_map<ll, ll> B;

    for(int i=0; i<n; i++)  cin>>a[i]; 
    for(int i=0; i<n; i++)  cin>>b[i];
    
    ll cnt=1; 
    for(int i=1; i<n; i++) {
        if(a[i-1]==a[i]) cnt++;
        else {
            A[a[i-1]] = max(A[a[i-1]], cnt);
            cnt=1;
        }
    }

    A[a[n-1]] = max(A[a[n-1]], cnt);

    cnt=1; 
    for(int i=1; i<n; i++) {
        if(b[i-1]==b[i]) cnt++;
        else {
            B[b[i-1]] = max(B[b[i-1]], cnt);
            cnt=1;
        }
    }

    B[b[n-1]] = max(B[b[n-1]], cnt);

    for(int i=0; i<2*n+1; i++) {
        ans = max(ans, A[i]+B[i]);
    }

    cout<<ans<<endl;

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