### Check if two lines intersect eac other or not
```
        ax+bx=c
        2x+3y=5
        3x+2y=5
```
1. find determinant
2. d==0 ->       (lines do not intersect, so, solution does not exist)
```
    a1  b1      ->     2    3       -> (a1*b2)-(a2*b1) = determinent
    a2  b2      ->     3    2 
```
3. d!=0 ->       (lines do intersect, so, solution does exist)
4. For finding x, do not include x part
```
    X = b1  c1   ->    3    -5
        b2  c2   ->    2    -5
    X = X/D
```
5. For finding y, do not include y part
```
    Y = a1  c1   ->    2    -5
        a2  c2   ->    3    -5
    Y = Y/D
```
6. Print X,Y

------

# ✅ **Complete Tutorial — Line Intersection (2 Linear Equations)**

We deal with equations of form:

```
a1x + b1y = c1
a2x + b2y = c2
```

Example:

```
2x + 3y = 5
3x + 2y = 5
```

---

# ⭐ Step 1 — Understand the meaning (VERY IMPORTANT)

Two lines can have **3 possibilities**:

### 1️⃣ Unique intersection → one solution

Lines meet at one point.

```
Example:
2x+3y=5
3x+2y=5
```

---

### 2️⃣ Parallel lines → no solution

They never meet.

```
2x+3y=5
4x+6y=7
```

(same slope, different intercept)

---

### 3️⃣ Coincident lines → infinite solutions

Same line.

```
2x+3y=5
4x+6y=10
```

---

👉 Codetantra questions often ask you to detect these cases.

---

# ⭐ Step 2 — Find determinant (MAIN STEP)

Compute:

```
D = a1*b2 − a2*b1
```

This decides everything.

---

## Case A — If `D ≠ 0` → unique intersection

Lines intersect at one point.

You compute x and y.

---

## Case B — If `D = 0` → check further

Now check:

```
Dx = c1*b2 − c2*b1
Dy = a1*c2 − a2*c1
```

### If Dx = 0 AND Dy = 0

```
Infinite solutions (same line)
```

### Otherwise

```
No solution (parallel lines)
```

⚠️ Your notes missed this important distinction.

---

# ⭐ Step 3 — Find intersection point (Cramer’s Rule)

When `D ≠ 0`:

---

## Formula for x

Replace x-column with constants.

```
Dx = c1*b2 − c2*b1
x = Dx / D
```

---

## Formula for y

Replace y-column with constants.

```
Dy = a1*c2 − a2*c1
y = Dy / D
```

---

# ⭐ Step 4 — Solve your example

```
2x + 3y = 5
3x + 2y = 5
```

### Determinant

```
D = (2×2) − (3×3)
D = 4 − 9 = -5
```

Since `D ≠ 0` → intersect.

---

### Find x

```
Dx = (5×2) − (5×3)
Dx = 10 − 15 = -5

x = Dx/D = (-5)/(-5) = 1
```

---

### Find y

```
Dy = (2×5) − (3×5)
Dy = 10 − 15 = -5

y = Dy/D = (-5)/(-5) = 1
```

Intersection point:

```
(1,1)
```

---

# ⭐ Step 5 — Coding Logic (Very Important for Exams)

In programming problems:

```
read a1,b1,c1,a2,b2,c2

D = a1*b2 - a2*b1
Dx = c1*b2 - c2*b1
Dy = a1*c2 - a2*c1

if D != 0
    x = Dx/D
    y = Dy/D
    print intersection
else if Dx == 0 and Dy == 0
    print infinite solutions
else
    print no solution
```

That’s the full algorithm.

---

# ⭐ Common Mistakes Students Make (avoid these)

### ❌ Using wrong signs

Determinant order matters.

```
a1*b2 − a2*b1  ✔
```

Not reversed.

---

### ❌ Ignoring infinite solution case

Exams love this trap.

---

### ❌ Replacing wrong column when finding x or y

Remember:

```
x → replace x column
y → replace y column
```

---

# ⭐ Intuition (so you actually *understand*)

Determinant measures if two lines have different slopes.

* `D ≠ 0` → slopes different → meet
* `D = 0` → slopes same → parallel or same line

Simple geometry hidden inside matrix math.

---