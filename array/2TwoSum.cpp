// Question Link - https://leetcode.com/problems/two-sum/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> res;
            // SOLUTION 1
            // for(int i=0; i<nums.size(); i++) {
            //     for(int j=i+1; j<nums.size(); j++) {
            //         if(nums[i]+nums[j] == target) {
            //             res.push_back(i);
            //             res.push_back(j);
            //             return res;
            //         }
            //     }
            // }
    
            // SOLUTION 2
            unordered_map<int, vector<int>> mp;
            for(int i=0; i<nums.size(); i++) {
                mp[nums[i]].push_back(i);
            }
    
            for(int i=0; i<nums.size(); i++) {
                int a = nums[i];
                mp[nums[i]].erase(mp[nums[i]].begin()); 
                int ele = target-nums[i];
                if(mp.find(ele)!=mp.end() && !mp[ele].empty()) {
                    res.push_back(i);
                    res.push_back(mp[ele].back());
                    return res;
                }
            }
            
            return res;
        }
    };