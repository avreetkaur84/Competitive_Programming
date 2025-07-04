// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Key DP Lesson: Never stop recursion early when counting subsets. Only evaluate the sum at the leaf node (last index). Especially important when zeros are involved.

    I first thought of using bool to store the numners in dp array,as I thought I will cnt the times the target coulm is true, but this is wrong, as -
    1. Bool - can I reach the target
    2. int - in how many ways can I reach the target.
    The question is of how many times the target can occur, so, need to use cnt

    // if(curr==target) return 1;  - this fucking one line of code, made me stumble on thsiproblem for two days, made me question my whole existence, I mean it. 
    // But yeah Got my lesson - don't fall for fixed patterns, need to elevate accroding to constraints and condition. Here earlier I returned 1, once target was met, but in case when target was zero it failed, because 0 can be target if there are further 0 after achieving it. So, need to understand the problem in depth and not just cram the basic dp structure.

    // Now, tabluation - another hurdle - 
    1. I think it was worth it to sacrifice 2 days on this problem, bcz bro I am not kiding but I fucking designed the whole tabulation from scratch, like after observing my memoization solution and then making the table and after dry running it on notebook, I constructed the code. Like it feels good. Maybe I have come to know 10% of dp, like maybe
*/

class Solution {
  public:
  
    int helper(int idx, int curr, int target, vector<int> &arr, vector<vector<int>> &dp) {
        int cnt=0;
        
        // if(curr==target) return 1;
        
        if(idx>=arr.size()) return curr==target ? 1 : 0;
        
        if(dp[idx][curr] != -1) return dp[idx][curr];
        
        // choices
        if(curr+arr[idx]<=target) {
            cnt += helper(idx+1, curr+arr[idx], target, arr, dp);
        } 
        
        cnt += helper(idx+1, curr, target, arr, dp);
        return dp[idx][curr] = cnt;
    }
  
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size(), cnt=0;
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        
        return helper(0, 0, target, arr, dp);
        
        // return cnt;
    }
};



// TABULATION
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
        
        for(int i=0; i<=n; i++) dp[i][target]=1;
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=target; j++) {
                int cnt=0;
                if(arr[i-1]+j<=target) {
                    cnt += dp[i-1][j+arr[i-1]];
                } 
                
                cnt += dp[i-1][j];
                dp[i][j] = cnt;
            }
        }
        
        return dp[n][0];
    }
};