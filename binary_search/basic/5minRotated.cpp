// Question Link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int low=0, high=nums.size()-1, mid=0, min=5000;
    // constratint, n can't be greater than 5000

    while(low<=high) {
        mid=low+(high-low)/2;

        if(nums[mid]>nums[low]) {
            if(min>nums[mid])   min = nums[mid];
            if(nums[low]>=nums[high])    low=mid+1;
            else    high=mid-1;
        } else {
            if(min>nums[mid])   min = nums[mid];
            high=mid-1;
        }
    }

    return min;
}