// Question Link - https://leetcode.com/problems/number-of-provinces/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    void matrix_to_list(vector<vector<int>>& matrix, vector<vector<int>>& adj) {
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]==1) {
                    adj[i+1].push_back(j+1);
                }
            }
        }
    }

    void dfs(vector<vector<int>>& arr, vector<int> &vt, int node) {
        for(auto it : arr[node]) {
            if(!vt[it]) {
                vt[it]=1;
                dfs(arr, vt, it);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0, i=1, n=isConnected.size();
        cout<<n<<endl; 
        vector<vector<int>> adj(n+1);
        matrix_to_list(isConnected, adj);
        vector<int> vt(n+1, 0);
        vt[0]=1;
        
        for(int i=1; i<=n; i++) {
            if(!vt[i]) {
                vt[i]=1; cnt++;
                dfs(adj, vt, i); 
            }
        }

        return cnt;
        
    }
};