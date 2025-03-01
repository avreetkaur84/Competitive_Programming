// Question Link - https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
    public:
      void generateSeq(vector<int> ip, int k, vector<int> op, int &cnt) {
          if(ip.size()==0) {
              int sum = accumulate(op.begin(), op.end(), 0);
              if(sum==k)  cnt++;
              return;
          }
          
          vector<int> op1 = op;
          op.push_back(ip[0]);
          vector<int> op2 = op;
          
          if(!ip.empty()) ip.erase(ip.begin());
          generateSeq(ip, k, op1, cnt);
          generateSeq(ip, k, op2, cnt);
      }
    
      int perfectSum(vector<int>& arr, int target) {
          int cnt=0;
          vector<int> op;
          
          generateSeq(arr, target, op, cnt);
          return cnt;
      }
  };