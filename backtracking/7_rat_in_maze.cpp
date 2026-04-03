// Question Link - https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n=maze.size();
        vector<string> res;
        if(maze[0][0]==0 || maze[n-1][n-1]==0) return res;
        unordered_map<char, pair<int, int>> mp={
            {'R', {0, 1}}, 
            {'L', {0, -1}}, 
            {'U', {-1, 0}}, 
            {'D', {1, 0}}
        };
        
        string cur="";
        set<pair<int, int>> st;
        
        auto rec = [&](auto &&self, int i, int j, string &cur, set<pair<int, int>> &st) {
            if(i==n-1 && j==n-1) {
                res.push_back(cur); return;
            }
            if(i>=n || j>=n) return;
            
            for(auto it : mp) {
                char u=it.first; 
                pair<int, int> v=it.second;
                int x=v.first+i, y=v.second+j;
                if(x<0 || y<0 || x>=n || y>=n) continue;
                if(maze[x][y]==0) continue;
                if(st.count({x, y})) continue;
                st.insert({x, y}); cur+=u;
                self(self, x, y, cur, st);
                st.erase({x, y}); cur.pop_back();
            }
        };
        
        st.insert({0,0});
        rec(rec, 0, 0, cur, st);
        sort(res.begin(), res.end());
        return res;
    }
};