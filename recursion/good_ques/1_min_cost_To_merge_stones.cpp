// Question Link - https://leetcode.com/problems/minimum-cost-to-merge-stones/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TLE

    int res=INT_MAX;
    int rec(int idx, vector<int> arr, int k) {
        // base case
        if(arr.size()==1) return 0;        
        if(arr.size()<k) return INT_MAX;

        int cost=INT_MAX;
        // choices
        for(int i=idx; i<=arr.size()-k; i++) {
            vector<int> temp;
            int sum = accumulate(arr.begin()+i, arr.begin()+i+k, 0);
            for(int j=0; j<i; j++) temp.push_back(arr[j]);
            temp.push_back(sum);
            for(int j=i+k; j<arr.size(); j++) temp.push_back(arr[j]);
            int x = rec(0, temp, k);
            if(x!=INT_MAX) cost = min(cost, x+sum);
        }

        return cost;
    }

    int mergeStones(vector<int>& stones, int k) {
        int x = rec(0, stones, k);
        return (x==INT_MAX)?-1:x;
    }
};