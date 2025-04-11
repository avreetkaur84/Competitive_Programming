// Question Link - https://codeforces.com/problemset/problem/1475/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 2^n -> only has even factors
// even*even = even
// even*odd = even
// odd*even = even
// odd*odd = odd
// all prime factors are even except 2

void solve() {
    ll n;   cin>>n;

    // check if n is 2^x
    while(n>1) {
        if(n%2!=0) {
            cout<<"YES"<<endl;  return;
        } else {
            n/=2;
        }
    }
    // cout<<n<<"  ";

    if(n==1)    cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

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