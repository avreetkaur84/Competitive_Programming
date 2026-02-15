// Question Link - https://leetcode.com/problems/count-subarrays-with-cost-less-than-or-equal-to-k/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<long long> maxx, minn;
        int n=nums.size(), l=0;
        long long res=0, cost=0;
        for(int i=0; i<n; i++) {
            // maxx
            while(!maxx.empty() && nums[maxx.back()]<nums[i]) maxx.pop_back();
            maxx.push_back(i);

            // minn
            while(!minn.empty() && nums[minn.back()]>nums[i]) minn.pop_back();
            minn.push_back(i);
            
            cost = 1ll*(nums[maxx.front()]-nums[minn.front()])*(i-l+1);
            while(cost>k) {
                if(!maxx.empty() && maxx.front()<=l) maxx.pop_front();
                if(!minn.empty() && minn.front()<=l) minn.pop_front();
                l++;
                cost = 1ll*(nums[maxx.front()]-nums[minn.front()])*(i-l+1);
            }

            res+=i-l+1;
        }



        return res;
    }
};