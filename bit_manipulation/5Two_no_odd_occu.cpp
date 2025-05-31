// Question Link - https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;


class Solution {
  public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        vector<long long int> res;
        long long int b=0;
        
        for(long long int i=0; i<N; i++) {
            b^=Arr[i];
        }
        
        // right most bit turned on?
        long long int rbit = (b & (b-1)) ^ b;
        long long int g1=0; long long int g2=0;
        
        for(long long int i=0; i<N; i++) {
            if(((Arr[i]) & rbit)!=0) g1^=Arr[i];
            else g2^=Arr[i];
        }
        
        res.push_back(max(g1, g2));
        res.push_back(min(g1, g2));
        
        return res;
        
    }
};