# Number Representation with Linear Combinations - Key Concepts

## 🎯 Core Concept:
Given a number `n`, determine if it can be represented as a linear combination of two integers `a` and `b`:

> n = a·x + b·y

Where:
- `x` and `y` are non-negative integers (counts of `a` and `b`)
- `a` and `b` are fixed values (e.g., 2020 and 2021)

---

## ✅ Technique: Integer Division and Remainder

Let:
```cpp
x = n / a
y = n % a
```
Then check:
```cpp
if (x >= y) → YES (n can be formed)
else → NO
```

### 💡 Why does this work?
Start with the original equation:
```text
n = 2020·x + 2021·y
```
Now observe:
```text
2021 = 2020 + 1
⇒ n = 2020·x + (2020+1)·y
   = 2020·(x + y) + y
```
Let `a = x + y` (total count of 2020-type blocks, before replacements)
Let `b = y` (how many are replaced with the 2021 version)

Then:
```text
n = 2020·a + b
```
So to express `n` in terms of 2020 and 2021, we check:
```cpp
int a = n / 2020;
int b = n % 2020;
```
If `a >= b`, we can represent `n` as 2020·x + 2021·y, because we can replace `b` of the 2020s with 2021s.

---

## 🧠 General Pattern to Remember
- If two numbers differ by 1 (like `a = 2020`, `b = 2021`), and you want to form `n = 2020·x + 2021·y`, 
  - Try converting all `b`s to `a`s and check if the remaining can be divided by `a`
  - Or: use `x = n / a`, `y = n % a`, then check if `x >= y`

---

## ✅ Key Takeaways for General CP Problems

1. **Integer Linear Combinations**:
   - Used in problems like: "Can we form `n` using `a` and `b`?"
   - Form: `n = a·x + b·y`, where `x, y ≥ 0`
   - Usually solved using modulo tricks, greedy approach, or number theory

2. **Greedy with Remainder**:
   - Use `x = n / a` and `y = n % a`
   - Condition: If `x ≥ y`, you can form `n`

3. **Replace expensive values with cheaper ones**:
   - Try maximizing the use of smaller number
   - Replace part of it with the bigger number if remainder matches

4. **Modulo Check Idea**:
   - Whenever a problem allows you to use `a` and `a+1` or close values, try:
     - `x = n / a`
     - `y = n % a`
     - Check if `x ≥ y`

---

## ✨ Bonus Tip:
If the difference between `a` and `b` is small (like 1), then it becomes easy to substitute one into the other with just one unit difference. These kinds of substitutions can make linear combinations feasible more easily.

---

## 📌 Example (Concept Only)
Given `n = 8081`, `a = 2020`, `b = 2021`
- `x = n / 2020 = 4`
- `y = n % 2020 = 1`
- `x = 4 >= 1 → YES`

You can replace 1 of the `2020`s with `2021`, so it becomes:
- 3·2020 + 1·2021 = 8081 ✅
