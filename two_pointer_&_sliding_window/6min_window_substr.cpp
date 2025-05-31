// Question Link - https://leetcode.com/problems/minimum-window-substring/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// This problem just fucked up my brain

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        if(s==t) return s;
        unordered_map<char, int> mp;

        for(int i=0; i<t.size(); i++) mp[t[i]]++;
        int required=mp.size(), cnt=0; 
        int startIdx=-1, minn=INT_MAX;

        int i=0, j=0, n=s.size();
        while(j<n) {
            mp[s[j]]--;
            if(mp[s[j]]==0) cnt++;

            while(cnt==required)  {
                if(minn>j-i+1) {
                    minn=j-i+1; startIdx=i;
                }

                mp[s[i]]++;
                if(mp[s[i]]>0) cnt--;
                i++;
            }

            // cout<<"cnt: "<<cnt<<"   required: "<<required<<endl;

            j++;
        }

        if(startIdx!=-1)    return s.substr(startIdx, minn);
        else return "";
    }
};