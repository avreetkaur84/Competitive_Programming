// Question Link - https://leetcode.com/problems/task-scheduler/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();

        vector<int> fq(26);
        // freq count
        for(int i=0; i<tasks.size(); i++) {
            fq[tasks[i]-'A']++;
        }

        // pq push
        priority_queue<int> pq;
        for(int i=0; i<fq.size(); i++) {
            if(fq[i]>0) pq.push(fq[i]);
        }

        int res=0;
        while(pq.top()!=1) {
            vector<int> ele;
            int j=0;
            while(!pq.empty() && j<=n) {
                ele.push_back(pq.top()); pq.pop(); j++;
            }
            res+=n+1;
            for(int i=0; i<ele.size(); i++) {
                if(ele[i]-1>0) pq.push(ele[i]-1);
            }
        }

        res+=pq.size();
        return res;
    }
};