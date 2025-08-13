// Question Link - https://codeforces.com/problemset/problem/1411/B

/*
    take LCM of all the digits of that no and check if that num is divisible by its lcm. And, make sure to keep checking num >=n.
    LCM*GCD=A*B
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    if(b==0) return a;
    if(a<b) swap(a, b);
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return (a/gcd(a,b))*b;
}

void solve() {
    ll n;  cin>>n;
    
    while(true) {
        ll x=n; int res=1;
        while(x>0) {
            if(x%10 != 0) res = lcm(res, x%10);
            x/=10;
        }
        if(n%res==0) {
            cout<<n<<endl; return;
        }
        n++;
    }
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