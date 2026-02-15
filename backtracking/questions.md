# Interview-level Backtracking Mastery Plan (2 weeks)

No chaos. No random practice. Structured attack.

---

## Phase 1 — Build ONE template (Day 1–2)

Your only goal:

```
understand the backtracking template deeply
```

Every problem must fit:

```
state
choices
constraints
goal
```

### Solve slowly (no editorial first):

1. **Permutations**
2. **Subsets**
3. **Combination Sum**

From LeetCode.

Not for answers.
For pattern recognition.

Ask after each:

```
What was state?
What was choice?
What did I undo?
```

If you don’t do this → you repeat old cycle.

---

## Phase 2 — Add constraints (Day 3–5)

Now problems where choices are restricted.

1. Word Search (your current problem)
2. Palindrome Partitioning
3. Combination Sum II

Here you learn:

```
pruning
visited tracking
constraint checking
```

This is where backtracking becomes powerful.

---

## Phase 3 — Classic interview monsters (Day 6–8)

Now harder constraint problems.

1. N-Queens
2. Generate Parentheses
3. Sudoku Solver (optional)

Now you’ll see same template everywhere.

---

## Phase 4 — Retention phase (MOST IMPORTANT)

After 1 week:

* redo ALL problems without looking
* if stuck → think 20 min minimum
* only hints, not full solution

This prevents forgetting.

This is the step you skipped earlier.

---

# The only backtracking template you need

Burn this into memory:

```
void solve(state):
    if goal reached:
        record answer
        return

    for each choice:
        if choice valid:
            make choice
            solve(new state)
            undo choice
```

Every backtracking problem is just:

```
what is state?
what is choice?
what is valid?
what is goal?
```

Nothing else.

---