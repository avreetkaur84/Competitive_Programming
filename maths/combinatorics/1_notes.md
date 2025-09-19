Got it 👍 Let me just drop the **full notes inline** so you don’t depend on file download. You can copy-paste this into your own `.md` file directly.

---

# Combinatorics Notes – Compositions of Integers

## 1. Core Idea
Combinatorics is the art of **counting without listing**.  
A common example is counting the number of ways to write an integer `n` as a sum of positive integers.

- When **order matters** → these are called **compositions**.  
- When **order does not matter** → these are called **partitions** (harder, not covered here).

Example for `n=4` (compositions):  
```

1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2, 3+1, 1+3, 4

```
So there are `8` compositions of `4`.

---

## 2. Recursive Definition
Define `f(n)` as the number of compositions of `n`.

- **Base case**: `f(0) = 1` (empty sum represents zero).  
- **Recursive formula**:  
```

f(n) = f(0) + f(1) + f(2) + ... + f(n-1),   for n > 0

```

Reason: if the first chosen number is `k`, the remaining sum is `n-k`, which has `f(n-k)` possibilities.

---

## 3. Closed-Form Formula (The 2^(n−1) Trick)
Instead of recursion, there is a **direct formula**:

\[
f(n) = 2^{n-1}
\]

### Why?
- Write `n` as `n` ones:  
```

1 \_ 1 \_ 1 \_ ... \_ 1

```
- There are `n-1` gaps.  
- Each gap can either:  
- have a cut (`+`) → split numbers  
- no cut → merge numbers
- So, each gap is a binary decision → total `2^(n-1)` possibilities.

Example: For `n=4`, we have 3 gaps → `2^3 = 8` compositions.

---

## 4. Alternative Proofs

### (a) Induction
- Base: `f(1) = 1 = 2^0`.  
- Assume true for all `k < n`.  
- Then:
```

f(n) = f(0) + f(1) + ... + f(n-1)
\= 1 + (2^0 + 2^1 + ... + 2^(n-2))
\= 1 + (2^(n-1) - 1)
\= 2^(n-1).

```

### (b) Generating Functions
- A single part ≥1 has generating function:  
\[
A(x) = x + x^2 + x^3 + ... = x / (1-x)
\]
- A composition = sequence of ≥1 parts:  
\[
F(x) = A(x) + A(x)^2 + A(x)^3 + ... = \frac{A(x)}{1 - A(x)}
\]
- Simplify:  
\[
F(x) = \frac{x}{1-2x} = \sum_{n \ge 1} 2^{n-1} x^n
\]
- Coefficient of `x^n` is `2^(n-1)`.

---

## 5. Extensions & Variants

- **Exactly k parts (each ≥1):**
\[
\binom{n-1}{k-1}
\]
(Choose `k-1` cuts among `n-1` gaps).

- **Exactly k parts each ≥a (a ≥1):**
Set aside `a` for each part → leftover `N = n - a*k`.  
Ways = weak composition of `N` into `k` parts:  
\[
\binom{N+k-1}{k-1} = \binom{n - ak + k - 1}{k-1}
\]

- **Weak compositions into k parts (zeros allowed):**
\[
\binom{n+k-1}{k-1}
\]

- **Parts restricted to a set S:**
- Let `A(x) = ∑ x^s (s in S)`.  
- Compositions counted by coefficient of:  
  \[
  \frac{A(x)}{1 - A(x)}
  \]

- **Distribution of number of parts (when picking a composition uniformly):**
- Each gap is an independent cut with probability `1/2`.  
- So, `(k-1)` ~ Binomial(`n-1`, 1/2).  
- Expected number of parts = `(n+1)/2`.

---

## 6. When to Use 2^(n-1)
Look for problems that reduce to:  
- "Choose any subset of `n-1` possible cut points."  
- Breaking an object into ordered chunks.  
- Binary choices per gap (cut / no cut).  

Common contest rephrasings:
- "Ways to break a stick of length n into integer pieces."  
- "Ways to insert `+` signs into a string of length n."  
- "Number of binary strings of length `n-1`."  

---

## 7. Key Takeaways
- **Compositions of n** → `2^(n-1)` ways.  
- **Exactly k parts** → `C(n-1, k-1)`.  
- Always check: does **order matter**? If no, it’s partitions (harder).  
- If you see "n-1 independent yes/no choices", think `2^(n-1)`.



## Where to use this formula

$$
f(n) = 2^{n-1}
$$

isn’t some magical number that just randomly shows up. It comes up whenever you can rephrase a problem as:

👉 **“There are $n-1$ independent yes/no (binary) choices.”**

Specifically: “Do I cut here, or do I not cut here?”

---

## 🔹 Scenarios where $2^{n-1}$ appears

### 1. **Compositions of an integer (order matters)**

* Already covered: number of ways to write $n$ as sum of positive integers.
* Example: $n=4$ → 8 ways.

---

### 2. **Breaking a stick (or rope) of length $n$**

* You have a stick of integer length $n$.
* You can cut at any of the $n-1$ positions (or not).
* Each position is an independent cut / no-cut choice.
* → $2^{n-1}$ ways.

---

### 3. **Binary strings of length $n-1$**

* Every “cut/no cut” decision can be encoded as a bit (0 = no cut, 1 = cut).
* So, number of compositions = number of binary strings of length $n-1$.
* Example: `101` ↔ cut at positions 1 and 3.

---

### 4. **Ways to insert plus signs**

* Given a string of length $n$, put `+` between digits (or not).
* Example: `"1111"` → you can form expressions like `1+1+1+1`, `11+1+1`, etc.
* Choices = $n-1$.
* → $2^{n-1}$.

---

### 5. **Splitting an array into contiguous subarrays**

* Take an array of length $n$.
* Between any two adjacent elements, either split or merge.
* Each boundary is binary choice.
* Total partitions into contiguous chunks = $2^{n-1}$.

---

### 6. **Team formation (ordered groups)**

* You have $n$ players in a line.
* Decide where to cut between them to form ordered groups (like relays).
* Same binary decision at each of $n-1$ gaps.
* → $2^{n-1}$.

---

### 7. **Path counting in a straight line**

* Walking $n$ steps forward, you can decide whether to “pause and record a checkpoint” or not at each step.
* Again, $n-1$ decisions → $2^{n-1}$.

---

## 🔹 When *not* to use $2^{n-1}$

* If **order doesn’t matter** (integer partitions instead of compositions).
* If **minimum/maximum constraints** exist (e.g., all parts ≥ 2, exactly k parts).
* If **cuts are dependent** (like symmetry or cyclic structure).

In those cases, other formulas (binomial coefficients, Catalan numbers, generating functions) take over.

---

✅ **Mental shortcut**:
Whenever you see *"divide an ordered thing of size n into parts"* or *"insert separators between n items"*, immediately think:

$$
2^{n-1}.
$$

---

Do you want me to make you a **list of CP-style practice problems** where spotting $2^{n-1}$ is the key trick?
