// Question Link - https://leetcode.com/problems/split-array-largest-sum/description/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int arrParts(vector<int>& nums, int x) {
            long long sum=0; int cnt=0;
            for(int i=0; i<nums.size(); i++) {
                if(sum+nums[i]<=x)  sum+=nums[i];
                else {
                    cnt++; 
                    sum=nums[i];
                }
            }
            cnt++;
            return cnt;
        }
    
        int splitArray(vector<int>& nums, int k) {
            long long prefixSum=0;
            for(int &x : nums)  prefixSum+=x;
    
            long long low=*max_element(nums.begin(), nums.end());
            long long high = prefixSum, mid;
    
            while(low<=high) {
                mid = low+(high-low)/2;
    
                int parts = arrParts(nums, mid);
    
                cout<<"low:"<<low<<"    mid:"<<mid<<"   high:"<<high<<"   parts:"<<parts<<endl;
    
                if(parts<=k) high=mid-1;
                else low=mid+1;
            }
    
            return low;
        }
    };