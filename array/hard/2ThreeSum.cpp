// Question Link - https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// BRUTE
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0, j=0, k=0, n=nums.size(); 
        set<vector<int>> st;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    if(nums[i]+nums[j]+nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }   

        vector<vector<int>> res(st.begin(), st.end());     

        return res;
    }

   
    // Somewhat optimized
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0, j=0, k=0, n=nums.size(); 
        set<vector<int>> st; unordered_map<int, int> mp;

        for(int i=0; i<n; i++) {
            mp = {};
            for(int j=i+1; j<n; j++) {
                int ele = -(nums[i]+nums[j]);
                mp[nums[j]]++;
                if(mp.find(ele)!=mp.end()) {
                    vector<int> temp = {nums[i], nums[j], ele};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }   

        vector<vector<int>> res(st.begin(), st.end());     

        return res;
    }

    // Optimized
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size(), i=0, j=i+1, k=n-1; 
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        if(n==3) {
            if((nums[i]+nums[j]+nums[k])==0) return {nums};
            else return res;
        } 
        
        while(i<n-2) {
            if(j>=k) {
                if(j==n && k==0) return res;
                int prev=nums[i];
                while(i<n-2 && nums[i]==prev) i++;
                j=i+1; k=n-1;
                if(j==k) return res;
            }

            int temp = nums[i]+nums[j]+nums[k];

            if(temp==0) {
                // cout<<i<<" "<<j<<" "<<k<<endl;
                res.push_back({nums[i], nums[j], nums[k]});
                int prev=nums[j]; j++;
                while(j<n && nums[j]==prev) j++;
                int pre = nums[k]; k--;
                while(k>0 && nums[k]==pre) k--;
            } else if(temp<0) {
                int prev=nums[j]; j++;
                while(j<n && nums[j]==prev) j++;
            } else {
                int prev = nums[k]; k--;
                while(k>0 && nums[k]==prev) k--;
            }
        }

        return res;
    }