#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int floorSqrt(int n) {
        int low=1, high=n, mid;
        
        while(low<=high) {
            mid = low+(high-low)/2;
            
            if(mid*mid == n)    return mid;
            else if((mid*mid) < n && ((mid+1)*(mid+1)) >n) return mid;
            
            if(mid*mid > n) high=mid-1;
            else low=mid+1;
        }
    }
};