# 🧠 Reverse Simulation Technique for Encoded/Expanded String Problems

This approach is a powerful method for solving problems where a string is **encoded/expanded** by repetition or transformation operations (e.g., digits multiplying string parts, or symbols like `#` duplicating content).

Commonly seen in problems like:

* Leetcode 880: Decoded String at Index
* Problems involving custom operators like `*`, `#`, `%`, etc.

---

## ✅ Problem Pattern

You're given an **encoded string `s`** and an integer `k`, and you're asked:

> What is the `k`-th character in the fully decoded/processed string?

But decoding it fully would result in huge memory usage or TLE. Instead, you must compute the answer **without actually building the full string**.

---

## 🔄 Key Idea: Reverse Simulation

We process the string **in reverse** to **trace back** the original character at position `k` by:

1. **First pass (forward)**: Simulate the total decoded string length `len`.
2. **Second pass (reverse)**: Walk backwards through the string and **adjust `k`** to find its original source in the smaller versions of the string.

---

## 🧮 Forward Pass (Calculate Total Length)

```cpp
long long len = 0;
for (char c : s) {
    if (isalpha(c)) len++;
    else len *= (c - '0');
}
```

> Simulates the final length of the decoded string **without building it**.

---

## 🔙 Reverse Pass (Trace Back `k`)

```cpp
for (int i = s.size() - 1; i >= 0; i--) {
    k %= len;

    if (isalpha(s[i]) && (k == 0)) // if 1-indexed
        return string(1, s[i]);

    if (isdigit(s[i]))
        len /= (s[i] - '0');
    else
        len--;
}
```

### 🔁 Why `k %= len;`?

`k` is an index in a **longer version** of the string (due to repetition). To trace back to the shorter version before duplication:

* We map `k` into its original index inside the shorter string:

```cpp
k %= len;
```

This keeps `k` always within the range of the string’s current (shrinking) size.

---

## 🧸 0-Indexed vs 1-Indexed `k`

| Indexing | Final condition to return `s[i]` |
| -------- | -------------------------------- |
| 1-based  | `k == 0 && isalpha(s[i])`        |
| 0-based  | `k == len - 1 && isalpha(s[i])`  |

> Make sure to convert `k` correctly if the question uses 0-based or 1-based indexing.

---

## 🔥 General Template

```cpp
long long len = 0;
for (char c : s) {
    if (isalpha(c)) len++;
    else len *= (c - '0');
}

for (int i = s.size() - 1; i >= 0; i--) {
    k %= len;

    if (isalpha(s[i]) && k == 0)
        return string(1, s[i]);

    if (isdigit(s[i]))
        len /= (s[i] - '0');
    else
        len--;
}
```

---

## ✅ When to Use This Approach

* You are **given an encoded string with repeat/double/multiply logic**.
* You're **asked for a specific character at position `k`**.
* Fully decoding the string is not feasible due to memory/time.
* You can simulate **length and transformations** without actual decoding.

---

## 👑 Bonus Tips

* Always be mindful of **indexing** — if you're off by 1, check if the question uses 0 or 1 indexing.
* `k %= len;` is often the **key to shrinking** the search space.
* This reverse simulation technique generalizes well to other problems with operations like `#` (duplicate), `*` (delete), `%` (reverse).

---

Use this technique confidently in competitive coding, interviews, and problems where "build and search" is too costly. 🚀
