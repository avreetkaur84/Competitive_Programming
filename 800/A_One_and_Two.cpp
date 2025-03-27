// Question Link - https://codeforces.com/problemset/problem/1788/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n; cin>>n; int cnt=0;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        if(arr[i]==2) cnt++;
    }

    if(cnt%2!=0) {
        cout<<-1<<endl; return;
    }

    if(cnt==0)  {
        cout<<1<<endl; return;
    }

    int cnt2=0;
    for(int i=0; i<n; i++) {
        if(arr[i]==2) cnt2++;
        if(cnt2==cnt/2) {
            cout<<i+1<<endl;  return;
        }
    }
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