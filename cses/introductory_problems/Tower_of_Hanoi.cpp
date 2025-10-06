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
    Recursion

*/

void rec(int st, int end, int n, vector<pair<int, int>> &arr) {
    if(n==0) return;
    int oth = 6-(st+end);
    rec(st, oth, n-1, arr); 
    arr.push_back({st, end});
    rec(oth, end, n-1, arr); 
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> arr;
    rec(1, 3, n, arr);
    cout<<arr.size()<<"\n";
    FOR(i, arr.size()) cout<<arr[i].first<<" "<<arr[i].second<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // uncomment for multi-test
    while (t--) solve();
}