// Question Link - https://leetcode.com/problems/sort-colors/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

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