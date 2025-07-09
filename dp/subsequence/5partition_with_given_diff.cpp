// Question Link - https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    // Another lesson - memoize with those index which are doing to give unique result for every time
    💥 And in DP, colliding states = lost paths = wrong answer

    Here, we have to find total number of partitions where subset sum difference is d.
    1. In this problem variable will be idx and d, as we need to tab d, target and current sum will decide d.
    2. Now the question is - what should be range of d? 

    but bro still can you explain me you rthought process behind taking that curr instead of T-2*curr, as one thing is that t-2*curr won't be unique, but I took that t-2*curr becuase I thought that T_2*curr, is derived from curr itself, so, it is controlling them and it is chaning everytime, as earlier what I had learnt was that, we take those as index of dp array, that are chnaging and here d was clearly chaning  everytime, so how curr???

    -While writing tabulation code, I am getting problem in which row to initialise with 1. I have to look at memoization base condition for this - but I am utterly confused, like - according to that condition only 1 cell is being initialised, which is incorrect.

    So, I learn that my maths eq - target-(2*j)>=d - is not simplified enough, and therefore makes it complex to convert the memo code into tabulation, as in tabulation we need prfect roadmap from which we can achieve results. 

    Another deep realization - my equation is not that smart, this eq - target = t+d/2 is insanely smart, because here we are directly counting the number of curr or sums possible that will have exact d differnece!!!! OMG movement. So, so have to not focus on the only main problem, but need to outsmart it, like we have to get that result, but achiveing it can be differnt. Like in competitive programing, we don't have to perform the exact operation but need to check what effect that operation will have on the result.
    THIS IS DEEP - Now everyhting makes sense.

    Finally tabulation fucking worked
*/

void printDP(vector<vector<int>> dp) {
    for(int i=0; i<dp.size(); i++) {
        for(int j=0; j<dp[0].size(); j++) {
            cout<<dp[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;
}

class Memoization {
  public:
    /*
        How can you even in your dreams give runtime error for the diff 0, as for every step, idx is being increased,
        so, there is no way, runtime error will come. 
        Dp really makes me question my brain!!! What I missed this time!!!
    */
  
    int helper(int idx, int curr, int target, int d, vector<int> &arr, vector<vector<int>> &dp) {
        if(idx>=arr.size()) return target-(2*curr) == d ? 1 : 0;
        
        if(dp[idx][curr]!=-1) return dp[idx][curr];
        
        int cnt = 0;
        if(target-(2*curr)>=d) {
            cnt += helper(idx+1, curr+arr[idx], target, d, arr, dp);
        }
        
        cnt += helper(idx+1, curr, target, d, arr, dp);
        
        return dp[idx][curr] = cnt;
        
    }
  
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int target = accumulate(arr.begin(), arr.end(), 0);
        
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        
        int cnt = helper(0, 0, target, d, arr, dp);
        printDP(dp);
    }
};

class Tabulation {
    public:
        int countPartitions(vector<int>& arr, int d) {
            int n = arr.size();
            int total = accumulate(arr.begin(), arr.end(), 0);
            
            if((total+d) & 1) return 0;
            int target = (total+d)/2;
            
            vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
            dp[0][0]=1;
            
            
            for(int i=1; i<=n; i++) {
                for(int j=0; j<=target; j++) {
                    int cnt = 0;
                    
                    cnt += dp[i-1][j];
                    
                    if(arr[i-1]<=j) {
                        cnt += dp[i-1][j-arr[i-1]];
                    }
                    
                    dp[i][j] = cnt;
                }
            }
            
            return dp[n][target];
            
        }
};

int main() {
    vector<int> arr = {1, 1, 1, 1};
    Tabulation obj;
    obj.countPartitions(arr, 0);
}