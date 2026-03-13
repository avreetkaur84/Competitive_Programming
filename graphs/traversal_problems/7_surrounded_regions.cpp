// Question Link - https://leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 8 march, 2026
class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        queue<vector<int>> q;
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        q.push({i, j}); board[i][j]='#';
        while(!q.empty()) {
            auto a = q.front(); q.pop();
            for(auto d : dir) {
                int x=a[0]+d[0], y=a[1]+d[1];
                if(x<0 || x>=n || y<0 || y>=m) continue;
                if(board[x][y]=='O') {
                    board[x][y]='#';
                    q.push({x, y});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        for(int i=0; i<n; i++) {
            if(board[i][0]=='O') bfs(i, 0, board);
        }
        for(int i=0; i<n; i++) {
            if(board[i][m-1]=='O') bfs(i, m-1, board);
        }
        for(int j=0; j<m; j++) {
            if(board[0][j]=='O') bfs(0, j, board);
        }
        for(int j=0; j<m; j++) {
            if(board[n-1][j]=='O') bfs(n-1, j, board);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
};

// 21 July, 2025
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