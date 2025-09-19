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

/*
    Problem is divided into parts, cal. flip for each index.
    Two tyeps: 
        1. 000...111 -> Flips[i]: ones_before_i+zeros_after_i
        2. 111...000 -> Flips[i]: zeros_before_i+ones_after_i
    Min flip at any point is answer
*/

void solve() {
    string s; cin>>s; int n=s.length();
    int cnt=INT_MAX;
    vi z(n, 0), o(n, 0); 
    
    if(s[0]=='1') o[0]=1;
    else z[0]=1;

    RGN(i, 1, n) {
        if(s[i]=='1') o[i]=1;
        else z[i]=1;
        o[i]+=o[i-1];
        z[i]+=z[i-1];
    }

    FOR(i, n) {
        // 111...000
        int x = z[i]+o[n-1]-o[i];
        cnt = min(cnt, x);

        // 000...111
        int y = o[i]+z[n-1]-z[i];
        cnt = min(cnt, y);
    }

    cout<<cnt<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment for multi-test
    while (t--) solve();
}
