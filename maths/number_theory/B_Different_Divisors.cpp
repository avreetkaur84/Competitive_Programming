// Question Link - https://codeforces.com/problemset/problem/1474/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
Here we have to find the number in a range, so we can use binary search, but I am not sure about what I should consider as end of the range.
-- This question is pure maths based -> divisors and prime factorization concept
-- From prime factorization we will get no of divisors a particular number can have.

1. Smallest prime greater than equal to d+1 -> p : then p^3 will be ans
2. q >= p+d
3. ans = min(p^3, p*q)

p^3 -> p is prime and has 4 factors according to prime factors theory of divisors
p*q -> will have 4 divisors -> p^1*q^1 -> (1+1)*(1+1)=4
*/

ll small_prime(ll x) {
    while(true) {
        bool flag=true;
        for(ll i=2; i*i<=x; i++) {
            if(x%i==0) {
                flag=false;
                break;
            }
        }
        if(flag) return x;
        x++;
    }

    return -1;
}

void solve() {
    ll d;  cin>>d;
    ll p = small_prime(d+1);
    ll q = small_prime(d+p);
    cout<<min(p*q, p*p*p)<<endl;
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