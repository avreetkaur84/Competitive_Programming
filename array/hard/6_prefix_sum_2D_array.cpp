// Question Link - https://www.geeksforgeeks.org/problems/2d-submatrix-sum-queries/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> ps(n+1, vector<int> (m+1, 0));
        vector<int> res;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                ps[i][j]=mat[i-1][j-1]+ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];
            }
        }
        
        for(int i=0; i<queries.size(); i++) {
            // +1 -> due to one-based indexing
            int r1=queries[i][0]+1, c1=queries[i][1]+1, r2=queries[i][2]+1, c2=queries[i][3]+1;
            int ans = ps[r2][c2]-ps[r1-1][c2]-ps[r2][c1-1]+ps[r1-1][c1-1];
            res.push_back(ans);
        }
        
        return res;
    }
};
