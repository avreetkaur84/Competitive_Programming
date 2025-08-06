// Question Link - https://leetcode.com/problems/two-sum/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


// MOST OPTIMAL SOLUTION - 3 AUG, 2025
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            int x=target-nums[i];
            if(mp.find(x)!=mp.end()) return {mp[x], i};
            mp[nums[i]]=i;
        }

        return {};
    }
};

// NOT RIGHT SOLUTION - IT WILL FAIL AS WE HAVE TO RETURN INDEX NOT NUMBER.
class Solution {
public:
    // binary serach is not a good option for 2 sum as we have to return the indexes not numbers, so optimal choice for this question is hashmap

    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1, n=nums.size();
        sort(nums.begin(), nums.end());

        while(l<h) {
            if(nums[l]+nums[h]==target) return {l, h};
            else if(nums[l]+nums[h]<target) {
                int y=nums[l];
                while(l<n && nums[l]==y) l++;
            } else {
                int y=nums[h];
                while(h>=0 && nums[h]==y) h--;
            }
        }

        return {};
    }
};

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