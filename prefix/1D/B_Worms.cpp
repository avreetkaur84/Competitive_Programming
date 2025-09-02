// Question Link - https://codeforces.com/problemset/problem/474/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void inArr(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

int bs(vector<int> &arr, int x) {
    int low=1, high=arr.size(), mid;

    while(low<=high) {
        mid=low+(high-low)/2;

        if(arr[mid]<x) low=mid+1;
        else high=mid-1;
    }

    return low;
}

void solve() {
    int n;  cin>>n;  vector<int> arr(n); inArr(arr, n);
    int m;  cin>>m;  vector<int> q(m); inArr(q, m);
    vector<int> pf(n+1, 0);

    for(int i=0; i<n; i++) pf[i+1]=pf[i]+arr[i];
    for(int i=0; i<m; i++) {
        cout<<bs(pf, q[i])<<"\n";
    }
}


int main()
{
    // int t;
    // cin >> t;

    
    // while(t--)
    // {
    //     solve();
    // }
    solve();
}