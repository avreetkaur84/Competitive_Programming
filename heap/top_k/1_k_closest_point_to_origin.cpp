// Question Link - https://leetcode.com/problems/k-closest-points-to-origin/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cal = [&](int x, int y) -> double {
            return sqrt(double(x*x) + (y*y));
        };

        // max heap
        priority_queue<vector<double>> pq;
        for(auto point : points) {
            double x = cal(point[0], point[1]);
            // cout<<x<<" "<<point[0]<<" "<<point[1]<<"\n";
            pq.push({x, double(point[0]), double(point[1])});
            if(pq.size()>k) pq.pop();
        }

        vector<vector<int>> res;
        while(!pq.empty()) {
            auto arr = pq.top(); pq.pop();
            res.push_back({int(arr[1]), int(arr[2])});
        }

        return res;
    }
};