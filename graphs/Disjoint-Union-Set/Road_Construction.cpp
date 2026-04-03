// Question Link: https://cses.fi/problemset/task/1676/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>

/*
    Think Simple
*/

vector<int> par, sz;
int comp;
int mx=0;

int find_par(int a) {
    if(par[a]==a) return a;
    return par[a]=find_par(par[a]);
}

void union_(int a, int b) {
    int par_a = find_par(a);
    int par_b = find_par(b);
    if(par_a==par_b) return;

    // swapping, to keep a always greater
    if(sz[par_a]<sz[par_b]) swap(par_a, par_b);
    par[par_b]=par_a;
    sz[par_a]+=sz[par_b];
    comp--; mx=max(mx, sz[par_a]);
}

void solve() {
    int n, m; cin>>n>>m;
    par.resize(n+1, 0);
    sz.resize(n+1, 1);
    comp=n;
    for(int i=1; i<=n; i++) par[i]=i;

    while(m--) {
        int u, v; cin>>u>>v;
        union_(u, v);
        cout<<comp<<" "<<mx<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin>>t;
    while(t--) solve();
}
