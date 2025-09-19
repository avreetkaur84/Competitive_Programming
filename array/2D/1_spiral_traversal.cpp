// Question Link - https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        int n=mat.size(), m=mat[0].size();
        int top=0, down=n-1, left=0, right=m-1;
        vector<int> res;
        /*
            dp[top][i] : left to right
            dp[i][right]: top to bottom
            dp[down][i]: right to left
            dp[i][left]: bottom to top
        */
        
        while(top<=down && left<=right) {
            for(int i=left; i<=right; i++) res.push_back(mat[top][i]);
            top++;
            
            for(int i=top; i<=down; i++) res.push_back(mat[i][right]);
            right--;
            
            if(top<=down) {
                for(int i=right; i>=left; i--) res.push_back(mat[down][i]);
                down--;
            }
            
            if(left<=right) {
                for(int i=down; i>=top; i--) res.push_back(mat[i][left]);
                left++;
            }
            // cout<<top<<" "<<down<<" "<<left<<" "<<right<<"\n";
        }
        
        return res;
    }
};