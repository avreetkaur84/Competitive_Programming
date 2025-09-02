// Question Link - https://usaco.org/index.php?page=viewproblem2&cpid=595

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void inArr(vector<ll> &arr, vector<ll> &pf, int n) {
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        pf[i+1]=(pf[i]+arr[i])%7;
    }
}

void outArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
    cout<<"\n";
}


/*
    Key Thing:
    1. A%M == B%M -> (A-B)%M==0
    2. Means instead of checking if differnece between two prefix sums if divisible by 7, we can directly check if mod of two numbers is same. 
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    
    int n; cin>>n;
    vector<ll> pf(n+1, 0);
    vector<ll> arr(n);
    map<ll, int> mp; int maxx=0;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
        pf[i+1]=pf[i]+arr[i];

        ll x=pf[i+1]%7;
        if(mp.find(x) != mp.end()) maxx=max(maxx, i-mp[x]);
        else mp[x] = i;
    }
    
    cout<<maxx;
    return 0;
}


int brute()
{
    int n; cin>>n;
    vector<ll> pf(n+1, 0);
    vector<ll> cows(n); inArr(cows, pf, n);

    for(int r=n; r>0; r--) {
        for(int l=0; l<r; l++) {
            if((pf[r]-pf[l])%7==0) {
                cout<<r-l; return 0;
            }
        }
    }

    return 0;
}