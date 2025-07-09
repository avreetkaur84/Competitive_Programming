// Question Link - https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
  public:
    // Starting with brute force, and cehcking all the possibilities
    // TC = O(n^2) - SC=O(n) -> got this sol under 5 minutes.
    int maxLength(vector<int>& arr) {
        int maxLen=0, n=arr.size();
        
        for(int i=0; i<n; i++) {
            int sum=0;
            for(int j=i; j<n; j++) {
                sum+=arr[j];
                if(sum==0) maxLen=max(maxLen, j-i+1);
            }
        }
        
        return maxLen;
    }
};

/*
    Optimal Solution - 
    1. First I tried to apply sliding wondow, But we can't as sliding window is monotonic in nature but here we have got the negavite numbers, so this will disrupt sliding window logic and it won't be effective.
    2. I tried prefix and suffix sum, but I wasn't able to observe any pattern in it, so I don't think this technique will be helpful
    3. I think 2 months ago, I solved an array question somewhat similar using map, like we were searching for remaining sum in the map - but I can't clearly remember this technique.
    4. Next, I can apply dp, but Complexities given are - O(n) for both TC and SC

*/