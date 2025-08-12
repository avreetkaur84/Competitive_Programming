// Question Link - https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// others more optimised sol -
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) merged.push_back(nums1[i++]);
            else merged.push_back(nums2[j++]);
        }
        while (i < nums1.size()) merged.push_back(nums1[i++]);
        while (j < nums2.size()) merged.push_back(nums2[j++]);
        
        int n = merged.size();
        if (n % 2 == 1) return merged[n / 2];
        return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
};

// my sol -
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size=0, i=0, j=0, m=nums1.size(), n=nums2.size(), med=-1; double ans=0;
        size=m+n;  int x=0;
        if(size&1) med=ceil(double(size)/2);
        else med = size/2;
        // cout<<med<<endl;

        while(i<m && j<n) {
            // cout<<size<<" "<<ans<<endl;
            if(nums1[i]>nums2[j]) {
                x++; 
                if(x==med) {
                    ans=nums2[j]; j++; break;
                }
                j++; 
            }
            else {
                x++; 
                if(x==med) {
                    ans=nums1[i]; i++; break;
                }
                i++; 
            }
        }
        // cout<<x<<" "<<ans<<endl;

        while(i<m && x<med) {
            x++; 
            if(x==med) {
                ans=nums1[i]; i++; break;
            } 
            i++; 
        }

        while(j<n && x<med) {
            x++; 
            if(x==med) {
                ans=nums2[j]; j++; break;
            }
            j++; 
        }
        // cout<<x<<" "<<ans<<endl;

        if(size&1) return ans;
        else {
            if(j>=n) ans+=nums1[i];
            else if(i>=m) ans+=nums2[j];
            else if(nums1[i]>nums2[j]) ans+=nums2[j];
            else ans+=nums1[i];
            return ans/2;
        }
    }
};
