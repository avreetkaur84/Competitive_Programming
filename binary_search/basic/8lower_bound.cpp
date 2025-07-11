// Question Link - https://www.geeksforgeeks.org/problems/implement-lower-bound/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Lower bound -> smallest index were the element is larger or equal than the given target. 

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int low=0, high=arr.size()-1, mid;
        
        while(low<=high) {
            mid=(low+high)/2;
            
            if(arr[mid]>=target) high=mid-1;
            else low=mid+1;
        }
        
        return low;
        
    }
};
