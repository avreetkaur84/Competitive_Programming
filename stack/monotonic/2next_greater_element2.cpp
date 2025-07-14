// Question Link - https://leetcode.com/problems/next-greater-element-ii/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    // in circular arrays, we assume hypothetical copy of array attached
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st; int n=nums.size();
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[i]>=st.top()) st.pop();
            st.push(nums[i]);
        }

        vector<int> res(n);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[i]>=st.top()) st.pop();
            if(st.empty()) res[i]=-1;
            else res[i]=st.top();

            st.push(nums[i]);
        }

        return res;
    }
};