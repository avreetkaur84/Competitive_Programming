// Question Link - https://codeforces.com/contest/2134/problem/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Concepts of this problem:
        1. GCD > 1 condition = divisibility alignment.
        2. Congruence notation (≡) and its meaning. 
            - Congruence Substitution
            - Aligning Remainders
        3. Trick: k ≡ -1 (mod k+1) → a universal way to reduce expressions.
        4. Method: choose c[i] = a[i] mod (k+1) to align divisibility.
        5. Lesson: when you want a common divisor, try forcing everything divisible by (k+1), k, or something similar.

    1. k%(k+1) = -1%(k+1)
    2. (a[i] + c[i]*K) % k+1 = 0  -> on basis of congurence subsitution
    3. c[i] = a[i]%k+1   -> came by putting k=-1 in eq. 2
    4. Formula: a[i] + (a[i]%(k+1))*k
*/

void inArr(vector<ll> &arr, ll n) {
    for(int i=0; i<n; i++) cin>>arr[i];
}

void outArr(vector<int> &arr) {
    for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";

    cout<<"\n";
}

void solve() {
    ll n, k;  cin>>n>>k;
    vector<ll> arr(n); inArr(arr, n);

    for(int i=0; i<n; i++) cout<<arr[i]+(arr[i]%(k+1))*k<<" ";
    cout<<"\n";
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