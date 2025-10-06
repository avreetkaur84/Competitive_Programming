// Question Link - https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Second approach - most optimised - two pointers - 3 oct, 2025
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0, j=n-1, l_mx=height[i], r_mx=height[j], res=0;

        while(i<=j) {
            if(l_mx<=r_mx) {
                res += max(0, l_mx-height[i]);
                i++; 
                if(i<n) l_mx = max(l_mx, height[i]);
            } else {
                res += max(0, r_mx-height[j]);
                j--; 
                if(j>-1) r_mx = max(r_mx, height[j]);
            }
        }

        return res;
    }
};

// My first approach - unexpected AC - I was just playing with technique and boom - Prefix and sufix - 14 july, 2025
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefix(n); vector<int> suffix(n);
        int p_lar=height[0]; int s_lar=height[n-1];

        for(int i=0; i<n; i++) {
            if(height[i]>p_lar) p_lar=height[i];
            prefix[i]=p_lar-height[i];
        }

        for(int i=n-1; i>=0; i--) {
            if(height[i]>s_lar) s_lar=height[i];
            suffix[i]=s_lar-height[i];
        }

        int sum=0;
        for(int i=0; i<n; i++) sum+=min(suffix[i], prefix[i]);

        return sum;
    }
};