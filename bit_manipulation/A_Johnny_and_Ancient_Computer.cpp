// Question Link - https://codeforces.com/problemset/problem/1362/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    1. Num should have same number of 1 bits in it, as we can only manipulaet 0's by operation and not 1's
    2. Number of operations -> no of zeros after corner 1's, for 3 0's -> 1 operation, so, zeros%3 
    3. First 1 se lekar last 1 tak bits same honni chaheye

*/

// zero after ones
pair<ll, ll> zao(ll a) {
    ll cnt=0;
    while(a) {
        if(a&1) return {cnt, a};   // last bit is 1
        a=a>>1; cnt++;
    }
    return {a, cnt};
}

void solve() {
    ll a, b;  cin>>a>>b;
    // ll x = __builtin_popcountll(a);
    // ll y = __builtin_popcountll(b);
    // cout<<x<<" "<<y<<endl;

    if(a<b) swap(a, b);   // a always greater
    pair<ll, ll> m=zao(a); pair<ll, ll> n=zao(b);
    if(m.second!=n.second) {
        cout<<-1<<endl;  return;
    }

    // cout<<m<<" "<<n<<endl;
    cout<<(abs(m.first-n.first)+2)/3<<endl; 
    // cout<<"\n";
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