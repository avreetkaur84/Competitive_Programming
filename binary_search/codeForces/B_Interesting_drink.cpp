// Question Link - https://codeforces.com/problemset/problem/706/B/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int cnt_bs(int coins, vector<int> &cost) {
    int low=0, high=cost.size()-1, mid, idx=-1;

    while(low<=high) {
        mid = low+(high-low)/2;

        if(cost[mid]<=coins) {
            idx=mid;
            low=mid+1;
        } else {
            high=mid-1;
        }
    }

    return idx+1;
}

void solve() {
    ll n;   cin>>n;
    vector<int> cost(n);
    for(int i=0; i<n; i++)  cin>>cost[i];
    
    sort(cost.begin(), cost.end());

    ll q;   cin>>q;
    vector<int> coins(q);
    for(int i=0; i<q; i++) {
        cin>>coins[i];
    }

    for(int i=0; i<q; i++) {
        cout<<cnt_bs(coins[i], cost)<<endl;
    }

}



int main()
{
    // int t;
    // cin >> t;

    solve();
    
    // while(t--)
    // {
    //     solve();
    // }
}