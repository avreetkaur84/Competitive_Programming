// Question Link - https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
// Min heap
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);

            if(pq.size()>k) pq.pop();
        }

        return pq.top();
    }
};

// Max heap

    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        
        for(int i=0; i<arr.size(); i++) {
            pq.push(arr[i]);
            
            if(pq.size()>k) pq.pop();
        }
        
        return pq.top();
        
    }