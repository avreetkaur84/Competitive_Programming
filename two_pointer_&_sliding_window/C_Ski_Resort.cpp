// Question Link - https://codeforces.com/problemset/problem/1840/C

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, k, q;  cin>>n>>k>>q;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int i=0, j=0;
    ll cnt=0, maxx=0;
    while(j<n) {
        if(arr[j]<=q) cnt++;

        if(arr[j]>q) {
            cnt=0; i=j+1;
        }

        if(cnt>=k && i<n) {
            maxx+=(j-i+2-k);
        }

        // cout<<"i: "<<i<<"   j: "<<j<<"  maxx: "<<maxx<<endl;

        j++;
    }
    

    cout<<maxx<<endl;
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