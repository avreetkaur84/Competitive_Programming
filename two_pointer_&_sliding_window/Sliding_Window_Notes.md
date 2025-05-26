
# 🧠 Sliding Window — Core Notes

### 🧠 General Conditions
1. **Contiguous Elements**:
   - Sliding window is used when the problem is asking for operations on **subarrays (contiguous sequences)**.

2. **Monotonicity (Optional)**:
   - Sometimes, you maintain a **monotonic deque** (increasing or decreasing) to keep track of maximum/minimum efficiently (used in problems like "Maximum in all subarrays of size K").

3. **Fixed or Variable Window**:
   - **Fixed-size window**: You slide by one and maintain the window size.
   - **Variable-size window**: You shrink and expand the window dynamically to satisfy some condition.

4. **Two Pointers**:
   - Most sliding window problems are an implementation of the **two pointers** pattern: `left` and `right` moving through the array.

5. **Prefix Sum is NOT Needed**:
   - Unlike brute force or range sum problems where prefix sum might be needed, sliding window often maintains a **rolling sum or count** as the window moves.

### 🧾 Common Conditions / Checks for Applicability

| Condition | Explanation |
|----------|-------------|
| Problem involves subarrays / substrings | This is the most basic sign. |
| Asking for "longest/shortest" window with a property | Usually means **variable-sized window**. |
| Asking for "maximum/minimum" in every window of size K | Use **monotonic deque** with fixed window. |
| You need to maintain frequency/count in a range | Often used in **variable window + hashmap**. |
| Array is unbounded, but condition must be valid in window | Slide window until condition breaks, then shrink. |
| Input is a stream or too large for nested loops | Sliding window gives an O(n) or O(n log k) alternative. |

### 🛠️ Data Structures Often Used With Sliding Window

- **HashMap / HashSet**: To maintain frequencies (ex: longest substring without repeating characters).
- **Deque**: To maintain the min/max in a window in O(1) time (ex: max in sliding window).
- **Array**: If the frequency range is small (like 26 lowercase letters), use simple frequency arrays.

### ⚙️ Sliding Window Properties

| Property | Meaning |
|----------|--------|
| Monotonic | If you're maintaining a window where elements follow a certain increasing/decreasing order (monotonic stack/deque). |
| Rolling Calculation | Maintain sum/product/count inside the window as it moves instead of recalculating from scratch. |
| Shrinking/Expanding | In variable-sized windows, you move `right` to expand and `left` to shrink until a condition is met. |
| Greedy Element Removal | Sometimes used to drop elements from the window to maintain optimal result (e.g., smallest window with all characters). |

### 🧪 Example-Based Conditions

| Problem Type | Technique |
|--------------|-----------|
| Longest substring with at most K distinct chars | Variable window, hashmap for char count |
| Subarray with sum <= K | Variable window, rolling sum |
| Max of each subarray of size K | Fixed window, monotonic deque |
| Count of substrings with all vowels | Variable window, hashset |
| Longest subarray with equal 0s and 1s | Convert 0s to -1s, use prefix sum + hashmap (not typical SW, but a trick variant) |

## 🔁 Common Approach (Fixed or Variable Size)
Sliding Window is used to reduce time complexity from **O(n²)** to **O(n)** in problems that involve subarrays, substrings, or continuous segments.

---

## ✅ 1. Fixed Size Sliding Window
Use this when window size is **given or fixed** (e.g., "Find max sum of subarray of size `k`").

**Pattern:**
```python
left = 0
current_sum = 0

for right in range(len(arr)):
    current_sum += arr[right]

    # shrink window when size exceeds k
    if right - left + 1 > k:
        current_sum -= arr[left]
        left += 1

    # process result when window is exactly size k
    if right - left + 1 == k:
        result = max(result, current_sum)  # or some condition
```

---

## ✅ 2. Variable Size Sliding Window
Use this when window size **depends on a condition** (e.g., "Find the length of longest substring with at most `k` distinct characters").

**Pattern:**
```python
left = 0
for right in range(len(arr)):
    # Expand window: add arr[right]

    # While condition is invalid
    while <invalid_condition>:
        # Shrink window from left

    # Process result: window is valid
```

---

# 📦 Where is Sliding Window Applicable?

## 🔹 Strings / Substrings
- Longest substring with **no repeating** characters
- Longest substring with **at most k** distinct characters
- Minimum window substring containing all characters of another string
- Check if one string is a permutation of another (`s1` in `s2`)

## 🔹 Arrays / Subarrays
- Max sum/min sum of subarray of size `k`
- Smallest subarray with sum ≥ `target`
- Count of subarrays with exactly `k` distinct elements
- Max element in every window of size `k` (requires deque)

## 🔹 Binary Arrays
- Longest subarray of 1’s after flipping at most `k` zeroes
- Longest subarray with equal number of 0’s and 1’s (convert to +1/-1 and use hashmap)

## 🔹 Count Based or Frequency-Based
- Count number of substrings that match a pattern
- Count distinct elements in each window

## 🔹 Two Pointer Variant (special case of sliding window)
- Trapping rain water (advanced)
- Subarrays with product less than `k`
- Longest mountain or peak in array

---

# ⚠️ Edge Patterns
- Use **hashmap or frequency map** if condition is based on characters/elements.
- In some problems, window shrinkage might not be based on size but on **frequency/constraint violation**.
