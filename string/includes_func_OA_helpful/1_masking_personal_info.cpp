// Question Link: https://leetcode.com/problems/masking-personal-information/description/?envType=problem-list-v2&envId=wwa0cvsi

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maskPII(string s) {
        string res="";

        if(s.find('@')!=string::npos) {
            // email
            string name="", domain="";
            bool flag=false;
            for(int i=0; i<s.size(); i++) {
                if(s[i]=='@') {
                    flag=true; continue;
                }
                s[i]=tolower(s[i]);
                if(!flag) name+=s[i];
                else domain+=s[i];
            }
            string y(1, name[0]), z(1, name[name.size()-1]);
            res = y + "*****" + z;
            res = res+'@'+domain;
        } else {
            // phone
            set<char> st = {'0','1','2','3','4','5','6','7','8','9'};
            string temp = "";
            for(int i=0; i<s.size(); i++) {
                if(st.count(s[i])) temp+=s[i];
            }
            s=temp;
            // cout<<s;
            int x = s.size();
            string local = "";
            int i=x-1;
            while(local.size()<4) {
                local=s[i]+local;
                i--;
            }

            int code_size = x-10;
            string code = s.substr(0, code_size);
            if(code.size()==0) {
                res = "***-***-"+local;
            } else if(code.size()==1) {
                res = "+*-***-***-"+local;
            } else if(code.size()==2) {
                res = "+**-***-***-"+local;
            } else if(code.size()==3) {
                res = "+***-***-***-"+local;
            }
        }

        return res;
    }
};