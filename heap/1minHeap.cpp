// Question Link - https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
HEAP CHEAT SHEET:

1. Min Heap:
   - Top() gives SMALLEST element
   - In C++: priority_queue<int, vector<int>, greater<int>>
   - Used when:
       -> You want to KEEP largest elements
       -> You want to REMOVE smallest elements

   Example: Kth LARGEST element
   Strategy:
   - Keep only K largest elements in heap
   - Whenever size > K, remove the SMALLEST
   - After processing all elements:
       -> Top() = Kth largest
*/

/*
2. Max Heap:
   - Top() gives LARGEST element
   - In C++: priority_queue<int>
   - Used when:
       -> You want to KEEP smallest elements
       -> You want to REMOVE largest elements

   Example: Kth SMALLEST element
   Strategy:
   - Keep only K smallest elements in heap
   - Whenever size > K, remove the LARGEST
   - After processing all elements:
       -> Top() = Kth smallest
*/


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