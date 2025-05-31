// Question Link - https://www.geeksforgeeks.org/problems/prime-factors5052/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

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