# `Prefix + Suffix Pattern in DSA`

This pattern is a powerful tool for solving problems where an element's result depends on **information from both sides** (left and right) of the array.

---

## ✨ Core Idea

For each index `i`, compute something like:

```
result[i] = f(prefix[0..i], suffix[i..n-1])
```

Typically, this is used when:

* You need **max/min/sum** of elements **before and after** a point
* Water trapping / range dominance / visibility / balance problems

---

## ✅ Common Use-Cases

### 1. **Trapping Rain Water**

* For each `i`, trapped water = `min(max_left[i], max_right[i]) - height[i]`
* Build prefix and suffix arrays with max so far

### 2. **Max Width Ramp**

* You want to find the largest j - i such that A\[i] <= A\[j]
* Build prefix min from left and suffix max from right

### 3. **Candy Distribution (Leetcode 135)**

* Do a left-to-right pass: give more candy if child is bigger than left
* Do a right-to-left pass: ensure child has more candy than right if needed

### 4. **Product of Array Except Self**

* Prefix product to left, suffix product to right

### 5. **Largest Element to Left/Right**

* Prefix max array and suffix max array can solve this in O(N)

---

## 📊 General Template

```cpp
int n = A.size();
vector<int> prefix(n), suffix(n);

// Build prefix max/min/sum/whatever
prefix[0] = A[0];
for (int i = 1; i < n; i++)
    prefix[i] = some_function(prefix[i-1], A[i]);

// Build suffix max/min/sum/whatever
suffix[n-1] = A[n-1];
for (int i = n - 2; i >= 0; i--)
    suffix[i] = some_function(suffix[i+1], A[i]);

// Final result combining both sides
for (int i = 0; i < n; i++) {
    result[i] = combine(prefix[i], suffix[i], A[i]);
}
```

---

## 🔬 Complexity

* Time: O(N)
* Space: O(N) (can be reduced to O(1) in some problems with clever 2-pointer techniques)

---

## 🔹 When to Use

* If you're asked: *"how does an element compare to those on both sides?"*
* If values depend on **extremes (max/min)** from **both directions**
* If stack feels messy or only gives one-side insight

---

## 💡 Bonus Optimization: Two Pointers

Some problems (like trapping rain water) can be done with **two pointers** instead of two arrays.

---

## 📃 Add to Your Pattern Notebook

### Prefix + Suffix Pattern
- Trapping Rain Water
- Product of Array Except Self
- Max Width Ramp
- Candy Distribution
- Building Visibility Problems


---