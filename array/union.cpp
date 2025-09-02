// Question Link - https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=union-of-two-sorted-arrays

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> res;
        int i=0, j=0;
        
        while(i<a.size() && j<b.size()) {
            if(a[i]<=b[j]) {
                if(res.size()>0 && res.back()==a[i]) {
                    i++; continue;
                }
                res.push_back(a[i]); i++;
            } else {
                if(res.size()>0 && res.back()==b[j]) {
                    j++; continue;
                }
                res.push_back(b[j]); j++;
            }
        }
        
        while (i<a.size()) {
            if(res.size()>0 && res.back()==a[i]) {
                    i++; continue;
                }
                res.push_back(a[i]); i++;
        }
        
        while (j<b.size()) {
            if(res.size()>0 && res.back()==b[j]) {
                    j++; continue;
                }
                res.push_back(b[j]); j++;
        }
        
        // cout<<"i: "<<i<<"   j: "<<j<<endl;
        
        return res;
    }
};