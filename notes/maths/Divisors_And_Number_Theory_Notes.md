# Number Theory and Divisors — Deep CP Notes

## 🔢 Concept 1: Number of Divisors Formula

Given a number `n` with its **prime factorization** as:
```
n = p₁^e₁ × p₂^e₂ × ... × pₖ^eₖ
```
The **total number of divisors** of `n` is:
```
(e₁ + 1) × (e₂ + 1) × ... × (eₖ + 1)
```

### 📌 Example:
`n = 60 = 2^2 × 3^1 × 5^1`  
Number of divisors = (2 + 1)(1 + 1)(1 + 1) = **12**

---

## 🧠 Concept 2: Prime Factorization Using Code

To get the prime factorization of a number `n`, we can loop from `i = 2` to `sqrt(n)`. 
At each step, we divide `n` by `i` as many times as possible. Only if `n % i == 0` do we consider `i` a factor.

```cpp
vector<pair<int, int>> prime_factors(int n) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; ++i) {
        int count = 0;
        while (n % i == 0) {
            ++count;
            n /= i;
        }
        if (count) {
            factors.push_back({i, count});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
    return factors;
}
```

### ⚡ Insight:
We only get **prime factors**, not composites! Why?

- Composite numbers are made of smaller primes.
- By the time we reach a composite number `c`, the primes that make up `c` have already divided `n` completely.
- So `n % c != 0` and we skip it.

That’s why **only primes make it** into the vector.

---

## 🧮 Concept 3: Numbers with Exactly 4 Divisors

### Types of numbers with exactly 4 divisors:
1. **p³** (a prime raised to 3):  
   - e.g., 2³ = 8 → divisors = {1, 2, 4, 8}
2. **p × q** (product of 2 distinct primes):  
   - e.g., 2 × 3 = 6 → divisors = {1, 2, 3, 6}

These are the **only two types** of numbers with exactly 4 positive divisors.

Why?
- For `p³`, number of divisors = (3 + 1) = 4
- For `p × q`, number of divisors = (1 + 1)(1 + 1) = 4

---

## 🧩 Concept 4: Square Root Optimization in Loops

When looping to factor a number `n`, we go only till `sqrt(n)`.

> If a number `n` has a factor greater than `sqrt(n)`, its **pair** is less than `sqrt(n)`, and will be found **earlier**.

So it's optimal and safe to loop till `i * i <= n`.

---

## 🤖 Brute Force CP Logic Using Math

Suppose we want to find numbers with at least 4 divisors such that the **difference between selected divisors** is at least `d`. Basic logic:

1. **Iterate over numbers from `1` to `max_n`**
2. For each number:
   - Get **all divisors** using the `prime_factors` trick.
   - Store divisors in an array or set.
3. Check if there exists **4 divisors** such that each pair is `>= d` apart.
4. Skip rest once 4 are found.

💡 Improvement: Once a valid divisor is found, **jump ahead by `d`** to search for the next.

---

## 🚀 Why This is Beautiful

This is the exact point where **math meets code** —
- Faster logic
- Smarter skips
- Cleaner loops
- Less memory & time

Understanding the **structure of numbers** lets you solve CP problems that others try to brute force — and fail.

---

## ✅ Practice Problems
- [Leetcode 1390 - Four Divisors](https://leetcode.com/problems/four-divisors/)
- Codeforces and AtCoder problems on "Number Theory", "Divisors", "Factorization"

---

## 🔚 Final Thoughts

> **Knowing the mathematical structure of numbers helps you build optimal, elegant, and faster solutions.**

You're not just solving problems — you're decoding **how numbers behave**.

🔥 Stick to this path and you’ll start enjoying CP more than ever.