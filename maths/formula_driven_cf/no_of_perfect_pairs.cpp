// Question Link - https://leetcode.com/problems/number-of-perfect-pairs/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Lessons Learnt:
    1. If i<j condition is given in array, then its not always okay to avoid sorting specially when result is dependent of math equations and it is asked to simply count the stuff. In this case, if maths equation result becomes independent of i and j, then absolutely sorting can be done as I did it in this question.
    2. Two pointer technique is beautifully applied, I was going again and again into brute force which was giving me TLE, so this technique is life savior.
    3. Absolute properties
*/


// TAKEN HELP FROM EDITORIAL => BUT THIS SOLUTION IS WHOLE LESSON IN ITSELF. LEARNT A LOT WHILE SOLVING IT!!
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        long long n=nums.size(), cnt=0;
        vector<int> arr;
        for(int i=0; i<n; i++) arr.push_back(abs(nums[i]));
        sort(arr.begin(), arr.end());

        // condition -> arr[j]<=2*arr[i] -> eq induced from given conditions
        // arr[j] -> max and arr[i] -> min
        // count pairs that satisfies the condition -> i<j

        int j=0;
        for(int i=0; i<n; i++) {
            while(j<n && arr[j]<=2*arr[i]) {
                j++;
            }
            cnt += j-i-1;
        }
        
        return cnt;
    }
};

// BRUTE FORCE
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        long long pos=0, neg=0, n=nums.size(), cnt=0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                long long mn = min(abs(nums[i]-nums[j]), abs(nums[i]+nums[j]));
                long long mx = max(abs(nums[i]-nums[j]), abs(nums[i]+nums[j]));
                if(mn<=min(abs(nums[i]), abs(nums[j])) && mx>=max(abs(nums[i]), abs(nums[j]))) cnt++;
            }
        }

        return cnt;
    }
};