// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// n=2^x
bool isPowerOfTwo(int n) {
    if(n<=0)   return false;
    return ((n & n-1)==0);
}

// Right Shift
// n>>k = n/2^k



