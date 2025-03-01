// Question Link - https://leetcode.com/problems/subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void solve(vector<vector<int>> &nums, vector<int> ip, vector<int> op) {
            vector<int> op1; vector<int> op2;
    
            if(ip.size()==0) {
                nums.push_back(op);
                return;
            }
    
            op1 = op;
            op.push_back(ip[0]);
            op2 = op;
    
            if(!ip.empty()) ip.erase(ip.begin());
            solve(nums, ip, op1);
            solve(nums, ip, op2);
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> res;
    
            if(nums.size()==0)  return res;
    
            vector<int> op;
            solve(res, nums, op);
    
            return res;
        }
    };