// Question Link - https://leetcode.com/problems/binary-subarrays-with-sum/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// SLIDING WINDOW IS MONOTONIC

// Approach 1 - prefix sum and hash map
class Approach1 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int p_sum=0, cnt=0, n=nums.size();
        unordered_map<int, int> mp;
        mp[0]=1;

        for(int i=0; i<n; i++) {
            p_sum+=nums[i];

            if(mp.find(p_sum-goal) != mp.end()) {
                cnt+=mp[p_sum-goal];
            }

            mp[p_sum]++;
        }
        

        return cnt;
    }
};

// Approach 2 - sliding window
class Solution {
public:
    int sol(vector<int>& nums, int goal) {
        if(goal<0)  return 0;
        int i=0, j=0, cnt=0, n=nums.size();
        int sum=0;
        
        while(j<n) {
            sum+=nums[j];

            if(sum>goal) {
                while(sum>goal && i<=j) {
                    sum-=nums[i]; i++;
                }
            }

            cnt+=j-i+1;
            // cout<<"i: "<<i<<"   j: "<<j<<"  sum: "<<sum<<"  cnt: "<<cnt<<endl;
            j++;
        }
        cout<<endl;

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sol(nums, goal)-sol(nums, goal-1);
    }
};