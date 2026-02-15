// Question Link - https://leetcode.com/problems/sliding-window-maximum/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    /*
        but uske andar koi aur maxx ho sakta hai na
        dequeue will be used to solve this question
        
    */

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // store the idx
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
            while(!dq.empty() && i-dq.front()>=k) dq.pop_front();
            dq.push_back(i);
            if(i>=k-1) res.push_back(nums[dq.front()]);
        }

        return res;
    }
};