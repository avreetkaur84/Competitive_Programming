// Question Link - https://leetcode.com/problems/rotate-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            if(nums.size()==0)  return;
    
            // if k<n - its value will be same, but if it is greater than n, then it will have value in n range with modulus
            k = k%nums.size();
    
    
            int dif = nums.size()-k;
            
            reverse(nums.begin()+dif, nums.end());
            reverse(nums.begin(), nums.begin()+dif);
    
            reverse(nums.begin(), nums.end());
            // return nums;
        }
    };