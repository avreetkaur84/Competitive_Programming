// Question Link - https://leetcode.com/problems/n-queens/description/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Trust me, if you want to make your life hell or you feel like you are a genius, start doing coding!!

class Solution {
public:
    /*
        - so, I can try to check for all positions, like start from (0,0) and place queen at next available pos, if this doesn't work, then at next available pos, so, yaha par recursion kam ayega na, as agar choice galat hua then you can backtrack from that choice only, no need to do everything from scratch. Like maybe last 2 postions are avialble and queen is not placed at second last but will be placed at last, so backtrack second last and check for last. 
        - Har position ke liye next positions ke liye recursion call karenge till base case.
        - I am not sure how I should manage the states of the varaibles, like I can't update them globally, so how. Mark array basically.
    */

    bool isValid(vector<string> &board, int r, int c) {
        int n=board.size();
        if(board[r][c]=='Q') return false;
        for(int i=0; i<n; i++) if(board[r][i]=='Q') return false;
        for(int i=0; i<n; i++) if(board[i][c]=='Q') return false;
        // diagonals up-left
        int i=r, j=c; i--; j--;
        while(i>-1 && j>-1) {
            if(board[i][j]=='Q') return false; i--; j--;
        }
        // up-right
        i=r; j=c; i--; j++;
        while(i>-1 && j<n) {
            if(board[i][j]=='Q') return false; i--; j++;
        }
        return true;
    }
    
    void rec(int i, int &n, vector<string> &board, vector<vector<string>> &res) {
        // base case
        if(i>=n) {
            res.push_back(board);
            return;
        }

        // choice dia
        for(int j=0; j<n; j++) {
            if(isValid(board, i, j)) {
                board[i][j]='Q';
                rec(i+1, n, board, res);
                board[i][j]='.';
            } 
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        rec(0, n, board, res);        
        return res;
    }
};