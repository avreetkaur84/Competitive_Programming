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

*/

void solve() {
    string s; cin>>s;
    int i=1, maxx=1, ans=1;
    while(i<s.length()) {
        if(s[i-1]!=s[i]) {
            ans=max(ans, maxx);
            maxx=1;
        } else maxx++;
        i++;
    }
    ans=max(ans, maxx);
    cout<<ans<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // uncomment for multi-test
    while (t--) solve();
}
