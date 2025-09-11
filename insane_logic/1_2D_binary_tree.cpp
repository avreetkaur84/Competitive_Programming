// Question Link : 
#include <bits/stdc++.h>
using namespace std;


// The matrix is assumed to be a binary serach tree and then this simple logic is created
// editorial link: https://leetcode.com/problems/search-a-2d-matrix/solutions/1895837/c-binary-search-tree-explained-with-img/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(), cols=matrix[0].size();
        int row=0, col=cols-1;

        while(row<rows && col>-1) {
            int num = matrix[row][col];
            if(num==target) return true;
            else if(num<target) row++;
            else col--;
        }

        return false;
    }
};

class Solution {
public:
    int up_bn(vector<vector<int>>& matrix, int target, int idx, int r) {
        int low=0, high=(r==1)?matrix.size()-1:matrix[idx].size()-1, mid;
        while(low<=high) {
            mid = low+(high-low)/2;

            // if(matrix[mid][idx]==target) return mid;
            if(r==1) {
                if(matrix[mid][idx]<=target) low=mid+1;
                else high=mid-1;
            } else {
                if(matrix[idx][mid]<=target) low=mid+1;
                else high=mid-1;
            }
        }
        return low;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first check in which row element is present.
        // row mein upper bound 
        int n=matrix.size(), m=matrix[0].size();
        if(matrix[0][0]>target || matrix[n-1][m-1]<target) return false;

        int i = up_bn(matrix, target, 0, 1);
        i = (i>0) ? i-1 : 0; 
        if(matrix[i][0]==target) return true;
        // cout<<i<<"\n"; 

        int x = up_bn(matrix, target, i, 0);
        // cout<<x<<"\n";
        x = (x>0) ? x-1 : 0; 
        if(matrix[i][x]==target) return true;
        return false;
    }
};