
# Sliding Window Technique - Quick Revision Guide

## What is Sliding Window?
Sliding Window is a technique used to reduce the time complexity of brute-force solutions involving subarrays or substrings by using a window (i.e., subarray) that slides over the data.

## When to Use Sliding Window?
Use Sliding Window when:
- You deal with contiguous subarrays or substrings.
- You're asked to find sum, count, maximum/minimum, or length over a range.
- The problem involves arrays or strings.
- You notice that recalculating from scratch every time is expensive.

## Types of Sliding Window

### 1. Fixed Size Window
Used when the window size is given or constant.

Example Code:
```cpp
int maxSum(vector<int>& arr, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) sum += arr[i];
    int max_sum = sum;
    for (int i = k; i < arr.size(); i++) {
        sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}
```

### 2. Variable Size Window
Used when the window size is not fixed and depends on conditions (e.g., sum or number of distinct elements).

Example Code:
```cpp
int minSubArrayLen(int target, vector<int>& nums) {
    int i = 0, sum = 0, min_len = INT_MAX;
    for (int j = 0; j < nums.size(); j++) {
        sum += nums[j];
        while (sum >= target) {
            min_len = min(min_len, j - i + 1);
            sum -= nums[i++];
        }
    }
    return min_len == INT_MAX ? 0 : min_len;
}
```

## Monotonic Behavior
Sliding Window works well when the value you're tracking changes monotonically:

| Problem Type                  | Monotonic Behavior | Sliding Window Friendly |
|------------------------------|--------------------|------------------------|
| Sum of only positive numbers  | Yes                | Yes                    |
| Count of distinct characters  | Yes                | Yes                    |
| Sum including negative numbers| No                 | Prefer Prefix Sum      |
| Product of elements           | No                 | Often unstable         |

If behavior is non-monotonic, consider using prefix sum, hash map, or binary search instead.

## Common Use Cases

| Problem Type                        | Technique                   |
|-----------------------------------|-----------------------------|
| Max/Min sum of subarray of size k | Fixed Size Sliding Window    |
| Longest substring with ≤ K distinct chars | Variable Window + HashMap |
| Count subarrays with exact sum     | Prefix Sum + HashMap OR Two Sliding Windows |
| Longest subarray with sum ≤ K      | Variable Sliding Window      |
| Max vowels in a substring of length k | Fixed Sliding Window        |

## When Not to Use Sliding Window?
Avoid sliding window when:
- You're dealing with non-contiguous elements.
- The value being tracked does not change predictably (non-monotonic).
- The problem involves combinatorics, recursion, or backtracking.
- You're working on multiple windows or need global scanning (e.g., LIS problems).

## Must-Practice Sliding Window Problems

| Platform  | Problem Title                     |
|-----------|---------------------------------|
| LeetCode  | 209. Minimum Size Subarray Sum  |
| LeetCode  | 1004. Max Consecutive Ones III  |
| LeetCode  | 904. Fruit Into Baskets          |
| LeetCode  | 713. Subarray Product Less Than K |
| LeetCode  | 1248. Count Number of Nice Subarrays |
| GeeksforGeeks | Longest Substring Without Repeating Characters |
| Codeforces| Various sliding window problems  |

