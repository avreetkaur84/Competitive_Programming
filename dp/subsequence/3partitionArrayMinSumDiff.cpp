// Question Link - 

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    long long summ=0;
    for(int i=0; i<n; i++) {
        summ=summ+nums[i];
    }

    cout<<"Summ: "<<summ<<endl;
    // summ/=2;
    vector<vector<bool>> dp(n, vector<bool> (summ+1, false));

    for(int i=0; i<n; i++) dp[i][0]=true;
    if(nums[0]<=summ)   dp[0][nums[0]]=true;

    for(int i=1; i<n; i++) {
        for(int tar=1; tar<=summ; tar++) {
            bool nonPick = dp[i-1][tar];
            bool pick=false;
            if(nums[i]<=tar) {
                pick=dp[i-1][tar-nums[i]];
            }

            dp[i][tar]=pick||nonPick;
        }
    }

    int minn=1e9;
    for(int j=0; j<summ; j++) {
        if(dp[n-1][j]==true) {
            int term = summ-j;
            minn = min(minn, abs(term-j));
        }
    }

    return minn;
}