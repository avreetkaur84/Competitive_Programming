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



//  first approach
// class Solution {
//     public:
//         int bs(vector<int>& nums, int target, int low, int high) {
//             int mid;
//             while(low<=high) {
//                     mid = (low+high)/2;
    
//                     if(nums[mid]==target) return mid;
//                     else if(nums[mid]<target) low = mid+1;
//                     else high = mid-1;
//                 }
    
//             return -1;
//         }
    
//         int search(vector<int>& nums, int target) {
//             // Rotation Idx
//             int low=0, high=nums.size()-1, mid, idx=-1;
    
//             while(low<=high) {
//                 mid = low+(high-low)/2;
    
//                 if(nums[mid]==target)   return mid;
//                 else if(nums[mid]<target)   high = mid-1;
//                 else    low = mid+1;
//             }
    
//             return idx;
//         }
//     };


// Right and optimal approach

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> arr, int target) {
    int low=0, high=arr.size()-1, mid;

    while(low<=high) {
        mid = low+(high-low)/2;

        if(arr[mid]==target) {
            
        }
    }
}
