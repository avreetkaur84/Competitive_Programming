// Question Link - https://www.geeksforgeeks.org/problems/better-string/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=better-string

// Need to solve this using dp too. (PENDING!!)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      void sequenceGen(string ip, set<string> &res, string op, int &cnt) {
          if(ip.length()==0 ) {
              if(op.size()>0) res.insert(op);
              return;
          }
          
          string op1 = op;     //non-pick
          string op2 = op+ip[0];   //pick
          
          if(!ip.empty()) ip.erase(ip.begin());
          
          sequenceGen(ip, res, op1, cnt);
          sequenceGen(ip, res, op2, cnt);
          
          cnt = res.size();
      }
    
      string betterString(string str1, string str2) {
          int cnt1=0, cnt2=0;
          
          set<string> res1;
          set<string> res2;
          string op="";
          
          sequenceGen(str1, res1, op, cnt1);
          sequenceGen(str2, res2, op, cnt2);
          
          // cout<<cnt1<<"   "<<cnt2<<endl;
          
          if(cnt1>=cnt2)   return str1;
          else return str2;
          
      }
      
  };