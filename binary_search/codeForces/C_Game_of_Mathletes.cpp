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
    n -> k & score=0 -> n/2
    a+b=k -> score 1 
    alice min score, bob max
*/

void solve() {
    int n, k; cin>>n>>k;
    vi arr(n); FOR(i, n) {cin>>arr[i];}
    ll score=0; int i=0, j=n-1;
    sort(all(arr));

    while(i<j) {
        int x = arr[i]+arr[j];
        if(x==k) {
            score++; i++; j--;
        } else if(x<k) i++;
        else j--;
    }

    cout<<score<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; // uncomment for multi-test
    while (t--) solve();
}
