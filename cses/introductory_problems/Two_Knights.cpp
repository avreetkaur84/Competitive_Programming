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

void solve(ll n) {
    // 1 knight can be placed at n*n pos and 2nd knight can be placed at n*n-1 pos
    ll total_pos = ((n*n)*((n*n)-1))/2;
    // 2*3: 2 attack pos and 3*2 blocks : 2=n-1 and 3=n-2
    ll attack_pos = 4*(n-2)*(n-1);     
    // cout<<total_pos<<" "<<attack_pos<<" ";
    cout<<total_pos-attack_pos<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; ll n=1;
    cin >> t; // uncomment for multi-test
    while (n<=t) {solve(n); n++;}
}