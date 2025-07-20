// Question Link - https://leetcode.com/problems/flood-fill/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // vector<vector<int>> res = image;
        queue<vector<int>> q;
        int n=image.size(), m=image[0].size();
        int cng = image[sr][sc];
        image[sr][sc]=color;
        q.push({sr, sc});

        while(!q.empty()) {
            int i=q.front()[0], j=q.front()[1]; q.pop();

            if(i-1>=0 && image[i-1][j]==cng && image[i-1][j]!=color) {
                image[i-1][j]=color; q.push({i-1, j});
            }
            if(i+1<n && image[i+1][j]==cng && image[i+1][j]!=color) {
                image[i+1][j]=color; q.push({i+1, j});
            }
            if(j-1>=0 && image[i][j-1]==cng && image[i][j-1]!=color) {
                image[i][j-1]=color; q.push({i, j-1});
            }
            if(j+1<m && image[i][j+1]==cng && image[i][j+1]!=color) {
                image[i][j+1]=color; q.push({i, j+1});
            }
        }

        return image;
    }
};