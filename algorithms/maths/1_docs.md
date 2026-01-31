Topics:
- Euclid Algorithm 
- GCD,LCM
- Sieve ,Segmented Sieve
- Combinatorics,Inclusion Exclusion
- Line Intersection


# ⏱️ Time Complexity (Theory)

---

## 1️⃣ Sieve of Eratosthenes

### What it does

Finds all prime numbers up to `n` by marking multiples of primes.

---

### Time Complexity

[
\boxed{O(n \log \log n)}
]

### Why? (EXAM-FRIENDLY EXPLANATION)

* Each prime `p` marks multiples:
  [
  \frac{n}{p}
  ]
* Total operations:
  [
  n \left( \frac{1}{2} + \frac{1}{3} + \frac{1}{5} + \dots \right)
  ]
* Sum over reciprocals of primes ≈ `log log n`

📌 Hence:
[
O(n \log \log n)
]

---

### Space Complexity

[
O(n)
]

---

## 2️⃣ Segmented Sieve

### What it does

Finds primes in a range `[L, R]` using primes up to `√R`.

---

### Time Complexity

Two parts:

#### 1. Sieve up to √R

[
O(\sqrt{R} \log \log \sqrt{R})
]

#### 2. Marking multiples in `[L, R]`

[
O((R - L + 1)\log \log R)
]

---

### Total Time Complexity

[
\boxed{O((R - L + 1)\log \log R)}
]

(√R part is dominated in large ranges)

---

### Space Complexity

[
O(\sqrt{R} + (R-L+1))
]

---

## 3️⃣ Euclidean Algorithm (GCD)

### What it does

Computes `gcd(a, b)` using repeated modulo operations.

---

### Time Complexity

[
\boxed{O(\log(\min(a,b)))}
]

---

### Why? (Very Important)

* Each step reduces the problem size significantly
* Worst case happens when numbers are **consecutive Fibonacci numbers**
* Number of steps ≤ number of digits

📌 Hence logarithmic time.

---

### Space Complexity

* Iterative: `O(1)`
* Recursive: `O(log n)` (call stack)

---

## 🔑 One-Line Exam Answers (Memorize These)

* **Sieve of Eratosthenes** runs in `O(n log log n)` time.
* **Segmented sieve** runs in `O((R−L+1) log log R)` time.
* **Euclidean algorithm** runs in `O(log n)` time.

---


