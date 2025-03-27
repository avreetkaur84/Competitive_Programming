// Question Link - https://codeforces.com/problemset/problem/1829/B

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int cnt=0, i=0, j=0, maxx=0;
    while(i<n) {
        if(arr[i]==0) {
            cnt++;
        } else {
            cnt=0;
        }
        maxx=max(cnt, maxx);
        i++;
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