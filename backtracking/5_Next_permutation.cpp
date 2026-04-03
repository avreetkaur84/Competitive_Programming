// Question Link - https://leetcode.com/problems/next-permutation/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    // select the peak from behind and swap it with immediate neighbour, and then sort the remaining elements after swap
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), i=n-1;
        for(i; i>=0; i--) {
            if(i==0) {
                sort(nums.begin(), nums.end());
                break;
            } else if(i==n-1 && nums[i]>nums[i-1]) {
                swap(nums[i], nums[i-1]);
                break;
            } else if(nums[i-1]<nums[i] && nums[i+1]<=nums[i]) {
                int x = nums[i-1];     // replace this element
                int mn_idx = i;
                for(int j=i+1; j<n; j++) {
                    if(nums[j]>x && nums[j]<nums[mn_idx]) mn_idx=j;
                }
                swap(nums[i-1], nums[mn_idx]);
                sort(nums.begin()+i, nums.end());
                break;
            } 
        }
    }
};