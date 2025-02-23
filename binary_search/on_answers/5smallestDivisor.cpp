// Ques Link - https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long max(vector<int> arr) {
            long max=arr[0];
            for(int &x : arr) {
               if(x>max)   max=x;
            }
            return max;
        }
    
        long sumArr(vector<int>& nums, int x) {
            long sum=0;
            for(int i=0; i<nums.size(); i++) {
                sum += ceil((double)nums[i]/(double)x);
            }
            return sum;
        }
    
        int smallestDivisor(vector<int>& nums, int threshold) {
            long low=1, high=max(nums), mid;
    
            while(low<=high) {
                mid = low+(high-low)/2;
    
                long sum = sumArr(nums, mid);
                cout<<"Sum : "<<mid<<" : "<<sum<<endl;
                if(sum<=threshold)  high=mid-1;
                else low=mid+1;
            }
            return low;
        }
    };