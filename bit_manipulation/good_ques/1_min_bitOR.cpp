// Question Link - https://leetcode.com/problems/minimum-bitwise-or-from-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        msb to lsb -> check for forbidden bits
    */
    
    int minimumOR(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int forbidden_bits=0, ans=0;

        auto check = [&](int forbidden) -> bool {
            for(int i=0; i<n; i++) {
                bool col=false;
                for(int j=0; j<m; j++) {
                    if((grid[i][j] & forbidden)==0) {
                        col=true;
                    }
                }
                if(!col) return false;
            }
            return true;
        };
        
        for(int i=30; i>=0; i--) {
            int cur_bit = 1<<i;
            int temp = forbidden_bits | cur_bit;

            // if check is false, it means cur_bit needs to be turn on
            if(!check(temp)) ans |= cur_bit;
            else forbidden_bits |= cur_bit;
        }

        return ans;
    }
};