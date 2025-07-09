// Question Link - https://leetcode.com/problems/assign-cookies/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    I solved this same question using greedy technique, now I have to solve this using dp.
    1. I have greed array and cookie size. I haev to count how many children will be satisfied - means return type will be int and we will store int result in dp array.
    2. Now, we can give each child at max 1 cookie, but my confusion is if we have given one cookie to a particular child, how will we track not to give that same cookie to another. 
    Okay, so I can solve this by making cookie my index, so, I will check all possiilities, if this particular cookie will be assigned to any child or not. If yes, that child will be marked as 1. And, I haev learnt that, I should not maek a separate variable count, but instead track teh count through dp array, but the issue is we can't give same cookie to the same child again, so how will we track this.
    3. So, what I haev learnt is to follow steps - 
        1. Base case -> 
            -if all cookies are checked || all greed factors are explored -> return 0
            -but here, we also haev to stop when particular cookie is assigned to a child
            -how do we make sure that one child gets one cookie, not more?
        2. Choice diagram -> 
    4. I think somehow I am doing wrong, dp explores possibilities but in systematic way, what I am thinking till now is like mapping all with all, which is wrong. So, maybe first I should sort both greed and cookie size array. But what will the impact of this operation and how will it make you achieve your goal? 
    5. Bro, I don't know, I mean can't come up with like solid plan. Wait, lets think again and forget sort because it won't have any deep impact on dp, but I don't know exact reason.
    THINK -
    1. At each step, what decision can I make and how does it affect the rest of the problem?
    2. define your DP state in terms of progress in each list. - 
        -dp[i][j] = max number of children that can be satisfied using first i children and first j cookies
        -i tracks how many children you've already handled.
        -j tracks how many cookies you've used.
    ------------------------------------------------------------------------------------------------------------------   
    | 🔍 Mistake                                          | 🔧 Fix                                                   |
    | --------------------------------------------------- | -------------------------------------------------------- |
    | Overcomplicating the matching logic                 | Define clear choices: give cookie or skip                |
    | Confused DP state                                   | Use `(childIdx, cookieIdx)` as state                     |
    | Ignoring power of sorting                           | Sort both arrays to avoid dumb checks                    |
    | Using backtracking intuition for a greedy-DP hybrid | DP here is structured traversal, not combination mapping |
    ------------------------------------------------------------------------------------------------------------------
    When matching two lists (e.g., people with resources), and each element can be used at most once, define DP with two pointers: one for each list.

    1. So, from above questions, I have realised that I should take greed as my index as greed is representing each child greed level. So, this will help us to check one child at once.
    2. Now, cookie will be another dimension. 
    3. Our choice diagram - we will check if a particular cookie can be assigned to child with that greed level. If it can be assigned, we will mark it as 1, or else skip it.
*/

/*
    TABULATION -
    1. Every cell in that grid is saying:
        “Hey, if I’ve handled the first i children and the first j cookies, how many children can I satisfy?”
    
*/

class Solution {
public:
    int helper(vector<int> &g, vector<int> &s, int i, int j, vector<vector<int>> &dp) {
        if(i==s.size() || g.size()==j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        dp[i][j]=0;
        if(g[i]<=s[j]) {
            dp[i][j] = 1+dp[i-1][j];
        } else {
            dp[i][j] = dp[i-1][j];
        }
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size(), n=s.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));

    }
};


// TABULATION

    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size(), n=s.size();
        if(n==0) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(g[i-1]<=s[j-1]) {
                    dp[i][j] = max(1+dp[i-1][j-1], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[m][n];
    }