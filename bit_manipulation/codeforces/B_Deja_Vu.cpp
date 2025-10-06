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

/*
    - if num is divisible by 2^x, then it is divisible by all the 2^y, where y<x.
    - if num is not divisible by 2^x, it is not divisible by any 2^y, where y>x
    - and after performing num+2^x-1 -> now, num won't be dvisible by any 2^y, where y>=x. So, this will help to reduce the time complexity.
*/

void solve() {
    int n, q; cin>>n>>q;
    vll arr(n); FOR(i, n) cin >> arr[i];
    vll x(q); FOR(i, q) cin >> x[i];
    ll minn = LLONG_MAX;

    FOR(i, q) {
        ll val = 1<<x[i];
        if(val>=minn) continue;
        minn = min(minn, val);
        FOR(j, n) {
            if(arr[j]%val==0) arr[j]+=(val>>1);
        }
    }

    FOR(i, n) cout<<arr[i]<<" ";
    cout<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment for multi-test
    while (t--) solve();
}