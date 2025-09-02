// Question Link - https://leetcode.com/problems/sort-colors/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    - Core Mental Hook
    Whenever you see "3 categories, arrange in order" (colors, numbers, partitioned zones), the Dutch National Flag algorithm should click:
        low = boundary for 0s
        high = boundary for 2s
        mid = explorer of unknown territory

    - Intuition
    You’re basically partitioning the array into 3 sections in a single pass:
        Left side (0s zone) → everything before low is guaranteed to be 0.
        Right side (2s zone) → everything after high is guaranteed to be 2.
        Middle (1s zone + unknown) → what’s between low and high is not yet processed, and mid is the pointer that explores this "unknown land".
    So, the job of mid is like a scanner:
        If it sees a 0 → send it to the 0s zone (left) and move both low and mid.
        If it sees a 2 → send it to the 2s zone (right), but don’t move mid because the swapped-in element is still unprocessed.
        If it sees a 1 → it’s already in the middle zone where it belongs, so just move mid.
*/

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            // SOLUTION 1 - USING FREQUENCY ARRAY
            // vector<int> freq(3,0);
            // for(int i=0; i<nums.size(); i++) {
            //     freq[nums[i]]++;
            // }
            // int i=0;
            // for(int j=0; j<freq.size(); j++) {
            //     int count = freq[j];
            //     while(count!=0) {
            //         nums[i]=j;
            //         count--; i++;
            //     }
            // }
    
    
            // SOLUTION 2 - Dutch national flag algorithm
            int low=0, mid=0, high=nums.size()-1;
            while(mid<=high) {
                // if(nums[low]==0 && low<mid)    low++;
                // if(nums[high]==2)    high--;
    
                if(nums[mid]==2) {
                    swap(nums[mid], nums[high]);
                    high--; 
                } else if(nums[mid]==0) {
                    swap(nums[mid], nums[low]);
                    low++; mid++;
                } else {
                    mid++;
                }
    
                // cout<<"low: "<<low<<" mid: "<<mid<<" high: "<<high<<endl;
            }
        }
    };