// Question Link - https://leetcode.com/problems/palindrome-partitioning/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void rec(int idx, vector<int> &nums) {
        if(idx==nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++) {
            swap(nums[i], nums[idx]);
            rec(idx+1, nums);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        rec(0, nums);
        return res;
    }
};