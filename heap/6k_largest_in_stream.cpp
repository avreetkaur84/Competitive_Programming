// Question Link - https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int cnt = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        // pq = {};  
        cnt=k;      
        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>cnt) pq.pop();

        if(pq.empty()) return 0;
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */