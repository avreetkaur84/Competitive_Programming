// Question Link - https://leetcode.com/problems/combination-sum/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    void memo(int idx, int cur, vector<int> arr, vector<int>& candidates, vector<vector<int>>& res) {
        if(cur==0) {
            // cout<<"entered"<<endl;
            res.push_back(arr); return;
        }

        if(idx<=0 || cur<0) return;

        memo(idx-1, cur, arr, candidates, res); // non-pick
        if(candidates[idx-1]<=cur) {
            arr.push_back(candidates[idx-1]);
            memo(idx, cur-candidates[idx-1], arr, candidates, res);
            arr.pop_back();
        }

        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; int n=candidates.size();
        memo(n, target, {}, candidates, res);
        return res;
    }
};