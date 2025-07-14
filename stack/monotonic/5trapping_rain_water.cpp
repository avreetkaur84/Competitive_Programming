// Question Link - https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


// My first approach - unexpected AC - I was just playing with technique and boom
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