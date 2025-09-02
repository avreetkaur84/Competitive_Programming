### 🟢 Easy / Intro to Prefix Sum

1. **CF 381A – Sereja and Dima** *(basic sums, simulation — warmup)*
2. **CF 363B – Fence** *(classic sliding window but solvable with prefix sums)*
3. **CF 299B – Ksusha and Array** *(checking divisible segments, prefix sums help)*

---

### 🟡 Medium (classic prefix sums)

4. **CF 433B – Kuriyama Mirai’s Stones** *(build prefix sums once, answer queries fast)*
5. **CF 474B – Worms** *(binary search + prefix sums, very famous one)*
6. **CF 567A – Lineland Mail** *(distance queries — prefix trick works)*
7. **CF 433A – Kitahara Haruki’s Gift** *(prefix sum feasibility checking)*

---

### 🔵 Harder / Interesting applications

8. **CF 961B – Lecture Sleep** *(prefix sums + sliding window optimization)*
9. **CF 363C – Fixing Typos** *(string, but prefix sums can help in frequency control)*
10. **CF 816B – Karen and Coffee** *(range add → prefix sum → queries)*
11. **CF 817C – Really Big Numbers** *(prefix sums + digit sum condition)*

---

👉 My suggestion:

* Start with **363B (Fence)** and **433B (Kuriyama Mirai’s Stones)** — they’re very popular prefix problems.
* Then jump to **474B (Worms)** for a prefix+binary search flavor.
* Once comfy, try **961B (Lecture Sleep)** or **816B (Karen and Coffee)** — these will really test your range handling skills.

---

1. Max Average ≥ L
Given an array A of n integers (may be negative) and an integer L (1 ≤ L ≤ n), find the maximum possible average of any subarray whose length is at least L. Output the value with 1e-5 precision.
Constraints: n ≤ 2e5, |A[i]| ≤ 1e9.


2. Closest Subarray Sum to K
Given an array A of n integers (may be negative) and a target K, find a subarray whose sum is closest to K (minimize absolute difference). Output that closest sum.
Constraints: n ≤ 2e5, |A[i]| ≤ 1e9, |K| ≤ 1e14.


3. Longest Subarray with Sum ≤ K (Negatives Allowed)
Given an array A of n integers (can be positive/negative/zero) and an integer K, find the maximum length of a subarray with sum ≤ K. If none, print 0.
Constraints: n ≤ 2e5, |A[i]|, |K| ≤ 1e14.


4. K-th Smallest Subarray Sum
Given an array A of n non-negative integers and an integer k (1 ≤ k ≤ n(n+1)/2), find the k-th smallest subarray sum among all n(n+1)/2 subarrays.
Constraints: n ≤ 2e5, 0 ≤ A[i] ≤ 1e9.