// Question Link - https://codeforces.com/problemset/problem/1765/M

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    BRUTE FORCE INTUTION - 
    1. I can explore all the possible numbers and then choose the LCM.
    2. LCM can't be found directly, so I will find gcd, then from it, LCM
    --- GOT TLE FOR BRUTE FORCE, NOW I HAVE TO THIK OF AN EQUATION --- I need to know LCM properties
    3. In this problem they asked us to find LCM -> but we didn't even perform the operation -> so, I need to ingrane this in mind, don't just focus on operation but on the effect operation will have if its performed.
*/

int gcd(int a, int b) {
    if(b==0) return a;

    if(a != max(a, b)) {
        a = a^b;
        b = a^b;
        a = a^b;
    }
    return gcd(b, a%b);
}

void solve() {
    ll n;  cin>>n;
    ll res = INT_MAX;
    ll a=1;

    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) {
            a = n/i;
            break;
        }
        
        // int g = gcd(n-i, i);
        // lcm = (a*b)/gcd
        // if(res>(i*(n-i))/g) {
        //     res = (i*(n-i))/g;
        //     a = i; b=n-i;
        // }
    }
    
    cout<<a<<" "<<n-a<<endl;
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