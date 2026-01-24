# Minimum Intervals to Cover a Range — The Complete Mental Kit

## 1️⃣ What this category ACTUALLY is

**Core problem:**

> Cover the **entire target range** `[L, R]` using the **minimum number of intervals**

Key difference from scheduling:

* Scheduling → *select as many*
* Coverage → *select as few*

Opposite goals. Opposite greedy rule.

If you apply “earliest end” here → congratulations, you’ve just sabotaged yourself.

---

## 2️⃣ The One Rule (non-negotiable)

> **At any point, choose the interval that starts before (or at) current coverage and extends FARTHHEST to the right.**

Not:

* shortest interval ❌
* earliest end ❌
* minimum overlap ❌

Only:
👉 **maximum reach**

If your greedy choice does not **maximize coverage expansion**, it’s wrong.

---

## 3️⃣ The Mental Model (THIS is the breakthrough)

Stop thinking in “intervals.”
Start thinking in **coverage expansion**.

You maintain:

* `current_end` → how far you’ve covered so far
* `farthest_reach` → best extension available at this step

You are basically doing:

> “From where I am, what is the farthest I can jump next?”

Yes.
This is **Jump Game II but on intervals**.

---

## 4️⃣ The Invariant (say this out loud)

At every step:

> Among all intervals that start ≤ `current_end`, we pick the one that maximizes the next reachable end.

This invariant guarantees:

* Minimum number of intervals
* No wasted coverage
* Global optimality

If you can’t explain *why* this invariant works, pause. Don’t code yet.

---

## 5️⃣ Canonical Greedy Process (language-agnostic)

### 🧠 Thought Process

1. Convert everything into intervals `[start, end]`
2. Sort intervals by `start` (tie-break: larger end first)
3. Initialize:

   * `current_end = L`
   * `farthest_reach = L`
   * `count = 0`
4. Scan intervals:

   * While interval.start ≤ `current_end`:

     * update `farthest_reach = max(farthest_reach, interval.end)`
   * When no more usable intervals:

     * **commit** one interval:

       * `count++`
       * `current_end = farthest_reach`
5. Stop when `current_end ≥ R`
6. If stuck (`farthest_reach == current_end`) → impossible

⚠️ This “commit step” is where people mess up.

---

## 6️⃣ Why This Greedy Works (interviewer-grade explanation)

Suppose you are at position `x`.

Any valid solution **must** pick an interval that starts ≤ `x`.

Among all such intervals:

* Picking one that ends earlier **cannot help**, because:

  * It covers less
  * It restricts future options
* Picking the one that ends farthest:

  * Maximizes remaining uncovered space
  * Never increases total number of intervals needed

Therefore:
👉 local max-reach choice → global minimum count

This is a **matroid-style greedy**. (Yes, that’s a flex.)

---

## 7️⃣ Recognition Signals (do NOT miss these)

### 🚨 Strong indicators

* “cover entire range”
* “minimum number of segments”
* “fully cover”
* “water the whole garden”
* “reach the end”

### 🧠 Disguised forms

* Taps
* Cameras
* Sprinklers
* Videos
* Clips
* Signals
* Interceptors

If it sounds like **“activate sources to cover an area”** → this bucket.

---

## 8️⃣ What This Category is NOT

| Problem Type    | Is this coverage? |
| --------------- | ----------------- |
| Merge intervals | ❌                 |
| Max overlap     | ❌                 |
| Scheduling      | ❌                 |
| Weighted profit | ❌                 |
| Meeting rooms   | ❌                 |

If the goal isn’t **full coverage with minimum picks**, wrong bucket.

---

## 9️⃣ Common Traps (these WILL ruin you)

### ❌ Sorting by end time

Fails because early-ending intervals don’t expand coverage.

### ❌ Picking intervals one-by-one

You must **scan first, commit later**.

### ❌ Confusing “touching” boundaries

Is `[a,b]` inclusive? Exclusive? Off-by-one errors love this problem.

### ❌ Thinking merge logic applies

Merge ≠ minimize picks.

---

## 🔥 Canonical Example (burn this in)

Intervals:

```
[0,2], [1,5], [3,6], [5,10]
Target: [0,10]
```

Wrong greedy:

* pick [0,2] → dead

Correct greedy:

* from 0 → best reach = 5
* commit → current = 5
* from 5 → best reach = 10
* commit → done

Answer = 2

---

## 10️⃣ THIS is why LC 1326 belongs here

**LC 1326 – Minimum Number of Taps**

Translation:

* Each tap gives an interval
* Garden = `[0, n]`
* Find **minimum taps** to cover it

That’s literally this category wearing a trench coat.

If you didn’t think “coverage expansion” there—now you know why it hurt.

---

## 11️⃣ Edge Cases You MUST handle

* Gaps in coverage
* Multiple intervals starting at same point
* Intervals fully contained in others
* Zero-length intervals
* Impossible cases

If you ignore these, test cases won’t ignore you.

---

## 12️⃣ Practice List — NO SKIPPING

### 🔹 LeetCode (Core)

1. **1326. Minimum Number of Taps to Open to Water a Garden**
2. **1024. Video Stitching**
3. **45. Jump Game II** *(conceptual twin)*
4. **55. Jump Game**
5. **757. Set Intersection Size At Least Two** *(hard variant)*

### 🔹 Advanced

6. **871. Minimum Number of Refueling Stops**
7. **1288. Remove Covered Intervals** *(contrast logic)*

---

## 13️⃣ Mastery Checklist

You’ve mastered this when:

* You instantly think **“expand farthest reach”**
* You delay committing until scan ends
* You can explain why early end is WRONG here
* You see Jump Game hiding inside interval problems

If not → reread invariant, not code.

---
