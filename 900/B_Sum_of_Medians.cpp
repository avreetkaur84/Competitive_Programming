// // Question Link - https://codeforces.com/problemset/problem/1440/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, k;    cin>>n>>k;
    vector<int> arr(n*k);
    ll sum=0;

    for(int i=0; i<n*k; i++)    cin>>arr[i];
    int med = n/2;
    // cout<<"med: "<<med<<"   ";

    ll s = n*k-1-med;


    while(k>=1) {
        sum+=arr[s];
        // cout<<arr[s]<<"  ";
        s-=med+1; k--;
    }

    cout<<sum<<endl;
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