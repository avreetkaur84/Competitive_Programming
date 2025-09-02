// Question Link - https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // start with memoization
      int memoization(int k, vector<int> &arr, vector<int> &dp, int n) {
          if(n==0)    return 0;
          if(dp[n]!=-1)   return dp[n];
          
          // dp[n] = dp[n-1]+energy[n-1]
          
          int minVal=INT_MAX;
          for(int i=1; i<=k; i++) {
              if(n-i>=0) {
                  int res = memoization(k, arr, dp, n-i) + abs(arr[n]-arr[n-i]);   
                  minVal = min(minVal, res);
              } 
          }
          
          return dp[n] = minVal;
      }
      
      int minimizeCost(int k, vector<int>& arr) {
          int n = arr.size();
          vector<int> dp(n, -1);
          
          return dp[n-1] = memoization(k, arr, dp, n-1);
      }
  
      int tabulation(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        
        dp[0] = 0;
        
        for(int i=1; i<n; i++) {
            int j=1; int minVal=INT_MAX;
            while(j<=k && i-j>=0) {
                int res = dp[i-j] + abs(arr[i]-arr[i-j]);
                minVal = min(minVal, res);
                j++;
            }
            dp[i] = minVal;
        }
        
        return dp[n-1];
    }
};