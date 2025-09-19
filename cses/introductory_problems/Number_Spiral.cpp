// Question Link - https://cses.fi/problemset/task/1071 
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

*/

void solve() {
    ll x, y; cin>>x>>y;
    ll begin=0;
    if(x>=y) {
        if(x&1) {
            x--;
            begin=x*x; begin++;
            FOR(i, y-1) begin++;
        } else {
            begin=x*x;
            FOR(i, y-1) begin--;
        }
    } else {
        if(!(y&1)) {
            y--;
            begin=y*y; begin++;
            FOR(i, x-1) begin++;
        } else {
            begin=y*y;
            FOR(i, x-1) begin--;
        }
    }
    cout<<begin<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment for multi-test
    while (t--) solve();
}
