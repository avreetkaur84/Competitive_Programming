# 📌 Choices Concept in Combinatorics

## 🧠 General Rule:
If an element has **`x` independent choices**, and there are **`cnt`** such elements, then the total number of combinations is:

```
Total combinations = x^cnt
```

---

## ✅ Conditions:
- Choices for **each element are independent** (i.e., selecting one does **not** affect the others).
- Each element has the **same number of choices**.

---

## 🧪 Examples:

### 1. Binary Choices (Include/Exclude)
- **Example:** Subsets of an array
- Each element can be:
  - Included
  - Not included
- **Total subsets =** `2^n` (where `n` = number of elements)

### 2. Three Choices (e.g., Wear a T-shirt)
- **Choices:** Wear as-is, Fold, Don’t wear
- **For 3 shirts:** `3^3 = 27` combinations

### 3. Application in Problem:
- In an array, each `0` can be:
  - Kept (doesn't affect sum)
  - Removed (still doesn’t affect sum)
- So for `z_cnt` zeros: `2^z_cnt`
- Multiply with `o_cnt` (ways to remove one `1`)  
  → **Total =** `2^z_cnt × o_cnt`

---

## 💡 Use this when:
- You're counting all possible configurations/combinations.
- The elements are **independent** and have **fixed number of options** each.

