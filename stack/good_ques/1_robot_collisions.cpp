// Question Link - https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2026-04-01

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int> idx(n);
        for(int i=0; i<n; i++) idx[i]=i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a]<positions[b];
        });

        // for(auto it : idx) cout<<it<<" ";

        stack<int> st; 
        for(int i=0; i<n; i++) {
            if(healths[idx[i]]==0) continue;
            else if(directions[idx[i]]=='R') st.push(idx[i]);
            while(directions[idx[i]]=='L' && !st.empty() && healths[idx[i]]!=0) {
                if(healths[idx[i]]<healths[st.top()]) {
                    healths[st.top()]--; healths[idx[i]]=0;
                } else if(healths[idx[i]]>healths[st.top()]) {
                    healths[st.top()]=0; healths[idx[i]]-=1;
                    st.pop();
                } else {
                    healths[st.top()]=0; healths[idx[i]]=0;
                    st.pop();
                }
            }
        }

        vector<int> res;
        for(int i=0; i<n; i++) {
            if(healths[i]!=0) res.push_back(healths[i]);
        }

        return res;
    }
};