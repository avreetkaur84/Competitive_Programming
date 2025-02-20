// Ques Link - https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // days range will be found from max and min.
    
        long max(vector<int> arr) {
            long max=arr[0];
            for(int &x : arr) {
                if(x>max)   max=x;
            }
            return max;
        }
    
        long min(vector<int> arr) {
            long min=arr[0];
            for(int &x : arr) {
                if(x<min)   min=x;
            }
            return min;
        }
    
        int calMinBouq(vector<int> arr, int m, int k, int day) {
            int totalBouq = 0;
            int cnt = 0;
    
            for(int i=0; i<arr.size(); i++) {
                // cout<<"entered"<<endl;
                if(arr[i]<=day) {
                    cnt++;
                } else {
                    totalBouq += (cnt/k);
                    // cout<<"Day: "<<day<<" : "<<cnt<<"/"<<k<<" : "<<(cnt/k)<<endl;
                    cnt = 0;
                }
            }
    
            totalBouq += (cnt/k);
            return totalBouq;
        }
    
        int minDays(vector<int>& bloomDay, int m, int k) {
            if(bloomDay.size() < (long long)m*k) return -1;
    
            long low=min(bloomDay), high=max(bloomDay), mid;
            // cout<<"Low: "<<low<<" "<<
            while(low<=high) {
                mid = low+(high-low)/2;
                int min_bouq = calMinBouq(bloomDay, m, k, mid);
                // cout<<"Min Bouq : "<<mid<<" : "<<min_bouq<<endl;
    
                if(min_bouq>=m) high=mid-1;
                else low = mid+1;
            }
            return low;
        }
    };