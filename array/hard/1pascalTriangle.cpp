// Question Link - https://leetcode.com/problems/pascals-triangle/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0) return res;
        res.push_back({1});
        if(numRows==1) return res;

        for(int i=1; i<numRows; i++) {
            int j=0, m=res[i-1].size(); vector<int> arr;
            arr.push_back(1);
            for(int j=0; j<m-1; j++) {
                arr.push_back(res[i-1][j]+res[i-1][j+1]);
            }
            arr.push_back(1);
            res.push_back(arr);
        }

        return res;
    }
};