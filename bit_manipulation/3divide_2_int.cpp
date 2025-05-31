// Question Link - https://leetcode.com/problems/divide-two-integers/description/?source=submission-noac

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long cnt=0; bool signal=true;

        if (dividend==INT_MIN && divisor==-1) return INT_MAX;
        if (dividend==INT_MIN && divisor==1) return INT_MIN;

        if(dividend==divisor)   return 1;
        if((dividend>0 && divisor<0)||(dividend<0 && divisor>0)) signal=false;

        cout<<signal<<endl;
        long long n = llabs((long long)dividend);
        long long x = llabs((long long)divisor); 
        int i=0;

        while(n>=x) {
            i=0;
            while(n>=(x<<(i+1))) i++;

            cnt+=(1<<i);
            n-=(x<<i);
        }

        if(cnt>INT_MAX) {
            if(signal==false) return INT_MIN;
            else return INT_MAX;
        }

        if(signal==false) return -cnt;
        else return cnt;
    }
};