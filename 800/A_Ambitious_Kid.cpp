// Question Link - https://codeforces.com/problemset/problem/1866/A

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> arr(n);
    int min=INT_MAX;
    for(int i=0; i<arr.size(); i++) {
        cin>>arr[i];
        if(min>(abs(arr[i])))   min=abs(arr[i]);
    }

    cout<<min<<endl;
}

int main()
{
    solve();
}