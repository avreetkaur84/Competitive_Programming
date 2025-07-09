// Question Link - https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// I solved this question after watching the youtube tutorial - I was only able to code the brute force approch
// Prefix sum with hashmap -> reverse engineering
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        long long sum=0; int n=arr.size(), maxx=0;
        unordered_map<long long, int> mp;
        
        for(int i=0; i<n; i++) {
            sum+=arr[i];
            
            if(sum==k) maxx = max(maxx, i+1);
            if(mp.find(sum-k) != mp.end()) maxx = max(maxx, i-mp[sum-k]);
            if(mp.find(sum) == mp.end()) mp[sum]=i;
        }
        
        return maxx;  
    }
};


// SLIDING WINDOW - PENDING (CORRECT THE CODE BELOW LATER ON) -> will work only for positives
int longestSubarrayWithSumK(vector<int> arr, long long k) {
    // Write your code here
    int i=0, j=0, maxx=0;
    long long sum=0;
    while(j<arr.size()) {
        if(sum+arr[j]==k) {
            maxx = max(maxx,j-i+1);
            sum = sum+arr[j]-arr[i];
            i++; j++;
        } else if(sum+arr[j]<k) {
            sum+=arr[j]; j++;
        } else {
            sum = sum+arr[j]-arr[i];
            i++; j++;
        }
    }
    return maxx;
}