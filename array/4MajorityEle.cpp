// Question Link - https://leetcode.com/problems/majority-element/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            // SOLUTION 1 - MAP - FREQ COUNT
            // unordered_map<int, int> mp;
            // for(int i=0; i<nums.size(); i++) {
            //     mp[nums[i]]++;
            // }
            // int maxx=INT_MIN; int ele=-1;
            // for(const auto &x : mp) {
            //     if(x.second>maxx) {
            //         maxx=x.second;
            //         ele = x.first;
            //     }
            // }
            // return ele;
        
            // SOLUTION 2 - Moore's Voting Algorithm
            int cnt=1, ele=nums[0];
            for(int i=1; i<nums.size(); i++) {
                if(cnt==0 && nums[i]!=ele) {
                    ele=nums[i];    cnt++;
                } 
                else if(nums[i]==ele) {
                    cnt++;
                } else if(nums[i]!=ele) {
                    cnt--;
                }
            }
    
            return ele;
        }
    };