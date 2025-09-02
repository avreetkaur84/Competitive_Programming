// Question Link - https://codeforces.com/contest/2131/problem/E

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    1. XOR of all items will give same result -> so, if XOR of a and b is same, then yes else no -> didn't work -> but why?? -> because XOR of both terms will be same if all its elements are same, but a and b are different in first place, so this won't work.
    2. We have to see if a's remaining elements can be transformed into b. One idx just one operation ->  but sequence can be hurdle in current logic. -> I can start from back, as i=i^i+1. So, left side elements will be impacted by sequence not right side.
*/

void inArr(vector<ll> &arr, int n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<ll> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}

void solve() {
    ll n;  cin>>n;
    vector<ll> a(n); inArr(a, n);
    vector<ll> b(n); inArr(b, n);
    vector<ll> t = a;

    for(int i=n-2; i>=0; i--) {
        if(a[i]!=b[i]) {
            if((a[i]^a[i+1])!=b[i]) a[i]=a[i]^t[i+1];
            else a[i]^=a[i+1];
        }
    }
    // outArr(a);

    // for(int i=0; i<n-1; i++) {
    //     if(a[i]!=b[i]) a[i]^=a[i+1];
    // }
    // outArr(a);
    
    for(int i=0; i<n; i++) {
        if(a[i]!=b[i]) {
            cout<<"NO\n"; return;
        }
    }

    cout<<"YES\n";
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