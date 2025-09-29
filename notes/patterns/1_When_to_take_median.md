## 🔎 Why Median Minimizes Sum of Absolute Differences

We want to minimize:

```
[
f(L) = \sum_{i=0}^{m-1} |b[i] - L|
]
```

### Step 1: Think geometrically

* Imagine points `b[0], b[1], … b[m-1]` on a number line.
* `L` is a point we get to choose.
* The cost is the total distance from all points to `L`.

If you move `L` left, you get closer to some points, but farther from others.
If you move `L` right, same thing.

So there must be a “balance point” where moving left or right doesn’t reduce the sum. That’s the **median**.

---

### Step 2: A simple example

Take numbers `[1, 2, 9]`.

* If `L = 2` (the median):
  Cost = |1-2| + |2-2| + |9-2| = 1 + 0 + 7 = 8.

* If `L = 1`:
  Cost = 0 + 1 + 8 = 9.

* If `L = 9`:
  Cost = 8 + 7 + 0 = 15.

So median wins.

---

### Step 3: Formal reasoning (derivative-style)

Sort `b`: (b_0 \le b_1 \le \dots \le b_{m-1}).

When you increase `L` by 1:

* Every element ≤ L adds +1 to cost.
* Every element > L subtracts 1 from cost.

So slope = (#elements ≤ L) - (#elements > L).

At the median, these two sides are balanced (half on each side), so slope = 0 → minimum.

---

## ⚡ Where this pattern shows up

This isn’t just for this string problem. Anytime you see **“choose a central point to minimize total movement / distance / absolute error”**, think **median**.

### Classic examples:

1. **Warehouse / post office placement problem**
   You have towns along a line, want to place a warehouse minimizing total distance → put it at the median town.

2. **Minimize Manhattan distance in 1D**
   For points (x-coordinates), the point minimizing sum of |x - xi| is the median.
   (In 2D Manhattan, solve separately for x and y → median(x), median(y)).

3. **Clustering tokens / making contiguous blocks**
   Exactly like the `a` and `b` problem here.

4. **Statistics**
   Median is more robust than mean when minimizing “L1 error” (absolute error).

   * Mean minimizes squared error (L2).
   * Median minimizes absolute error (L1).

5. **Interview/CP trick**
   Whenever the problem says “minimize sum of absolute values of something - X”, 90% chance → answer involves **median**.

---

## 🚀 How to use this intuition

* If cost = sum of **squares** → think **mean**.
* If cost = sum of **absolute values** → think **median**.

---

👉 So in your problem, once we rewrote cost as `∑|b[i] - L|`, it immediately screamed: **“Pick L = median(b)”**.
That’s the generalizable trick you can now spot elsewhere.
