// Question Link - https://leetcode.com/problems/4sum/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// This pronlem was fucking Good!!! I mean it.
/*
    What I learnt from this problem -
    1. Always try to begin each question from brute force, because here, first I tried to solve this using 4 loops, and got to now how exactly solution will be made. I figured out duplicates problem.
    2. Then the transition to two pointer or binary search, and what made it interesting was that, I had 4 loops but for 2 pointers I can reduce only 2 loops, like can have 2 pointers, so, I had to think how to handle and chnage the outer loops.
    4. This question taught me how to use binary serach like a pro, means I can't say its proper binary serach but similar to binary search, as we focused on chnaging the pointers on basis of the value, like if value is greater than target, then increase k or vice versa.
*/

// BRUTE FORCE
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;
        set<vector<int>> st;

        for(int i=0; i<n-3; i++) {
            for(int j=i+1; j<n-2; j++) {
                for(int k=j+1; k<n-1; k++) {
                    for(int l=k+1; l<n; l++) {
                        int temp = nums[i]+nums[j]+nums[k]+nums[l];
                        if(temp==target) {
                            vector<int> arr = {nums[i], nums[j], nums[k], nums[l]};
                            sort(arr.begin(), arr.end());
                            if(st.find(arr)==st.end()) {
                                res.push_back(arr);
                            }
                            st.insert(arr);
                        }
                    }
                }
            }
        }

        return res;
    }
};


// OPTIMISED
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i=0, j=i+1, k=j+1, l=n-1;
        long long temp=0; 

        while(i<n-3) {
            // cout<<"i: "<<i<<"   j: "<<j<<endl;
            if(j>=n-2) {
                int prev=nums[i]; i++;
                while(i<n-3 && prev==nums[i]) i++;
                if(i==n-3) break;
                j=i+1; k=j+1; l=n-1;
            }
            while(j<n-2) {
                // cout<<"i: "<<i<<"   j: "<<j<<"  k: "<<k<<"   l: "<<l<<endl;
                if(k>=l) {
                    // if(temp==target) res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    int prev=nums[j]; j++;
                    while(j<n-2 && prev==nums[j]) j++;
                    if(j==n-2) break;
                    k=j+1; l=n-1;
                }

                // cout<<nums[i]<<"   "<<nums[j]<<"   "<<nums[k]<<"   "<<nums[l]<<endl;
                temp=(long long)nums[i]+nums[j]+nums[k]+nums[l];

                if(temp<target) {
                    // move in +ve -> k++;
                    int prev=nums[k]; k++;
                    while(k<n && prev==nums[k]) k++;
                } else if(temp>target) {
                    // move in -ve -> l--
                    int prev=nums[l]; l--;
                    while(l>0 && nums[l]==prev) l--;
                } else {
                    res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    int prev=nums[k]; k++;
                    while(k<n && prev==nums[k]) k++;

                    int prev2=nums[l]; l--;
                    while(l>=0 && prev2==nums[l]) l--;
                }
            }
        }
        
        return res;
    }
};