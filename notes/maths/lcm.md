# 📘 Least Common Multiple (LCM) - Competitive Programming Notes

## 🧠 What is LCM?

- **LCM (Least Common Multiple)** of two integers `a` and `b` is the smallest positive number divisible by both `a` and `b`.

$$
\text{LCM}(a, b) = \frac{a \cdot b}{\text{GCD}(a, b)}
$$

---

## ⚙️ Key Properties

### ✅ Commutative
$$
\text{LCM}(a, b) = \text{LCM}(b, a)
$$

### ✅ Associative
$$
\text{LCM}(a, b, c) = \text{LCM}(\text{LCM}(a, b), c)
$$

> 💡 Useful when reducing an array:  
```cpp
int lcm = arr[0];
for (int i = 1; i < n; i++) {
    lcm = (lcm * arr[i]) / gcd(lcm, arr[i]);
}
````

### ✅ LCM-GCD Identity

$$
\text{LCM}(a, b) \cdot \text{GCD}(a, b) = a \cdot b
$$

* Very useful in problems where you're given LCM and GCD and asked to reconstruct or analyze the numbers.

---

## ⚡ Overflow Handling

> ❗ `a * b` can exceed `long long` range!

**Correct usage (safe):**

```cpp
long long lcm = (a / gcd(a, b)) * b;
```

Avoid:

```cpp
long long lcm = (a * b) / gcd(a, b);  // ❌ might overflow
```

Use `__int128` or BigInteger for large inputs.

---

## 🧩 Special Cases

| Case                   | Result                          |
| ---------------------- | ------------------------------- |
| LCM(a, 0) or LCM(0, a) | `0`                             |
| LCM(0, 0)              | `undefined` (handle separately) |
| LCM of 1 and anything  | That number                     |


## ✨ LCM is Minimized, When GCS is Maximized ✨

---

## 📚 Applications in Competitive Programming

| Problem Type                | Use of LCM                         |
| --------------------------- | ---------------------------------- |
| Scheduling tasks            | Find when multiple cycles sync     |
| CRT with non-coprime moduli | Combine using LCM                  |
| Array processing            | LCM of subarrays or entire array   |
| Constructive problems       | Build arrays with given LCM        |
| Cyclic patterns             | Minimum steps till pattern repeats |

---

## 🛠️ LCM in Arrays

### Compute LCM of entire array:

```cpp
long long arrayLCM(vector<int>& arr) {
    long long res = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        res = (res / gcd(res, arr[i])) * arr[i];
        if (res > 1e18) break; // Overflow guard
    }
    return res;
}
```

---

## 🚫 Modular Arithmetic Warning

LCM does **not** behave cleanly under mod:

* No identity like: `LCM(a, b) % m = ???`
* Avoid direct modular operations on LCM unless constraints are tight and under control

---

## 🔢 LCM of Primes

If all numbers are **distinct primes**:

$$
\text{LCM}(p_1, p_2, ..., p_k) = p_1 \cdot p_2 \cdot \dots \cdot p_k
$$

Used in prime generation, multiplicative number theory, etc.

---

## 🧠 Pattern Recognition

### Useful Relationship:

$$
\text{LCM}(a, b) = \frac{a \cdot b}{\text{GCD}(a, b)} \Rightarrow \text{GCD} = \frac{a \cdot b}{\text{LCM}}
$$

Often used to reverse-engineer values when only GCD or LCM is given.

---

## 🧪 Typical CP Problems

### ✅ Problem Patterns:

* Smallest number divisible by all array elements
* "Do x and y align every N seconds?" → LCM(x, y)
* Construct array of N elements with LCM = K
* LCM ≤ K in subarrays
* LCM and GCD sum/max

---

## 🧠 Sample Practice Problems

| Platform   | Problem Name                                                               | Tags                       |
| ---------- | -------------------------------------------------------------------------- | -------------------------- |
| Leetcode   | [LCM of Two Numbers](https://leetcode.com)                                 | Math, Number Theory        |
| GFG        | [LCM of Array](https://www.geeksforgeeks.org/lcm-of-given-array-elements/) | Arrays, LCM                |
| Codeforces | [LCM Problem](https://codeforces.com/problemset/problem/1834/A)            | Math, Brute Force          |
| AtCoder    | [LCM Sum](https://atcoder.jp/contests/abc)                                 | Math, Prefix, Optimization |

---

## 📌 Key Reminders

* Always use GCD to calculate LCM.
* Handle overflows with rearranged formula.
* LCM of multiple numbers → reduce with associativity.
* `LCM` is a frequent trap for overflows — test edge cases.

---

## 📦 Bonus Tip: Write a Utility Function

```cpp
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b; // safe from overflow
}
```

---

## ✨ To-Do for Mastery

* [ ] Implement LCM function with safe overflow handling
* [ ] Practice at least 5 array-based LCM problems
* [ ] Revise LCM + GCD identity weekly
* [ ] Solve a CRT + LCM problem
* [ ] Understand `__int128` if dealing with huge numbers

---

## 🧠 Final Thought

> *LCM is like that polite kid in class — quiet until you mess up your math or let it overflow. Treat it right, and it’ll solve your hardest CP scheduling and math puzzles.*

---
