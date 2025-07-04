### ✅ `README.md` – `base-k-conversion`

# 🔢 Base-k Conversion – Master Notes

This document covers everything you need to understand and apply **Base-k representation** in programming, with clear examples and use cases.

---

## 📌 What is Base-k?

In Base-k, a number is represented using **powers of `k`** rather than 10.

**Example (Base-10):**
```

473 = 4×10² + 7×10¹ + 3×10⁰

```

**Example (Base-3):**
```

100 (decimal) = 10201 (base-3)
Because: 1×3⁴ + 0×3³ + 2×3² + 0×3¹ + 1×3⁰ = 100

````

---

## 🛠️ How to Convert from Decimal to Base-k

**Algorithm:**
```cpp
while (n > 0) {
    digit = n % k;
    store digit;
    n = n / k;
}
````

⚠️ This gives the digits **in reverse order**.

---

## 🧠 What Do Base-k Digits Represent?

Each digit at position `i` tells:

> "How many times power `k^i` is used in the sum to form `n`."

So base-k is like saying:

```
n = a₀·k⁰ + a₁·k¹ + a₂·k² + ... + aₙ·kⁿ
Where each aᵢ ∈ [0, k-1]
```

---

## ✨ Base-k and Minimum Operations

In problems like:

> ❓ You can subtract any power of `k` from `n`. What’s the **minimum number of steps** to reduce `n` to 0?

➡️ Answer = **Sum of digits of `n` in base-`k`**

---

## ✅ C++ Code Snippet – Convert to Base-k

```cpp
vector<int> getBaseKDigits(int n, int k) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % k);
        n /= k;
    }
    reverse(digits.begin(), digits.end()); // Optional
    return digits;
}
```

---

## 📚 Example Conversions

### 🔹 Example 1: Convert 100 to base-3

Steps:

```
100 ÷ 3 = 33 R1  → digit: 1
33 ÷ 3 = 11 R0   → digit: 0
11 ÷ 3 = 3 R2    → digit: 2
3 ÷ 3 = 1 R0     → digit: 0
1 ÷ 3 = 0 R1     → digit: 1
```

Base-3 = `10201`

Sum of digits = `1 + 0 + 2 + 0 + 1 = 4` → 4 operations to reach 0

---

### 🔹 Example 2: Base-2 of 13

```
13 ÷ 2 = 6 R1
6 ÷ 2 = 3 R0
3 ÷ 2 = 1 R1
1 ÷ 2 = 0 R1

Binary: 1101 → 1×2³ + 1×2² + 0×2¹ + 1×2⁰ = 13
```

---

## 💡 Where Base-k Appears in DSA

| Topic                      | Usage                           |
| -------------------------- | ------------------------------- |
| Bitmasking / Subsets       | Base-2                          |
| Minimum operation problems | Base-k digit sum                |
| Greedy Problems            | Coin change with powers         |
| Combinatorics              | Representing permutation states |
| DP on digits               | Digit-DP uses base              |
| XOR / Binary ops           | Everything is base-2 underneath |

---

## 🧠 Tips

* `k == 1` → infinite loop risk! Special case.
* Watch for overflow in `cur * k` while generating powers.
* Don't forget to reverse the digit array if needed.
* You can reconstruct the number using:

```cpp
int n = 0;
for (int i = 0; i < digits.size(); ++i)
    n += digits[i] * pow(k, digits.size() - i - 1);
```

---

## 🧪 Practice Ideas

1. Convert `n` to base-`k` and print digits
2. Sum of digits in base-`k`
3. Reconstruct `n` from base-`k` digits
4. Find if a number can be represented as sum of **distinct powers of `k`**
5. Apply base-k tricks in greedy + bitmask problems

---

## 🔗 Related CP Problems

* Codeforces 2020A – Find Minimum Operations \[✓]
* Leetcode 405 – Convert a Number to Hexadecimal
* AtCoder Beginner 276 D – Divide by 2 and 3
* Custom: "Can you represent N using at most K powers of base B?"

---

## 🏁 Summary

* Base-k is a fundamental tool in number theory and DSA.
* Learn to read and manipulate number representations beyond base-10.
* Convert, interpret, and use base-k wisely in problems related to **optimization, operations, binary logic, and recursion.**

---

🧠 **"Once you master base-k, you stop seeing digits — and start seeing possibilities."**


---