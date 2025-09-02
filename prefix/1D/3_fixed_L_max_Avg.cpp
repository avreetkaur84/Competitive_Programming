// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e5;

/*
    Max Average ≥ L
Given an array A of n integers (may be negative) and an integer L (1 ≤ L ≤ n), find the maximum possible average of any subarray whose length is at least L. Output the value with 1e-5 precision.
Constraints: n ≤ 2e5, |A[i]| ≤ 1e9.
*/

/*
    Miss read teh question earlier!!!!!!! 
*/


// length at most L.
long long maxSubarraySumAtMostL(vector<int>& nums, int L) {
    int n = nums.size();
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + nums[i];

    long long ans = LLONG_MIN;
    deque<int> dq; // will store indices of prefix sums (monotonic increasing)

    dq.push_back(0); // prefix[0] = 0

    for (int r = 1; r <= n; r++) {
        // Remove indices out of window (older than L)
        while (!dq.empty() && dq.front() < r - L) {
            dq.pop_front();
        }

        // Best candidate = pref[r] - smallest prefix in window
        ans = max(ans, pref[r] - pref[dq.front()]);

        // Maintain deque monotonic increasing (so front is minimum prefix)
        while (!dq.empty() && pref[dq.back()] >= pref[r]) {
            dq.pop_back();
        }
        dq.push_back(r);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 12, -5, -6, 50, 3};
    int L = 3;
    cout << "At most L: " << maxSubarraySumAtMostL(arr, L) << "\n";
    return 0;
}


// greater than equal L -> length
long long maxSubarraySumAtLeastL(vector<int>& nums, int L) {
    int n = nums.size();
    vector<long long> pf(n + 1, 0);

    for (int i = 0; i < n; i++) {
        pf[i + 1] = pf[i] + nums[i];  // no modulo, keep exact prefix
    }

    long long ans = LLONG_MIN;
    long long minPref = 0;  // minimum prefix sum seen so far
    // but we only start checking when subarray length >= L

    for (int i = L; i <= n; i++) {
        // before using pref[i], update minPref to include pref[i-L]
        minPref = min(minPref, pf[i - L]);
        ans = max(ans, pf[i] - minPref);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 12, -5, -6, 50, 3};
    int L = 3;
    cout << maxSubarraySumAtLeastL(arr, L) << "\n";
    return 0;
}


int max_k_SubArray(vector<int>& nums, int L) {
        int sum=0; int maxx=INT_MIN, n=nums.size(), len;
        vector<int> pf(n+1, 0);
        for(int i=0; i<n; i++) {
            pf[i+1] = (pf[i]+nums[i])%MOD;
        }

        int minn=INT_MAX, j=0;
        for(int i=1; i<=n; i++) {
            if(i-j+1>L) {
                j++; minn=pf[j];
            }
            
            if(minn>pf[i]) {
                minn=pf[i]; j=i;
            }
            maxx=max(maxx, pf[i]-minn);
            cout<<"maxx: "<<maxx<<" minn: "<<minn<<"\n";
        }

        while(j<=n) {
            if(minn>pf[j]) {
                minn=pf[j];
            }
            maxx=max(maxx, pf[n]-minn);
            cout<<"maxx: "<<maxx<<" minn: "<<minn<<"\n";
            j++;
        }

        return maxx;
}

int main() {
    vector<int> arr = {1, 12, -5, -6, 50, 3};
    int res = max_k_SubArray(arr, 3);
    cout<<res<<"\n";
}