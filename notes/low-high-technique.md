### ✅ Valid Parenthesis String using `low-high` Technique

---

#### 💡 Core Intuition

We **track the range** of **possible open brackets** using two variables:

* `low`: **Minimum** number of unclosed `'('` (if every `'*'` turns into `')'`)
* `high`: **Maximum** number of unclosed `'('` (if every `'*'` turns into `'('`)

Why a range?

Because `'*'` can be anything: `'('`, `')'`, or empty — so we explore all possible consequences **without actually branching**. Instead of using stacks or backtracking, we *simulate all possibilities simultaneously* via a range.

---

#### 🔁 Per Character Logic

For each character in the string:

* `'('`:

  * `low++` → definitely more opens
  * `high++` → definitely more opens

* `')'`:

  * `low--` → try closing an open
  * `high--` → must close one open

* `'*'`:

  * Can be `'('`: `high++`
  * Can be `')'`: `low--`
  * Can be empty: `low` and `high` stay same

But:

* `low` must not go below `0`
  → If it does, we reset it: `low = max(low, 0)`

---

#### ❗ Termination Conditions

At any step:

* If `high < 0`:
  → Too many `')'` to be possibly valid — return `False`

At the end:

* If `low == 0`:
  → All `'('` can be closed — return `True`
* If `low > 0`:
  → Too many `'('` left unclosed — return `False`

---

#### 🧠 Thought Process Behind This Trick

* Instead of using a stack or backtracking, we imagine **all possible bracket states** that `'*'` can form.
* By maintaining a **range** of valid open brackets, we keep things efficient and scalable.
* It’s kind of like saying:

  * "At worst, we have this many opens"
  * "At best, we have that many opens"
* If either goes out of bounds (especially `high < 0`), then we're doomed.

---

#### ✅ Dry Run Example 1: `(((*)))`

Step by step:

| i | char | low | high |
| - | ---- | --- | ---- |
| 0 | `(`  | 1   | 1    |
| 1 | `(`  | 2   | 2    |
| 2 | `(`  | 3   | 3    |
| 3 | `*`  | 2   | 4    |
| 4 | `)`  | 1   | 3    |
| 5 | `)`  | 0   | 2    |
| 6 | `)`  | 0   | 1    |

✅ Final check: `low == 0`, so it's **valid**

---

#### ✅ Dry Run Example 2: `((**())*`

Step by step:

| i | char | low | high |
| - | ---- | --- | ---- |
| 0 | `(`  | 1   | 1    |
| 1 | `(`  | 2   | 2    |
| 2 | `*`  | 1   | 3    |
| 3 | `*`  | 0   | 4    |
| 4 | `(`  | 1   | 5    |
| 5 | `)`  | 0   | 4    |
| 6 | `)`  | 0   | 3    |
| 7 | `*`  | 0   | 4    |

✅ Final check: `low == 0`, so it's **valid**

---

#### 🧪 Edge Case: Why `low` Must Stay ≥ 0?

If `low` ever becomes negative:

* It means we’re trying to **close more brackets** than we could possibly open
* But even if `'*'` turns into `'('`, there weren't enough `'('` before

So we just:

```python
low = max(low, 0)
```

---

#### 🚫 Why `high < 0` is a Red Flag?

If `high` drops below `0`, then:

* Even in the **best-case scenario** (where every `'*'` was `'('`), we have **more `')'` than open `(`**
* Impossible to fix this
* Hence, return `False`

---

#### ✅ Summary

* `low` = Min possible open `(` count
* `high` = Max possible open `(` count
* `low` can't go below 0
* If `high` < 0 at any point → invalid
* At the end, `low == 0` → valid
