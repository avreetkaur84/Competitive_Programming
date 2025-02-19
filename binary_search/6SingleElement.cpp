// Question Link - https://leetcode.com/problems/single-element-in-a-sorted-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int singleNonDuplicate(vector<int>& nums) {
    // Another Big Problem : I don't cover edge cases.

    /*
        Two Steps -
        1. Check if mid is single , if not, step 2
        2. Which half to exclude -
            1. If mid is even index(0 based) - if it has double element in first half, then exclude, second half, else first half.
            2. If mid is odd - if double element is in first half, then exclude first half, else secind half.
    */

    if(nums.size()==1)  return nums[0];

    int low=0, high=nums.size()-1, mid;

    while(low<=high) {
        mid = low+(high-low)/2;
        // cout<<mid<<endl;
        if(mid==0 && nums[mid]!=nums[mid+1])    return nums[mid];
        if(mid==nums.size()-1 && nums[mid]!=nums[mid-1])    return nums[mid];

        // condition will fail for nums[0] and nums[size-1]
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1] && 1<=mid<=nums.size()-2) {
            return nums[mid];
        } else {
            if(mid%2==0) {
                if(nums[mid-1]==nums[mid]) high = mid-1;
                else low = mid+1;
            } else {
                if(nums[mid]==nums[mid-1]) low=mid+1;
                else high=mid-1;
            }
        }
    }

    return -1;
}