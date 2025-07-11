// Question Link - https://www.geeksforgeeks.org/problems/implement-upper-bound/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// upper bound - smallest index in the given array where element is greater than target

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int low=0, high=arr.size()-1, mid;
        
        while(low<=high) {
            mid=(low+high)/2;
            
            if(arr[mid]<=target) low=mid+1;
            else high=mid-1;
        }
        
        return low;
        
    }
};