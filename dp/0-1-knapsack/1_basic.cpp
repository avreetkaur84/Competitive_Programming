// Question Link - 

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

/*
 
*/

void outArr2d(vector<vector<int>> arr) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int memo(int idx, int cur_wt, vector<int> &wt, vector<int> &pf, vector<vector<int>> &dp) {
    // base
    if(cur_wt<=0 || idx<0) return 0;
    if(dp[idx][cur_wt]!=-1) return dp[idx][cur_wt];

    // choice
    int non_pick = memo(idx-1, cur_wt, wt, pf, dp);
    int pick = 0;
    if(cur_wt-wt[idx]>=0) {
        pick = pf[idx]+memo(idx-1, cur_wt-wt[idx], wt, pf, dp);
    }

    // result
    return dp[idx][cur_wt] = max(pick, non_pick);
}

int main() {
    vector<int> wt = {1, 4, 2, 3, 5};
    vector<int> pf = {1, 8 , 5, 7, 9};
    int max_wt = 5;
    vector<vector<int>> dp(wt.size(), vector<int> (max_wt+1, -1));
    cout<<memo(wt.size()-1, max_wt, wt, pf, dp)<<"\n";
    outArr2d(dp);
}