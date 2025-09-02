// Question Link - https://www.geeksforgeeks.org/problems/prime-factors5052/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    - When we loop from 2 upwards, every time we find a divisor i, we strip it completely from n.
    - If i were composite, it would have a smaller prime factor p < i, and we would have already divided out all p's earlier.
    - Therefore, no composite i can ever divide n at its turn — only primes survive.
    - At the end, if n > 1, it’s prime itself.
*/

// Given a number N. Find its unique prime factors in increasing order.

    vector<int> AllPrimeFactors(int n) {
        vector<int> res;
        
        if(n==1) return res;
        
        for(int i=2; i*i<=n; i++) {
            if(n%i==0) {
                res.push_back(i);
                while(n%i==0) {
                    n=n/i;
                }
            }
        }
        
        if(n>1) res.push_back(n);
        
        return res;
    }