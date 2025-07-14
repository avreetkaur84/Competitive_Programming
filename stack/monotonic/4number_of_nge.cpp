// Question Link - https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
  public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        vector<int> res(n);
        
        for(int i=0; i<n; i++) {
            int cnt=0;
            for(int j=i+1; j<n; j++) {
                if(arr[j]>arr[i]) cnt++;
            }
            res[i]=cnt;
        }
        
        vector<int> out;
        for(int i=0; i<indices.size(); i++) {
            out.push_back(res[indices[i]]);
        }
        
        return out;
    }
};

