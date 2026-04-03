// Question Link: https://leetcode.com/problems/russian-doll-envelopes/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    // array sorted hai, next big hi hai, but dono ki gurantee nii hai
    // so, 1-d dp mein kaise karen, without prev
    // need to work for the intution for this solution

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [&](vector<int> &a, vector<int> &b) {
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });

        // width sorted, only care about height
        vector<int> tail; 
        for(auto it : envelopes) {
            if(tail.empty() || tail.back()<it[1]) tail.push_back(it[1]);
            else {
                int idx = lower_bound(tail.begin(), tail.end(), it[1])-tail.begin();
                tail[idx] = it[1];
            }
        }

        return tail.size();
        
    }
};