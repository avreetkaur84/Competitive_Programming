// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

// normal method
ll res=1;
ll normal(ll a, ll b) {
    if(b==0) return 1;

    res = normal(a, b/2);
    if(b%2) return res*res*a;
    else return res*res;
}