// Question Link - https://leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    // what I turn all the 0's into X, except the border ones? But, this question won't be this simple.
    void bfs(set<pair<int, int>> &st, vector<vector<char>>& board, pair<int, int> cur) {
        queue<pair<int, int>> q;
        q.push(cur); st.erase(cur);
        int n=board.size(), m=board[0].size();

        while(!q.empty()) {
            pair<int, int> p=q.front(); q.pop(); 

            if(p.first+1<n && board[p.first+1][p.second]=='O' && st.find({p.first+1, p.second})!=st.end()) {
                st.erase({p.first+1, p.second});
                q.push({p.first+1, p.second});
            }
            if(p.first-1>=0 && board[p.first-1][p.second]=='O' && st.find({p.first-1, p.second})!=st.end()) {
                st.erase({p.first-1, p.second});
                q.push({p.first-1, p.second});
            }
            if(p.second+1<m && board[p.first][p.second+1]=='O' && st.find({p.first, p.second+1})!=st.end()) {
                st.erase({p.first, p.second+1});
                q.push({p.first, p.second+1});
            }
            if(p.second-1>=0 && board[p.first][p.second-1]=='O' && st.find({p.first, p.second-1})!=st.end()) {
                st.erase({p.first, p.second-1});
                q.push({p.first, p.second-1});
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        set<pair<int, int>> st; // store the idx of 0's
        if(n==1 || m==1) return;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]=='O') st.insert({i, j});
            }
        }

        // check all the edge rows and columns
        for(int j=0; j<m; j++) if(board[0][j]=='O') bfs(st, board, {0, j});
        for(int i=0; i<n; i++) if(board[i][0]=='O') bfs(st, board, {i, 0});
        for(int j=0; j<m; j++) if(board[n-1][j]=='O') bfs(st, board, {n-1, j});
        for(int i=0; i<n; i++) if(board[i][m-1]=='O') bfs(st, board, {i, m-1});

        for(auto p : st) {
            board[p.first][p.second]='X';
        }
        
    }
};