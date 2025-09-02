## 🚀 Step 1: Strengthen Basics (The Ground Level)

Before fancy tricks, get rock-solid on the fundamentals:

* **Divisibility rules** (gcd, lcm, prime factorization)
* **Modulo arithmetic basics** (remainders, congruences, properties like $(a+b) \mod m$)
* **Euclidean algorithm** for gcd
* **Fast exponentiation** (binary exponentiation)

📖 Resources:

* CP-Algorithms (cp-algorithms.com) → the "Number Theory" section
* Book: *Competitive Programmer’s Handbook* by Antti Laaksonen (free PDF)

💡 How to practice:

* Solve 10–15 problems only about gcd/lcm/modulo from Codeforces / CSES.
* Don’t rush. Focus on *why* each solution works.

---

## 🚀 Step 2: Modular World (Where the “≡” Magic Lives)

Here’s where tricks like the one you just saw live. Key topics:

* Congruences
* Modular inverses
* Linear congruences
* Fermat’s Little Theorem
* Chinese Remainder Theorem (CRT)

📖 Resources:

* *Number Theory – Niven & Zuckerman* (classic)
* *CP-Algorithms* modular arithmetic section
* YouTube: "Number Theory for Competitive Programming" playlist (by William Lin, Errichto, or SecondThread)

💡 Practice:

* Problems where you must align remainders (like this Codeforces one).
* Hackerrank / Codeforces tags: `math`, `number theory`.

---

## 🚀 Step 3: Tricks Become Intuition

After solving \~50+ problems, you’ll start to *see* patterns:

* "Oh, I need all elements divisible by some g" → try to think in terms of congruences.
* "This expression repeats every m steps" → try modulo reasoning.
* "I need to balance + and -" → replace something with its congruence.

Basically:
👉 The “magical steps” in editorials will stop looking magical and start looking *inevitable*.

---

## 🚀 Step 4: Train With Contests

* Stick to Codeforces Div2 B, C math problems.
* After trying, always read editorials.
* Try to re-derive the trick on your own (don’t just copy).

For example:
Today you saw:

$$
a[i] + k \cdot c[i] \equiv a[i] - c[i] \pmod{k+1}
$$

At first it looked magic. Next time you’ll **expect** this substitution when you see `k+1`.

---

## 🧠 The Mindset

* Don’t be afraid when you feel stuck → it’s normal.
* Celebrate the “oh my gggg” moments — that’s growth.
* Force yourself to **re-derive** instead of memorizing.

---

⚡ Pro Tip: Start a “Math CP Notebook” 📓

* Write each new trick you learn (like today’s `k ≡ -1 mod (k+1)` substitution).
* For each trick, add a small example.
* Review your notebook before contests → your brain will start firing these ideas automatically.

---