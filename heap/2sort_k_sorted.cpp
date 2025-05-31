// Question Link - https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int j=0;
        
        for(int i=0; i<arr.size(); i++) {
            pq.push(arr[i]);
            
            if(pq.size()>k) {
                arr[j]=pq.top(); pq.pop(); j++;
            }
        }
        
        while(j<arr.size()) {
            arr[j]=pq.top(); pq.pop(); j++;
        }
    }
};