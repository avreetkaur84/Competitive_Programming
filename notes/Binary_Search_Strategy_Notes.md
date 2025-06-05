### 🔍 **"Low-High" Binary Search Strategy — In General**

Think of binary search not as *just* a way to find a number in a sorted array, but as a **framework** to search for the *best value that satisfies a condition*, when:

* The solution space is **monotonic** (if condition is true for some `x`, then it’s true for all values > `x` or < `x`).
* You can define a function `isValid(x)` or `check(x)` to **tell whether a guess is good or not**.

---

## 🔁 The General Binary Search Pattern

```python
low = minimum_possible_value
high = maximum_possible_value

while low <= high:
    mid = (low + high) // 2
    if check(mid):      # or isValid(mid)
        # mid is a valid answer. Try to find a better one (maybe smaller/larger)
        high = mid - 1   # or low = mid + 1, depending on direction
    else:
        # mid is invalid. Adjust the range to eliminate this and bad ones.
        low = mid + 1    # or high = mid - 1
```

> **Key Insight:** You're not searching in an array — you're searching in a range of *potential answers*.

---

### ✅ **When Should You Use This?**

When:

* You're told to find the **minimum / maximum value** that satisfies a condition.
* You have a **range of answers**, not necessarily an array.
* You can check whether a guess is valid in **O(log n)** or better.
* The condition is **monotonic**: once it's true, it stays true (or false, then stays false).

---

## 📦 Types of Problems Where It Applies

| Problem Type            | Example                                                                    |
| ----------------------- | -------------------------------------------------------------------------- |
| Allocate resources      | "Can I paint all houses in `x` days with `k` painters?"                    |
| Minimize/Maximize value | "What is the minimum largest sum I can split an array into `k` subarrays?" |
| Greedy Validity Check   | "Can I place `k` cows in stalls at least `d` distance apart?"              |
| Scheduling              | "Can I finish `x` tasks in `t` units of time?"                             |

---

### 👇 Let’s break it into intuition levels

---

### 🧠 **Level 1: Classic Binary Search on a Sorted Array**

```python
low = 0
high = len(arr) - 1
while low <= high:
    mid = (low + high) // 2
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        low = mid + 1
    else:
        high = mid - 1
```

---

### 🧠 **Level 2: Binary Search on the Answer**

Example: **Minimum Capacity to Ship Packages in D Days**

You want the *minimum ship capacity* such that all packages can be shipped in `D` days.

```python
low = max(packages)         # at least the largest single package
high = sum(packages)        # at most ship everything in 1 day

def canShip(capacity):
    days = 1
    current = 0
    for p in packages:
        if current + p > capacity:
            days += 1
            current = 0
        current += p
    return days <= D

while low <= high:
    mid = (low + high) // 2
    if canShip(mid):
        answer = mid
        high = mid - 1
    else:
        low = mid + 1
```

---

### 💡 Tip to Master It

Whenever you see:

> “Find the **minimum/maximum** value of X such that condition Y holds”

Immediately think:

> Can I apply binary search on **X** by defining a `check(X)` function?

---

### 🔁 Which direction to move?

* If `check(mid)` is **True** and you're minimizing → move `high = mid - 1`
* If `check(mid)` is **True** and you're maximizing → move `low = mid + 1`
* If `check(mid)` is **False** → go in the opposite direction

---

### 🧪 Think Like This:

You’re playing a guessing game.

* Your guess is `mid`.
* You have a **judge function** `check(mid)` that says “yes” or “no”.
* Based on that, you adjust your guess range.

---

### 🛠️ Abstract Template (Minimum Valid Value)

```python
def check(x):
    # returns True if x is a valid answer

low = some_min_possible_value
high = some_max_possible_value
answer = -1

while low <= high:
    mid = (low + high) // 2
    if check(mid):
        answer = mid      # this mid is valid, but maybe we can do better
        high = mid - 1
    else:
        low = mid + 1

return answer
```
