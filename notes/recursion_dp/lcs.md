# 📜 Longest Common Subsequence (LCS) 

## 🔍 What is LCS?

Given two strings `X` and `Y`, the **Longest Common Subsequence** is the longest sequence that appears **in both strings in the same order**, but **not necessarily contiguous**.

**Example:**
```
X = "abcde"
Y = "ace"
LCS = "ace"
Length = 3
```

---

## 🧠 Recursive Approach (Base of DP)

### Function Signature:
```cpp
int lcs(string x, string y, int m, int n);
```

### Logic:
```cpp
if x[m-1] == y[n-1]
    return 1 + lcs(x, y, m-1, n-1);
else
    return max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
```

### Base Case:
```cpp
if(m == 0 || n == 0) return 0;
```

---

## ✅ Why `m-1` and `n-1` in Recursion?

- Because `m` and `n` represent **lengths**, not indices.
- Strings are **0-indexed**, so `x[m-1]` is the **last character**.

---

## ✅ Why Not Use `cnt` in Recursive LCS?

### ❌ Your Original Idea:
```cpp
int cnt = 0;
if(x[m] == y[n]) cnt++;
```

### ❌ Problems:
1. **You compared wrong characters** (`x[m]` is out of bounds).
2. **You passed `cnt` by reference** — so all branches were modifying the same variable → **Incorrect total**.
3. **Recursion doesn't return anything** when using `cnt`, so you lose control over **accumulating values correctly**.

### ✅ Correct Way:
Use **return values**, and let recursion stack handle the accumulation:
```cpp
return 1 + lcs(x, y, m-1, n-1);
```

---

## ✅ Why `max(...)` in LCS?

- At each mismatch, you have two choices:
  - Skip from string `x`: `lcs(x, y, m-1, n)`
  - Skip from string `y`: `lcs(x, y, m, n-1)`
- You need the **best** (longest) subsequence from these → hence use `max(...)`.

Even though all paths are explored in recursion, `max` helps you **build the correct answer** step-by-step.

---

# 📌 Your Common Mistakes and Misunderstandings

| Mistake / Confusion                            | Clarification                                                                 |
|------------------------------------------------|------------------------------------------------------------------------------|
| Used `x[m]` and `y[n]`                         | Out-of-bounds! Always use `x[m-1]`, `y[n-1]` if `m` and `n` are lengths.     |
| Used `cnt` by reference in recursion           | Wrong when recursion explores multiple paths. Causes shared state bugs.     |
| Didn’t understand where accumulation happens   | It’s through **return values**. Recursion stack handles the buildup.        |
| Asked: “What’s the use of max if all paths are traversed?” | `max(...)` helps choose the **best** subsequence. When memoized, avoids recomputation. |
| Thought return values vanish after call        | They bubble up through the call stack, forming the correct result at the top.|

---

## ✅ LCS Template to Remember (Recursive):

```cpp
int lcs(string &x, string &y, int m, int n) {
    if(m == 0 || n == 0) return 0;

    if(x[m-1] == y[n-1])
        return 1 + lcs(x, y, m-1, n-1);
    else
        return max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
}
```

---

## 📘 Suggested Practice Flow

1. ✅ Write pure recursion for LCS
2. ♻️ Convert it to Memoization with `dp[m][n]`
3. 📆 Convert it to Bottom-Up (Tabulation)
4. 🧠 Do space optimization (1D arrays) if you want to master DP

---

