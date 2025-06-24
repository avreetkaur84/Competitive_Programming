// Question Link - https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    Wait, first how did I even got this spetember intution I mean, I can't remember now in 2025. As for my 2025 intution, I think its pretty obvious, I tried to apply the brute force solution of checking all the elemnts and then, comparing them to find the common prefix, pretty basic. 
    But, my main problem that I am noticing while revising is that I really don't take care of edge cases beforehand, I insert them into code while getting WA for that particular test case on leetcode. So, I need to learn and need to make the habit of checking the dge cases before submitting the code.
*/


// 12 september, 2024 Solution - 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int a=strs.size();
        string n=strs[0],m=strs[a-1],ans="";
        for(int i=0;i<n.size();i++){
            if(n[i]==m[i]){ans+=n[i];}
            else break;
        }
        return ans;
        
    }
};


// 22 June, 2025 Solution - beats 100% solutions on leetcode - and this was my first intution - solved in 15 minutes
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";

        string res = strs[0];
        for(int i=1; i<strs.size(); i++) {
            string cur = strs[i];
            if(cur.size()==0) return "";

            for(int j=0; j<cur.size(); j++) {
                if(res[j]!=cur[j]) {
                    res = res.substr(0, j); break;
                }
                if(j==cur.size()-1) res=cur;
            }
        }

        return res;
    }
};