// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

/*
    n -> 1 to n
    small complete once -> to get next big
    points -> 
    only k -> max. points
*/

void inArr(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void outArr2d(vector<vector<int>> arr) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void solve() {
    int n, k;  cin>>n>>k;
    vector<int> a(n); inArr(a, n);   
    vector<int> b(n); inArr(b, n);
    vector<int> pf(n); pf[0]=a[0];

    // convert b to max b
    for(int i=1; i<n; i++) b[i] = max(b[i-1], b[i]);    
    for(int i=1; i<n; i++) pf[i] = pf[i-1]+a[i];

    int maxx=0; int i=0;
    while(k>0 && i<n) {
        k--;
        maxx = max(pf[i]+(k*b[i]), maxx);
        i++; 
        // cout<<maxx<<"\n";
    }

    // outArr(b);
    cout<<maxx<<"\n"; 
    // cout<<"\n";
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