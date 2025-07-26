// Question Link - https://leetcode.com/problems/01-matrix/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
### What I did wrong:
1. Started BFS from all 1s instead of 0s → led to TLE.
2. Pushed every neighbor into queue without checking if it’s already visited or useful.
3. Used `else if` for neighbor traversal, blocking multiple directions.
4. Revisited same cells multiple times, bloating the queue.

### Final Correct Intuition:
- This is a **multi-source BFS** problem.
- All `0`s are **sources**, all `1`s are **targets**.
- BFS expands from 0s, assigning shortest distance to any reachable 1.
- Only push a neighbor if:
  - It's a `1`
  - It's unvisited
- Track visited with a matrix.
- BFS naturally guarantees shortest distance.

**Pattern learned:**  
Multi-source BFS → Push all sources → Expand with shortest-first guarantee → Set answer at first visit.
*/


// On second try - doing this question felt like cramming, as I have made quite number of mistakes while solving
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size(), cnt=0;
        vector<vector<int>> res = mat; vector<vector<int>> vt(m, vector<int> (n, 0));
        queue<vector<int>> q;  //{i, j, dis}

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j]==0) {
                    q.push({i, j, 0}); vt[i][j]=1;
                }
                else cnt++;
            }
        }

        while(!q.empty() && cnt>0) {
            vector<int> arr=q.front(); q.pop();
            int i=arr[0], j=arr[1];

            if(i+1<m && vt[i+1][j]==0 && mat[i+1][j]==1) {
                cnt--; vt[i+1][j]=1;
                res[i+1][j]=arr[2]+1;
                q.push({i+1, j, arr[2]+1});
            }
            if(i-1>=0 && vt[i-1][j]==0 && mat[i-1][j]==1) {
                cnt--; vt[i-1][j]=1;
                res[i-1][j]=arr[2]+1;
                q.push({i-1, j, arr[2]+1});
            }
            if(j+1<n && vt[i][j+1]==0 && mat[i][j+1]==1) {
                cnt--; vt[i][j+1]=1;
                res[i][j+1]=arr[2]+1;
                q.push({i, j+1, arr[2]+1});
            }
            if(j-1>=0 && vt[i][j-1]==0 && mat[i][j-1]==1) {
                cnt--; vt[i][j-1]=1;
                res[i][j-1]=arr[2]+1;
                q.push({i, j-1, arr[2]+1});
            }
        }

        return res;
    }
};

// first try - got TLE
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> res = mat;
        queue<vector<int>> q;  //{i, j, pi, pj, dis}

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j]==1) {
                    q.push({i, j, i, j, 0});
                }
            }
        }

        while(!q.empty()) {
            vector<int> arr=q.front(); q.pop();
            int i=arr[0], j=arr[1];

            if(i+1<m && mat[i+1][j]==0) {
                res[arr[2]][arr[3]]=arr[4]+1; continue;
            }
            else if(i-1>=0 && mat[i-1][j]==0) {
                res[arr[2]][arr[3]]=arr[4]+1; continue;
            }
            else if(j+1<n && mat[i][j+1]==0) {
                res[arr[2]][arr[3]]=arr[4]+1; continue;
            }
            else if(j-1>=0 && mat[i][j-1]==0) {
                res[arr[2]][arr[3]]=arr[4]+1; continue;
            }

            if(i+1<m) q.push({i+1, j, arr[2], arr[3], arr[4]+1});
            if(i-1>=0) q.push({i-1, j, arr[2], arr[3], arr[4]+1});
            if(j+1<n) q.push({i, j+1, arr[2], arr[3], arr[4]+1});
            if(j-1>=0) q.push({i, j-1, arr[2], arr[3], arr[4]+1});
        }

        return res;
    }
};