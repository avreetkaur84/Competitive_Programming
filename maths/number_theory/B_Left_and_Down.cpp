// Question Link - https://codeforces.com/contest/2125/problem/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    if(a<b) swap(a, b);
    return gcd(b, a % b);
}

void solve() {
    long long a, b, k;  cin>>a>>b>>k;
    // cout<<gcd(a, b)<<"  ";
    if((a<=k && b<=k)) {
        cout<<1<<endl; return;
    }

    int g = gcd(a, b);
    if(a/g<=k && b/g<=k) {
        cout<<1<<endl; return;
    }

    cout<<2<<endl;
    
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