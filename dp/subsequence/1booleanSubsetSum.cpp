// Question Link - https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


// memoization approach
bool cal(int idx, int target, vector<int>& arr, vector<vector<int>> &dp, int n) {
    if(target==0)  return true;
    
    // if(idx==0)  return (arr[0]==target);
    // if(idx==n)  return (arr[n]==target);
    if(idx>=n)   return false;
    
    if(dp[idx][target]!=-1) return dp[idx][target];
    
    // non-pick
    bool pick = cal(idx+1, target, arr, dp, n);
    
    // non-pick
    bool nonPick = false;
    if(target>=arr[idx]) {
        nonPick = cal(idx+1, target-arr[idx], arr, dp, n);
    }
    
    return dp[idx][target] = pick || nonPick;
}

bool isSubsetSum(vector<int>& arr, int target) {
    int size = arr.size();
    vector<vector<int>> dp(size, vector<int>(target+1, -1));
    bool flag = cal(0, target, arr, dp, size);
    return flag;
}

// tabulation
bool tabulation(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target+1, false));
    
    // TABULATION
    // BASE CASES
    for(int i=0; i<n; i++) dp[i][0]=true;
    if(arr[0]<=target)   dp[0][arr[0]]=true;     
    
    for(int i=1; i<n; i++) {
        for(int tar=1; tar<=target; tar++) {
            bool nonPick = dp[i-1][tar];
            bool pick = false;
            if(tar>=arr[i]) {
                pick = dp[i-1][tar-arr[i]];
            }
            
            dp[i][tar] = nonPick || pick;
        }
    }
    
    return dp[n-1][target];
    
}