// Question Link - https://codeforces.com/problemset/problem/1901/A

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin>>n>>x;

    vector<int> arr(n);
    for(int i=0; i<n; i++)  cin>>arr[i];

    int max=arr[0]-0;
    for(int i=1; i<arr.size(); i++) {
        if((arr[i]-arr[i-1])>max)   max=arr[i]-arr[i-1];
    }

    if(2*(x - arr[arr.size()-1]) > max) max = 2*(x - arr[arr.size()-1]);

    cout<<max<<endl;
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