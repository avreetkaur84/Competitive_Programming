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
    ll n; cin >> n;
    ll target = (n*(n+1))/2;
    if(target&1) {
        cout<<"NO"<<"\n"; return;
    } else cout<<"YES\n";

    // cout<<target<<" ";
    target/=2;

    set<ll> st;
    ll sum=0; int x=n;
    while(sum+x<=target) {
        sum+=x;  st.insert(x); x--;
    }
    if(sum<target) st.insert(target-sum);

    cout<<st.size()<<"\n";
    for(auto it : st) cout<<it<<" ";
    cout<<"\n"<<n-st.size()<<"\n";

    for(int i=1; i<=n; i++) {
        if(st.find(i)==st.end()) cout<<i<<" ";
    }
    cout<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    // int t = 1;
    // cin >> t; // uncomment for multi-test
    // while (t--) solve();
}
