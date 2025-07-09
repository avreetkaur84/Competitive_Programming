// Question Link - https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
    1. Sort the coins array in the desending order, as we want fewest number of coins to make teh value
    2. DP states -> 
        - coins will be idx, as we don't want same coin to be used again
        - value will be another dimension from 0 to value range.
        - We will use 2D dp array with the int return type
    3. Base case ->
        - If coins have finished - return 0
        - We have to return -1 if no coins can make up for the value - so will we include this in base case or ?
    4. Choice Diagram ->
        - Two cases - pick and non-pick
        - Pick : if cur value + cur coin is less than the target value
        - Non-Pick: if cur value exceeds target value
        - dp[i][j] = min(pick, non-pick) -> as we ahve to return the fewest coins
        - no, dude I think this will lead to some conflicts, as min can be zero too, or -1, so, maybe I need to think of some additional condition too.
    - Wait, I am missing the main point, if I am adding a coin, I need to add 1, to the number of coins that are going t amke up for the sum. So, need to make changes in above intutuion.  So, I will return +1 with the pick case.
    - So, I will haev my pick and non-pick case, ut the problem is then hpw will I keep the track of min coins, as I am not quite sure, if assigning min(pick, non_pick) to the dp[idx][curVal] will lead to problems, but my instinct id telling me it will. But, I am not sure which problems wil occur.
    - So, lets now go deeper with proper pen and paper.
    - I don't think choosing min will cause any problem, bcz here in memo, we will get the computed resut from the subProblems, so it will work alright. But, we can only consider comparing with those, where result is actually getting the target value. Wait, are you even making sense babygirl. 
    - Wait the biggest flow that I can see in my code is, like how the hell I am checking if particular array even makes up the camount as there I have not specified any such condition externally.
    -----------------------------------------------------------------------------------------------------------------------
    | ⚠️ Mistake                       | 📌 What's Wrong                       | 💡 What to Reflect                      |
    | -------------------------------- | ------------------------------------- | ---------------------------------------- |
    | Wrong base case                  | Not checking if `curVal == targetVal` | What *should* signal "I succeeded"?      |
    | Unbounded coins used as bounded  | You move to `idx+1` even on pick      | Shouldn't pick allow reusing same coin?  |
    | Unprotected `min()`              | -1s will mess up results              | Only compare valid paths                 |
    | Sorting coins                    | DP doesn't care                       | Greedy needs it, DP doesn’t              |
    ----------------------------------------------------------------------------------------------------------------------

    ** Biggest Blunder - I ignored the statement that we have infinite supply of each coin!! This changes the whole question intution

    -------------------------------------------------------------------------------------------------------------------------
    ## NEW BEGINING
    1. DP State ->
        - Coins -> We have infinite supply of each coin, so we will check how much max sum we can produce with each coin. 
        - CurVal -> Second dimension
    2. Raw intution : 
        - Suppose first coin is 5 and target is 11 -> so we will see what values we can produce with this coin, so, we will mark dp[0][5]=1, and dp[0][10]=2, as we will be able to produce 10 with 2 '5' coins, In this manner we will go forward.
        - Now, suppose next coin is 2 -> we will mark teh sum that can be produced with 2 coins and with 5 combined. Now, '2' coin can produce 10 with 5 coins but '5' coin can produce 10 with '2' coins, so we will keep the '2' coin number at dp[x][10]. 
        - But, I can figure out tabulation with tis, but can't visualize the recursion on apper for this, I am consufed how recursive tree will be made for multile choices of same coin.
        - Therefore, I will first write the tabulation code.

*/

class Solution {
public:
    // int helper(int idx, int curVal, int targetVal, vector<int> &arr, vector<vector<int>> &dp) {
    //     if(idx>=arr.size()) return 0;
    //     if(dp[idx][curVal] != -1) return dp[idx][curVal];

        
    // }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), [](int a, int b){
            return a>b;
        });

        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                // problem in figuring out this part logic, it seems complex -> bro my mind is crying now!!! Bur, just few more steps!!
                // bro I am failing, in generating all the combinations of sum with the val, when dp[i-1][j]>0, like if 5 was previous coin and two is next, then we can generate 5, 7, 9, 11 -> these all from them. So, this will require further loop or something, and this is killing me!!!!!!
                if(dp[i-1][j]>0 && j+coins[i-1]<=amount) {
                    dp[i][j+coins[i-1]] = dp[i-1][j]+1;
                }
                if(j%coins[i-1]==0) {
                    dp[i][j] = min(j/coins[i-1], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
};