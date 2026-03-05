// Question Link - https://leetcode.com/problems/count-subarrays-with-k-distinct-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        long long res=0;
        int n=nums.size(), left=0, minLeft=0;
        int valid_cnt=0, distinct_cnt=0;
        int freq[150000]={0};

        for(int r=0; r<n; r++) {
            freq[nums[r]]++;
            if(freq[nums[r]]==1) distinct_cnt++;
            if(freq[nums[r]]==m) valid_cnt++;

            // left inc, if dis_cnt>k
            while(distinct_cnt>k) {
                // how to ensure valid cnt is not decreased inappropriately
                if(left>=minLeft) {
                    if(freq[nums[left]]==m) valid_cnt--;
                    if(freq[nums[left]]==1) distinct_cnt--;
                    freq[nums[left]]--;
                }
                left++;
            }

            minLeft = max(minLeft, left);

            // minLeft inc, if freq[x]>m
            while(freq[nums[minLeft]]>m) {
                freq[nums[minLeft]]--;
                minLeft++;
            }

            if(distinct_cnt==k && valid_cnt==k) {
                res = 1ll*res+(minLeft-left+1);
            }

        }

        return res;
    }
};