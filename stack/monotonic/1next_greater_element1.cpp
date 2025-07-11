// Question Link - https://leetcode.com/problems/next-greater-element-i/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;


//  BRUTE FORCE
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<int> res;

        for(int i=0; i<n; i++) {
            bool flag=false;
            for(int j=0; j<m; j++) {
                if(flag==false && nums1[i]==nums2[j]) flag=true;
                if(flag && nums1[i]<nums2[j]) {
                    res.push_back(nums2[j]); break;
                }

                // cout<<j<<"  "<<flag<<"  ";
                if(j==m-1 && flag==true) res.push_back(-1);
            }
            // cout<<endl;
        }

        return res;
    }
};


// Optimised
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<int> res;
        unordered_map<int, int> mp;
        stack<int> st;

        for(int i=m-1; i>=0; i--) {
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(st.empty()) mp[nums2[i]]=-1;
            else {
                mp[nums2[i]]=st.top();
            }

            st.push(nums2[i]);
        }

        for(int i=0; i<n; i++) {
            res.push_back(mp[nums1[i]]);
        }

        return res;
    }
};