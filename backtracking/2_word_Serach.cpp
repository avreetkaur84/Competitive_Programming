// Question Link - https://leetcode.com/problems/word-search/description/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        backtrack:
            state - 
                1. Row and col as it wil be changing
                2. Visited 
                3. Idx till word is made
            choice -
                1. explore all 4 directions that surround cur cell
                2. if any cell is matched with letter of word that we need now next. then we will make our next call with this choice
                3. We will mark visited the state, then make call and then mark cell unvisited
                3. if no match, then continue without doing anything
            base case -
                1. if full word is made, then we will return true and things will end here
                2. if we reached end of row or col then we will return false to cancel the current branch
    */

    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size(), p=word.size();
        unordered_map<char, int> bmp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                bmp[board[i][j]]++;
            }
        }

        for(auto it : word) {
            if(!bmp.count(it)) return false;
            bmp[it]--;
            if(bmp[it]<=0) bmp.erase(it);
        }
        
        auto dfs = [&](auto &&self, int r, int c, int cur) -> bool {
            if(cur==p) return true;

            for(auto it : dir) {
                int i=r+it[0], j=c+it[1];
                if(i>=0 && i<n && j>=0 && j<m && board[i][j]!='#' && board[i][j]==word[cur]) {
                    board[i][j]='#';
                    bool res = self(self, i, j, cur+1);
                    if(res) return true;
                    board[i][j]=word[cur];
                }
            }

            return false;
        };

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]==word[0]) {
                    board[i][j]='#';
                    if(dfs(dfs, i, j, 1)) return true;
                    board[i][j]=word[0];
                }
            }
        }

        return false;
    }
};