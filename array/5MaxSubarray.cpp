// Question Link - https://leetcode.com/problems/maximum-subarray/description/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int sum=0; int maxx=INT_MIN, n=nums.size();
            // SOLUTION 1
            // for(int i=0; i<n; i++) {
            //     for(int j=i; j<n; j++) {
            //         sum=0;
            //         for(int k=j; k<n; k++) {
            //             sum=sum+nums[k];
            //             // cout<<"Sum: "<<sum<<endl;
            //             maxx=max(maxx, sum);
            //         }
            //     }
            // }
            // sum=accumulate(nums.begin(), nums.end(), 0);
            // maxx=sum;
    
    
            // SOLUTION 2
            // for(int i=0; i<n; i++) {
            //     sum=0;
            //     for(int j=i; j<n; j++) {
            //         cout<<"Sum: "<<sum<<endl;
            //         sum+=nums[j];
            //         maxx=max(maxx, sum);
            //     }
            // }
    
    
            // SOLUTION 3 - KADANE'S ALGO
            // int sum1=0, sum2=0;
            for(int i=0; i<n; i++) {
                sum+=nums[i];
                maxx=max(sum, maxx);
                
                if(sum<0)   sum=0;
            }
    
            return maxx;
        }
    };