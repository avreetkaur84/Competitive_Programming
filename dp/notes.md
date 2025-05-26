# When to Use Dynamic Programming (DP) vs Greedy

### *NOT ALL MAX/MIN PROBLEMS REQUIRE DP*


## ✅ When to Use Greedy

Greedy works when **local optimal choices** lead to a **global optimum**. That is, you can make the best decision at each step without revisiting previous steps.

### Characteristics:

* No dependency on previous states.
* No need to remember past decisions.
* No overlapping subproblems.

### Example:

**Problem:** Buy and sell stocks any number of times to maximize profit.

```cpp
int maxProfit(vector<int>& prices) {
    int profit = 0;
    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}
```

You just take every up-slope (buy low and sell high every time).

---

## ❌ When to Use DP

Use Dynamic Programming when the problem has:

* **Overlapping subproblems**.
* **Optimal substructure**.
* **Constraints on actions**, like limited transactions or cooldowns.

### Triggers for DP:

1. **At most *k* transactions**.
2. **Cooldown after selling**.
3. **Transaction fee on selling**.
4. **Can only hold one stock at a time**.
5. **Must skip days or make conditional decisions**.

### Example:

**Problem:** Max profit with at most 2 transactions.

```cpp
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if(n == 0) return 0;
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    
    for(int t = 1; t <= k; t++) {
        int maxDiff = -prices[0];
        for(int d = 1; d < n; d++) {
            dp[t][d] = max(dp[t][d-1], prices[d] + maxDiff);
            maxDiff = max(maxDiff, dp[t-1][d] - prices[d]);
        }
    }
    return dp[k][n-1];
}
```

Here, you track the best you can do with `t` transactions up to day `d`, considering the impact of previous decisions.

---

## Rule of Thumb

> **"If a greedy move now could hurt future decisions due to constraints, use DP."**

Ask:

* "Do I have restrictions on how often I can act?"
* "Do I need to remember the effect of previous moves?"
* "Can I be penalized for making a choice now vs later?"

If yes to any → **Use DP**.

---

## Summary

| Situation                          | Use    |
| ---------------------------------- | ------ |
| Unlimited actions                  | Greedy |
| Limited transactions               | DP     |
| Cooldown period required           | DP     |
| Transaction fees                   | DP     |
| Simple increase-based maximization | Greedy |

---

## Pro Tip:

Always **attempt greedy first** for max/min type problems. If it fails due to constraints, convert the greedy idea into a DP recurrence.