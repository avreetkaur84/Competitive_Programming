// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

ll bin_pow(ll a, ll b) {
    ll res=1;
    while(b>0) {
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

// modular
ll bin_pow(ll a, ll b, ll m) {
    ll res=1;
    while(b>0) {
        if(b&1) res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}


int main() {
    cout<<bin_pow(2, 7)<<"\n";
}