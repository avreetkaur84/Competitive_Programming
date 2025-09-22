// Question Link - 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORRE(i, n) for (int i = (n) - 1; i >= 0; --i)
#define RGN(i, a, b) for (int i = (a); i < (b); ++i)
#define RGNRE(i, a, b) for (int i = (a); i >= (b); --i)
#define EACH(x, a) for (auto& x : a)

ll MOD = 1000000007;

/*
    why left shift failed for large values?? -> I guess modulo
*/

// binomial exponentiation
ll bex(ll a, ll b) {
    int res=1;
    while(b>0) {
        if(b&1) res=(res*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }    

    return res;
}


void solve() {
    ll n; cin >> n;
    cout<<bex(2, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t = 1;
    // cin >> t; // uncomment for multi-test
    // while (t--) solve();
    solve();
}
