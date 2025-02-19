// Question Link - https://leetcode.com/problems/find-peak-element/description/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// this question will be understood better with drawing teh graph of 4 cases that can occur.

int findPeakElement(vector<int>& nums) {
    int low=1, high=nums.size()-2, mid;

    // if(nums.size()==1)  return 0;
    if(nums.size()==1 || nums[0]>nums[1])  return 0;
    if(nums[nums.size()-1]>nums[nums.size()-2])  return nums.size()-1;

    while(low<=high) {
        mid = low+(high-low)/2;

        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])  return mid;
        
        else if(nums[mid]>=nums[mid-1] && nums[mid]<=nums[mid+1]) low = mid+1;
        else  high = mid-1;
    }

    return -1;
}