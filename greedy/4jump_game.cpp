// Question Link - https://leetcode.com/problems/jump-game/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(), maxReach=0;

        for(int i=0; i<n-1; i++) {
            maxReach = max(maxReach, nums[i]);
            if(maxReach==0) return false;
            maxReach--;
        }

        return true;
    }
};