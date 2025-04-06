// Question Link - https://codeforces.com/contest/2092/problem/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

/* 
used gdc property - GCD(x + d, y + d) = GCD(y - x, x + d)
    gcd(a, b) == gcd(a, b - a) 
    gcd(x + d, y + d) == gcd(y - x, x + d)
*/


void solve() {
    int n;  cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    ll y = *max_element(arr.begin(), arr.end());
    ll x = *min_element(arr.begin(), arr.end());

    cout<<y-x<<endl;
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