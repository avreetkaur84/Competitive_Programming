#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

// Question Link - https://cses.fi/problemset/task/1633
void dice_combination() {
    int n;  cin>>n;
    vector<int> dp(n+1, 0);
    dp[0]=1;

    for(int i=1; i<=n ; i++) {
        for(int j=1; j<=6; j++) {
            if(i-j<0) continue;
            dp[i] = (dp[i]+dp[i-j])%MOD;
        }
    }

    cout<<dp[n]<<"\n";
    // outArr(dp);
}

// Question Link - https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump
class Frong_jump {
  public:
    // 1 -> n
    // choice -> 1, 2
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        dp[1] = abs(height[1]-height[0]);
        
        for(int i=2; i<n; i++) {
            int one = dp[i-1]+abs(height[i]-height[i-1]);
            int two = dp[i-2]+abs(height[i]-height[i-2]);
            dp[i] = min(one, two);
        }
        
        return dp[n-1];
        
    }
};