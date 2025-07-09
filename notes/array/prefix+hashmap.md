# 📘 DSA Notes: Prefix Sum + HashMap Technique for Subarray Problems

---

## 📌 Problem Pattern

These types of problems typically look like:

> Find the **longest / count / check existence** of a subarray that **sums up to K** (where `K` can be `0`, any constant, or even changing conditions).

### 🧠 Keywords that scream for this technique:

* “Subarray” (contiguous)
* “Sum equals K”
* “Longest” or “Number of subarrays”
* “Positive and negative integers” (important)
* Constraints suggest O(n) time, not O(n²)

---

## 🎯 Use Case

This technique is best for:

* Subarray with sum = `K`
* Longest subarray with sum = `K`
* Count of subarrays with sum = `K`
* Checking if any subarray has sum = `K`

---

## 🪛 Core Idea

Use **prefix sum** to keep running sum of elements and **hash map** to store the **first occurrence** of each prefix sum.

### ✨ Observation:

If `prefixSum[j] - prefixSum[i] == K`,
then the subarray `arr[i+1...j]` has sum `K`.

So if:

* `sum` is the current prefix sum
* You’ve seen `sum - K` before at index `idx`
  → Then subarray from `idx+1 to i` has sum `K`.

---

## 🧩 Components

| Variable | Purpose                                            |
| -------- | -------------------------------------------------- |
| `sum`    | Running prefix sum                                 |
| `mp`     | HashMap storing **first index** of each prefix sum |
| `maxx`   | Length of longest subarray (or count if counting)  |

---

## 💡 Algorithm

```cpp
Initialize:
    sum = 0
    maxx = 0
    unordered_map<long long, int> mp

Loop from i = 0 to n-1:
    sum += arr[i]

    If sum == k:
        maxx = max(maxx, i+1)

    If (sum - k) exists in map:
        maxx = max(maxx, i - mp[sum - k])

    If sum not in map:
        mp[sum] = i

Return maxx
```

---

## 🚨 Edge Cases

1. **`sum == k` directly:** Means from 0 to current index is a valid subarray.
2. **Map stores *first* occurrence only**: So we always get longest subarray.
3. **Don't overwrite in map**: Always store `sum → first index`, never update it.
4. **Negative numbers allowed**: That’s why sliding window fails and prefix sum shines.

---

## 🧪 Dry Run Example

Input: `arr = [15, -2, 2, -8, 1, 7, 10, 23], k = 0`

| i | arr\[i] | sum | sum-k | mp\[sum-k] | length | maxx |
| - | ------- | --- | ----- | ---------- | ------ | ---- |
| 0 | 15      | 15  | 15    | -          | -      | 0    |
| 1 | -2      | 13  | 13    | -          | -      | 0    |
| 2 | 2       | 15  | 15    | 0          | 2      | 2    |
| 3 | -8      | 7   | 7     | -          | -      | 2    |
| 4 | 1       | 8   | 8     | -          | -      | 2    |
| 5 | 7       | 15  | 15    | 0          | 5      | 5 ✅  |
| 6 | 10      | 25  | 25    | -          | -      | 5    |
| 7 | 23      | 48  | 48    | -          | -      | 5    |

So longest subarray with sum `0` is of length **5**

---

## 🧠 Template

```cpp
int longestSubarray(vector<int>& arr, int k) {
    unordered_map<long long, int> mp;
    long long sum = 0;
    int maxLen = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if(sum == k) maxLen = i + 1;

        if(mp.find(sum - k) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum - k]);
        }

        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return maxLen;
}
```

---

## 🛠 Related Questions (Same Technique)

| Problem                          | Description                                |
| -------------------------------- | ------------------------------------------ |
| Leetcode 560                     | Count subarrays with sum = k               |
| GFG: Largest subarray with 0 sum | Just a special case with k = 0             |
| Leetcode 325                     | Max size subarray sum = k                  |
| GFG: Subarray with given sum     | Use in O(n) when negative numbers exist    |
| Leetcode 930                     | Binary subarrays with sum = k (with twist) |

---

## 🧭 When *Not* to Use This

* If array only has **positive numbers**, consider sliding window.
* If asked for **non-contiguous subarrays or subsets**, this won’t help.

---

## 🔁 Revision Checklist

✅ Do I have to find a subarray with a fixed sum?
✅ Can elements be negative?
✅ Is it asking for length, count, or check existence?
✅ Can I use prefix sum to express the condition?

---
