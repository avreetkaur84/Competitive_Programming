// Question Link - https://codeforces.com/problemset/problem/1878/A

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> arr(n);
    map<int, int> freq;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
        freq[arr[i]]++;
    }

    if(freq[k]!=0)  cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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