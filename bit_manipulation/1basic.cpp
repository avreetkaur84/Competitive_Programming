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

// 2220. Minimum Bit Flips to Convert Number - https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

    int minBitFlips(int start, int goal) {
        int n, count=0;
        n=start^goal;  // bits that are not same in both no's will be set

        // count no. of set bits
        while(n) {
            n=n&(n-1);   // turn off rightmost bit
            count++;
        }

        return count;
    }

// 136. Single Number - https://leetcode.com/problems/single-number/description/
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one. You must implement a solution with a linear runtime complexity and use only constant extra space.

    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0; i<nums.size(); i++) {
            res^=nums[i];
        }

        return res;
    }

