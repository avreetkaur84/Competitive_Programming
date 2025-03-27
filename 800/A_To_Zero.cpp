// Question Link - https://codeforces.com/contest/2075/problem/A

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, k; cin>>n>>k;
    ll cnt=0;
    // 1 to k - range;
    // if(n%k==0) {
    //     cout<<n/k<<endl; return;
    // }

    if(n%2!=0) {
        n=n-k;  cnt++;
    }

    // now n is even
    ll rem = n%(k-1);
    cnt+=n/(k-1);
    if(rem!=0)  cnt++;

    // cnt += n / (k - 1);
    // if (n % (k - 1) != 0) {
    //     cnt++; // If there is a remainder, we need one extra step
    // }


    cout<<cnt<<endl;

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