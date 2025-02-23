// Ques Link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long max(vector<int> arr) {
            long max=arr[0];
            for(int &x : arr) {
                if(x>max)   max=x;
            }
            return max;
        }
    
        long daysReq(vector<int>& arr, int x) {
            long sum=0; int cnt=0;
    
            cout<<"Sum for "<<x<<" : ";
            for(int i=0; i<arr.size(); i++) {
                if((sum+arr[i])>x) {
                    cout<<sum<<"    ";
                    cnt++; sum=arr[i];
                } else {
                    sum+=arr[i];
                }
            }
    
            cnt++;
            return cnt;
        }
    
        int shipWithinDays(vector<int>& weights, int days) {
            long prefixSum = 0;
            for(int &x : weights) prefixSum += x;
    
            int low = max(weights), high=prefixSum, mid;
    
            while(low<=high) {
                mid = low+(high-low)/2;
    
                int x = daysReq(weights, mid);
                cout<<"Days : "<<x<<endl;
    
                // if(x==days) return mid;
                if(x<=days) high=mid-1;
                else low=mid+1;
            }
    
            return low;
        }
    };