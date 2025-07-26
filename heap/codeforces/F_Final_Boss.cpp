// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int h, n;  cin>>h>>n;
    vector<int> attacks(n); vector<int> down(n);
    for(int i=0; i<n; i++) cin>>attacks[i];
    for(int i=0; i<n; i++) cin>>down[i];

    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll, int>>> pq;    // {active attack, attack index}
    for(int i=0; i<n; i++) pq.push({1, i});
    ll turn=0;

    while(!pq.empty() && h>0) {
        pair<ll, int> cur = pq.top(); pq.pop();
        h-=attacks[cur.second]; 
        pq.push({cur.first+down[cur.second], cur.second});
        // cout<<cur.first<<" "<<turn<<" "<<h<<endl;
        turn = cur.first;
    }

    cout<<turn<<endl;
    // cout<<endl;
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