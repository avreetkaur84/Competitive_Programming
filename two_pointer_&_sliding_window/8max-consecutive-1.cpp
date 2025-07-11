// Question Link - https://leetcode.com/problems/max-consecutive-ones-iii/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    In revision solved this question in 8 minutes. Got the intution right on first try.
    Key takeway - we don't have to always perform the operation, we just have to see the result the operation will have.
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(), i=0, j=0, maxx=0;

        while(j<n) {
            if(nums[j]==0) k--;

            while(k<0) {
                if(nums[i]==0) k++;
                i++;
            }

            maxx = max(maxx, j-i+1);
            j++;
        }

        return maxx;
    }
};