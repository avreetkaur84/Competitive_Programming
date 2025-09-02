// Question Link - https://leetcode.com/problems/max-consecutive-ones/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int max=0, i=0, j=0;
            if(nums.size()==0)  return 0;
    
            while(j<nums.size()) {
                if(nums[j]==1) {
                    if((j-i+1)>max) max = j-i+1;
                    // cout<<max<<endl;
                    j++;
                } else {
                    j++; i=j;
                }
            }
    
            return max;
        }
    };

// OPTIMIZED 

// class Solution {
//     public:
//         int findMaxConsecutiveOnes(vector<int>& nums) {
//             int m = 0;
//             int count = 0;
    
//             for(int i=0; i<nums.size(); i++){
//                 if(nums[i] == 1){
//                     count++;
                    
//                 }
//                 else{
                    
//                     count = 0;
//                 }
//                 m = max(count, m);
//             }
    
//             return m;
//         }
//     };