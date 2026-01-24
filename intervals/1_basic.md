> Everything started with - LC QUES: 1326 - https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

## Phase 0: Mental Model (this is why you’re stuck)

Most people fail interval problems because they think in **intervals** instead of **events**.

Hard interval problems are almost always one of:

1. **Greedy with a specific invariant**
2. **Line sweep (events + ordering)**
3. **DP on sorted intervals**
4. **Binary search on answer**
5. **Graph-ish thinking (covering / selecting)**

If you try to brute-force “merge-like thinking” everywhere → instant pain.

---

## Phase 1: Core Greedy Interval Patterns (You must master these invariants)

### 1️⃣ Interval Scheduling (Selection)

**Goal:** Pick max number of non-overlapping intervals
**Key invariant:**

> Always pick the interval that **ends earliest**

🔑 Teaches you:

* Why sorting by end time matters
* Why “local optimal → global optimal” works

🧠 Recognition clue:

* “maximum number of intervals”
* “attend as many meetings as possible”

---

### 2️⃣ Minimum Intervals to Cover a Range (VERY IMPORTANT)

This is where most people collapse.

**Problem type:**

> Given intervals, cover `[L, R]` using minimum intervals

**Greedy idea:**

* Sort by start
* At current position, choose the interval that:

  * starts ≤ current
  * extends **farthest to the right**

If you don’t think in **“expand coverage greedily”**, you lose.

🧠 Recognition clue:

* “cover entire area”
* “minimum segments”
* “full coverage”

📌 This is NOT merge intervals.
📌 This is **jump-game thinking in 1D**.

---

## Phase 2: Line Sweep (Not just “prefix sum”, your friend undersold it)

Line sweep = **convert intervals into events**, then process in order.

### 3️⃣ Basic Line Sweep (Overlap counting)

**Events:**

* `(start, +1)`
* `(end, -1)` (or `end+1` depending on inclusive/exclusive)

**Use cases:**

* Maximum overlapping intervals
* Minimum number of meeting rooms
* Peak usage time

🧠 Recognition clue:

* “maximum simultaneous”
* “minimum rooms”
* “overlaps at any time”

---

### 4️⃣ Line Sweep with State (THIS is the hard part)

This is where it becomes powerful.

Instead of just counting, you track:

* active intervals
* max end
* current coverage
* gaps

Used for:

* union length of intervals
* detecting uncovered regions
* skyline problems
* splitting segments

🧠 Recognition clue:

* “total covered length”
* “find gaps”
* “visible segments”

---

## Phase 3: Interval DP (the hidden boss)

### 5️⃣ Weighted Interval Scheduling

**Problem:**

> Intervals have weights/profits. Pick non-overlapping intervals with max profit.

**Key idea:**

* Sort by end time
* DP[i] = best till i
* Binary search for last compatible interval

This teaches:

* DP + greedy + binary search combo

🧠 Recognition clue:

* “profit”
* “maximize value”
* “cannot overlap”

---

### 6️⃣ Interval DP on ranges

Classic examples:

* Burst balloons
* Minimum cost to cut a stick
* Matrix chain style

**Pattern:**

> DP[l][r] = best solution for interval [l, r]

🧠 Recognition clue:

* “choose a partition point”
* “cost depends on sub-intervals”

---

## Phase 4: Binary Search on Answer + Intervals

### 7️⃣ Feasibility Checking

You binary search the answer, and **check if intervals can achieve it**.

Examples:

* Can we cover the range with ≤ k intervals?
* Can we schedule tasks within time T?

Greedy is used **inside** binary search.

🧠 Recognition clue:

* “minimum possible maximum”
* “at least / at most k intervals”

---

## Phase 5: Advanced / Niche but Powerful

### 8️⃣ Difference Array / Prefix Trick (Line sweep lite)

Used when:

* You don’t need ordering of events
* Just range increments and queries

Examples:

* Flight bookings
* Range updates

---

### 9️⃣ Interval Graph Thinking

Intervals form graphs where overlap = edge.

Used in:

* Coloring (meeting rooms)
* Conflict detection

---

## How to Practice (Important or you’ll just “read” this)

### Step 1: Pattern Buckets

Create 5 buckets:

1. Greedy coverage
2. Line sweep
3. Interval DP
4. Binary search + intervals
5. Mixed

Solve **5–7 problems per bucket**, not random.

---

### Step 2: Force Yourself to Answer These Before Coding

For every interval problem, ask:

1. **What is fixed?** (start, end, profit, count)
2. **What am I optimizing?**
3. **Do I care about order or overlaps?**
4. **Am I selecting intervals or analyzing coverage?**

If you can’t answer these → stop coding.

