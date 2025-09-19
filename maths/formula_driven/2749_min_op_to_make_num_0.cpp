// Question Link - https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/?envType=daily-question&envId=2025-09-12

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        x = n1-K*n2
        check if x can be written in k powers of two -> k: [0 to 60]
    */
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1; i<=60; i++) {            
            long long x = num1-(1LL*i*num2);
            int set_bits = __builtin_popcountll(x);
            // set bits upper count -> x lowerbound
            if(i>=set_bits && i<=x) return i;
        }

        return -1;
    }
};