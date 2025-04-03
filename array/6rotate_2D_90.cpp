// Question Link - https://leetcode.com/problems/rotate-image/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
    public:
        void print(vector<vector<int>>& matrix) {
            for(int i=0; i<matrix.size(); i++) {
                for(int j=0; j<ceil(matrix[0].size()); j++) {
                    // swap(matrix[i][j], matrix[j][i]);
                    cout<<matrix[i][j]<<"   ";
                }
                cout<<endl;
            }
        }
    
        void transpose(vector<vector<int>>& matrix) {
            for(int i=0; i<matrix.size(); i++) {
                for(int j=i; j<matrix[0].size(); j++) {
                    swap(matrix[i][j], matrix[j][i]);
                    // cout<<i<<j<<"->"<<j<<i<<"   ";
                }
                // cout<<endl;
            }
        }
    
        void rotate(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            
            // SOLUTION 1
            // vector<vector<int>> arr = matrix;
            // m--; n--;
            // for(int i=0; i<=m; i++) {
            //     for(int j=0; j<=n; j++) {
            //         matrix[j][m-i] = arr[i][j];
                    // cout<<i<<j<<"->"<<j<<m-i<<" ";
            //     }
            //     cout<<endl;
            // }
    
            // SOLUTION - 2
            // 1. Transpose -> 2. Reverse columns
            transpose(matrix);
            // print(matrix);
            for(int i=0; i<m; i++) {
                reverse(matrix[i].begin(), matrix[i].end());
            }
        }
    };