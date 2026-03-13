// Question Link - https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

/*
 1. Check in which side of array mid belongs. 
    - If a[low]<mid - mid belongs to first sorted array
    - if a[low]>mid - mid belongs to second sorted array
2. If mid belongs to first half, then,  
    - check if target is in range between low and mid, if yes, high=mid-1
    - if no, low=mid+1
3. If mid belongs to secong half, then,
    - check if target is in range between mid and high, if yes, low=mid+1
    - if no, then, high=mid-1;
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(), low=0, high=n-1, mid;

        while(low<=high) {
            mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            // cout<<nums[low]<<" "<<nums[mid]<<" "<<nums[high]<<"\n";

            if(nums[mid]>=nums[low]) {
                // belongs to first half
                if(target>=nums[low] && target<nums[mid]) high=mid-1;
                else low=mid+1;
            } else {
                // belongs to second half
                if(target>nums[mid] && target<=nums[high]) low=mid+1;
                else high=mid-1;
            }
        }

        return -1;
    }
};