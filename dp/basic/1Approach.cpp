// Question Link - https://www.geeksforgeeks.org/problems/introduction-to-dp/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-dp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// In memoization, we store the result of recursion in an array, and then directly use that result whenever required.
// In tabulation, we don't use recursion, but only array, where we start solving the prooblem by starting from base, getting the answer and then solving the main problem.

class Solution {
    public:
      const unsigned int M = 1000000007;
      
      long long int memoization(int n, vector<long long int> &dp) {
          if(n<=1)    return n;
          
          if(dp[n]!=-1)   return dp[n];
          
          dp[n]=(memoization(n-1, dp)+memoization(n-2, dp))%M;
          // cout<<"n :"<<n<<"   , dp[n]: "<<dp[n]<<endl;
          return dp[n];
      }
    
      // recursion
      long long int topDown(int n) {
          // code here
          // n+1 bcz 0 included till n
          vector<long long int> dp(n+1, -1);
          
          long long int res = memoization(n, dp);
          // cout<<"called"<<endl;
          return res;
      }
      
      long long int bottomUp(int n) {
          // code here
          vector<long long int> dp(n+1, -1);
          dp[0]=0; dp[1]=1;
          for(int i=2; i<=n; i++) {
              dp[i] = (dp[i-1]+dp[i-2])%M;
          }
          return dp[n];
      }
  };