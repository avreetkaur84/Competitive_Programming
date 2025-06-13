// Question Link - https://leetcode.com/problems/majority-element-ii/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Moover's Voting Algo
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt1=0, cnt2=0, ele1=-1, ele2=-1;
        vector<int> arr;
        if(n==0) return arr;        

        for(int i=0; i<n; i++) {
            if(cnt1==0 && nums[i]!=ele2) {
                cnt1=1; ele1=nums[i];
            } else if(cnt2==0 && nums[i]!=ele1) {
                cnt2=1; ele2=nums[i];
            } else if(nums[i]==ele1) {
                cnt1++;
            } else if(nums[i]==ele2) {
                cnt2++;
            } else {
                cnt1--; cnt2--;
            }
        }

        cnt1=0; cnt2=0;

        for(int i=0; i<n; i++) {
            if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
        }

        if(cnt1>(n/3)) arr.push_back(ele1);
        if(cnt2>(n/3)) arr.push_back(ele2);

        return arr;
    }

// brute Force
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }

        for(auto i: mp) {
            if(i.second>(n/3)) arr.push_back(i.first);
        }

        return arr;
    }
};

// space o(1) - time - n log n
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt=1;
        vector<int> arr;
        sort(nums.begin(), nums.end());

        for(int i=1; i<n; i++) {
            if(nums[i-1]!=nums[i]) {
                if(cnt>(n/3)) arr.push_back(nums[i-1]);
                cnt=0;
            }

            cnt++;
        }

        if(cnt>(n/3)) arr.push_back(nums[n-1]);

        return arr;
    }

    