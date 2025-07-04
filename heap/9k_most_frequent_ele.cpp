// Question Link - https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Solved this question in 10 minutes, my first intution was on point. Means somehow I am improving.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> hp;

        for(int i=0; i<nums.size(); i++) mp[nums[i]]++;

        for(const auto& i : mp) {
            hp.push({i.second, i.first});
            if(hp.size()>k) hp.pop();
        }

        vector<int> res;
        while(!hp.empty()) {
            pair<int, int> p = hp.top();
            res.push_back(p.second);
            hp.pop();
        }

        return res;
    }
};