// Question Link - https://codeforces.com/problemset/problem/1876/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, p;  cin>>n>>p;
    vector<ll> people(n);
    map<ll, ll> cost;

    for(ll i=0; i<n; i++) cin>>people[i];

    for(ll i=0; i<n; i++) {
        ll x;  cin>>x;
        if(x<=p) cost[x]+=people[i];
    }

    ll cnt=1;  ll t_cost=p;
    for(auto& p : cost) {
        // cout<<p.first<<": "<<p.second<<"    ";
        // cout<<cnt+p.second<<",   ";
        if(cnt+p.second<=n) {
            cnt+=p.second;
            t_cost+=(p.first*p.second);
            // cout<<t_cost<<":"<<cnt<<",  ";        
        } 
        else {
            t_cost+=((n-cnt)*p.first);
            cnt+=(n-cnt);
        }
    }

    // cout<<t_cost<<":"<<cnt<<",  ";
    // cout<<n<<":"<<cnt<<",  ";

    if(cnt<n) t_cost+=((n-cnt)*p);
    cout<<t_cost<<endl;

}



int main()
{
    int t;
    cin >> t;

    
    while(t--)
    {
        solve();
    }
}