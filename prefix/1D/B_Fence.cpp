// Question Link - https://codeforces.com/problemset/problem/363/B

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

void solve() {
    int n, k;  cin>>n>>k;
    vector<int> arr(n); inArr(arr, n);
    vector<int> pf(n+1, 0);

    for(int i=0; i<n; i++) {
        pf[i+1]=pf[i]+arr[i];
    }

    int minn=INT_MAX, idx=-1;

    for(int i=k; i<=n; i++) {
        if((pf[i]-pf[i-k])<minn) {
            minn=pf[i]-pf[i-k]; idx=i-k+1;
        }
    }

    cout<<idx<<endl;
    
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