// Question Link - https://leetcode.com/problems/find-the-duplicate-number/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Find the duplicate element using Floyd cycle detection.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int slow=0, fast=0;

        while(true) {
            slow=nums[slow];
            fast=nums[nums[fast]];

            if(slow==fast) {
                slow=0;
                while(slow!=fast) {
                    slow=nums[slow];
                    fast=nums[fast];
                }
                return slow;
            }
        }

        return slow;
    }
};