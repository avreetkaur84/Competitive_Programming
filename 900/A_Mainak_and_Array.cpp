// Question Link - https://codeforces.com/contest/1726/problem/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Dont think of how to perform the operation, but think what effect does this operation will have

// in cyclic arrays, just think of manipulating the indexes, instead if rotating the arrays, as it will become complex with latter

void solve() {
    int n;  cin>>n;
    vector<int> arr(n);
    int maxx=INT_MIN;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    for(int i=0; i<n; i++) {
        // keep a[0] fixed, rotate a[n-1]
        maxx = max(maxx, arr[i]-arr[0]);

        // keep a[n-1] fixed, rotate a[0]
        maxx = max(maxx, arr[n-1]-arr[i]);

        // adjacent elements difference
        if(i>0) {
            maxx = max(maxx, arr[i-1]-arr[i]);
        } else {
            maxx = max(maxx, arr[n-1]-arr[0]);
        }
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