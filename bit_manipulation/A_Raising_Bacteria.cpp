// Question Link - https://codeforces.com/problemset/problem/579/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
When something doubles or halves, think powers of two and binary.
Ask: what does a single item contribute after the process? — if it’s 2^t, you’re in binary land.
Try to express the target as sum of contributions of single items; minimal number = minimal summands.

In this problem: the number of bacterias that will be added are equal to the number of ones that a binary form of the number can have. 
*/

int main() {
    ll x; cin>>x;
    int cnt=0;
    while(x) {
        cnt+= (x&1);
        x=x>>1;
    }

    cout<<cnt<<endl;
}