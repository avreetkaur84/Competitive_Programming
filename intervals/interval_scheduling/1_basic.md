# Interval Scheduling (Selection) — The Complete Mental Kit

## 1️⃣ What this category ACTUALLY is

**Core problem:**

> Select the **maximum number of non-overlapping intervals**

That’s it. No tricks. No profits. No coverage. Just *count*.

If the question is about **choosing as many intervals/events/tasks/meetings as possible without overlap**, this is your category.

---

## 2️⃣ The One Rule (burn this into your brain)

> **Always pick the interval that finishes first.**

Not:

* shortest duration ❌
* earliest start ❌
* smallest overlap ❌

Only:
👉 **earliest end time**

Why?
Because it leaves the **maximum remaining space** for future intervals.

If your greedy choice does not *maximize future options*, it’s wrong.

---

## 3️⃣ The Invariant (this is what interviewers care about)

At any point:

> The chosen interval ends as early as possible among all valid choices.

This guarantees:

* You never block a future interval unnecessarily
* Any other choice can be swapped with this one without reducing the count

If you can *say this invariant out loud*, you understand the problem.

---

## 4️⃣ Recognition Signals (VERY IMPORTANT)

### 🚨 Strong indicators

* “maximum number of…”
* “attend as many…”
* “non-overlapping”
* “cannot overlap”
* “choose events/meetings/tasks”

### 🧠 Sneaky variants

* Activities
* Jobs
* Events
* Courses
* Performances
* Appointments

If it smells like scheduling → **sort by end time**.

---

## 5️⃣ What You Will ALWAYS Use (Toolkit)

### 🧰 Tools

* Sorting (by end time)
* Single pass greedy
* A variable like:

  * `last_end`
  * `current_end`

### 🧠 Thought process

1. Sort intervals by **end**
2. Initialize `last_end` = end of first selected interval
3. For each interval:

   * If `start >= last_end` → select it

⚠️ Overlap definition matters:

* `[a, b)` vs `[a, b]`
* Read constraints carefully (this kills people)

---

## 6️⃣ What This Category is NOT (don’t misclassify)

| Problem Type                     | Is this interval scheduling? |
| -------------------------------- | ---------------------------- |
| Minimum intervals to cover range | ❌                            |
| Max overlap at a time            | ❌                            |
| Weighted profit                  | ❌                            |
| Merge intervals                  | ❌                            |
| Meeting rooms                    | ❌                            |

If you’re **optimizing count**, not coverage or value → yes
Otherwise → wrong bucket

---

## 7️⃣ Common Traps (and how to not embarrass yourself)

### ❌ Sorting by start time

Fails on:

```
[1,10], [2,3], [4,5]
```

### ❌ Choosing shortest interval

Fails subtly; duration ≠ future flexibility

### ❌ Confusing with meeting rooms

* Scheduling = **select max**
* Meeting rooms = **min resources**

Opposite goals.

---

## 8️⃣ Edge Cases You MUST Think About

* Same end times
* Fully nested intervals
* Touching boundaries (`end == start`)
* Empty input
* Single interval

If you forget these, test cases will remind you. Rudely.

---

# Practice List — DO THESE IN ORDER (No Skipping)

## 🔹 LeetCode (Core)

1. **435. Non-overlapping Intervals**
2. **252. Meeting Rooms**
3. **2406. Divide Intervals Into Minimum Number of Groups** *(contrast problem)*
4. **1288. Remove Covered Intervals**
5. **646. Maximum Length of Pair Chain**

---

## 🔹 LeetCode (Classic Disguised)

6. **452. Minimum Number of Arrows to Burst Balloons**
7. **757. Set Intersection Size At Least Two**
8. **1353. Maximum Number of Events That Can Be Attended**

---

## 🔹 Codeforces (Pure Gold for This Pattern)

1. **CF 1623B – Game of Ball Passing**
2. **CF 1234C – Pipes**
3. **CF 1661B – Getting Zero**
4. **CF EDU Greedy: Activity Selection**

(Search by title—these are textbook greedy scheduling.)

---

## 9️⃣ How to Know You’ve MASTERED This Category

You should be able to:

* Instantly say **“sort by end”** without thinking
* Explain *why* earliest end works
* Detect fake greedy traps
* Solve variations without changing logic

If not → you’re memorizing, not understanding.

---

## Final Mentor Note (friendly but honest)

If you struggle **after** mastering this category, the issue isn’t intervals—it’s **recognition speed**.

Do 6–8 of these *properly*, and your brain will auto-route.