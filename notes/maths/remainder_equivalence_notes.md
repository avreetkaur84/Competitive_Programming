
# Remainder Equivalence & Canonical Form in Modular Problems

## 1. Problem Context
Sometimes, in contest problems, you're given operations like:
- `x → x + k`
- `x → |x - k|`

and asked if you can transform one multiset into another.

Key observation: **These operations strongly preserve modular properties**.

---

## 2. Modular Invariance
### Case 1: Adding/Subtracting `k`
If you take `x % k = r`, then:
```
(x + k) % k = r
(x - k) % k = r  (for x ≥ k)
```
So the remainder stays the same.

### Case 2: `|x - k|` when `x < k`
If `x < k`, remainder is `r = x`.
```
|x - k| = k - x
new remainder = k - r
```
**Boom:** This flips the remainder across `k/2`.

---

## 3. Remainder Graph
Think of remainders from `0` to `k-1`:
```
0    1    2   ...   k/2   ...  k-2   k-1
```
Operation `|x - k|` lets you instantly jump:
```
r  →  k - r
```
Example for `k = 7`:
```
0 ↔ 0
1 ↔ 6
2 ↔ 5
3 ↔ 4
```
These form **equivalence classes**: {0}, {1, 6}, {2, 5}, {3, 4}.

---

## 4. Canonical Form
An **equivalence class** is a set of remainders you can freely reach from each other.

We can label each class with its **canonical form**:
```
canonical(r) = min(r, k - r)
```
- `{1, 6}` → 1
- `{2, 5}` → 2
- `{3, 4}` → 3
- `{0}` → 0

So any number is reduced to a "standard" label for its reachable class.

---

## 5. Algorithm to Check Equality of Two Multisets
1. For each element in both sets:
    - Compute `m = x % k`
    - Replace `x` with `min(m, k - m)`
2. Sort both sets.
3. Compare.
    - If equal → "YES"
    - Else → "NO"

---

## 6. Why This Works
- Adding/subtracting `k` keeps you in the same remainder class.
- Flipping remainder with `|x - k|` swaps between `r` and `k - r`.
- Once you collapse both sets into **canonical remainders**, if they match, transformation is possible.

---

## 7. Common Pitfalls
- Forgetting that when `x ≥ k`, `|x - k|` might not flip remainder (depends on whether subtraction keeps number positive).
- Missing the special cases:
    - `r = 0` → stays `0`
    - If `k` is even, `r = k/2` → stays `k/2`

---

**Pro Tip for Contests:**  
When you see operations of the form "add k" or "subtract k" combined with something that flips a value under `k`, **immediately think in terms of modular equivalence classes** and find a canonical form.

---
