// Question Link - https://codeforces.com/contest/1855/problem/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;  cin>>n;
    vector<int> arr(n); int cnt=0;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        if(arr[i]==i+1) cnt++;
    }

    // cout<<cnt<<"    ";

    if(cnt==0)  {
        cout<<0<<endl;  return;
    } 

    cout<<ceil((double)cnt/2)<<endl;

    // if(cnt==1){
    //     cout<<1<<endl;  return;
    // }
    // if(cnt%2==0)    cout<<1<<endl;
    // else cout<<2<<endl;
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