// Question Link - https://leetcode.com/problems/sum-of-subarray-minimums/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
Problem: Sum of minimums of all subarrays.
Observation (Pattern): Each element in the array is a minimum in several subarrays. So instead of finding all subarrays and their mins (which is brute), 
we ask: For a given element arr[i], in how many subarrays is arr[i] the minimum?
This is called contribution technique.
*/


/*
This falls under the category: “Contribution Technique + Monotonic Stack” for Range Frequency problems.
    Some classic examples in the same pattern family:
    Sum of subarray maximums
    Largest rectangle in histogram
    Next Greater Element
    Sum of all subarrays
    Subarrays where an element is max/min

    Leetcode 907 – Sum of Subarray Minimums
    Leetcode 2104 – Sum of Subarray Ranges
    Leetcode 84 – Largest Rectangle in Histogram
    Leetcode 503 – Next Greater Element II
*/


// BRUTE FORCE - TLE - 78/89
class Solution {
public:
    const int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(), sum=0, minn=INT_MAX; 

        for(int i=0; i<n; i++) {
            minn=INT_MAX;
            for(int j=i; j<n; j++) {
                minn=min(minn, arr[j]);
                sum= (sum+minn)%MOD;
                // cout<<"i: "<<arr[i]<<"  "<<sum<<endl;
            }
            // cout<<endl;
        }

        return sum;
    }
};

// OPTIMAL SOLUTION - FRIED MY BRAIN COMPLETELY!!!!
class Solution {
public:
    const int MOD = 1e9+7;
    vector<int> nse(vector<int> &arr) {
        int n=arr.size(); stack<int> st; vector<int> res(n);

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(st.empty()) res[i]=n;
            else res[i]=st.top();
            st.push(i);
        }

        return res;
    }

    vector<int> pse(vector<int> &arr) {
        int n=arr.size(); stack<int> st; vector<int> res(n);

        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(st.empty()) res[i]=-1;
            else res[i]=st.top();
            st.push(i);
        }

        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(), sum=0; 
        vector<int> nsea = nse(arr);
        vector<int> psea = pse(arr);

        for(int i=0; i<n; i++) {
            int rf = nsea[i]-i;
            int lf = i-psea[i];
            sum = (sum+((1LL*lf*rf%MOD)*arr[i])%MOD)%MOD;
        }

        return sum;
    }
};