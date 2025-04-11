# 📘 Divisors – Complete Concept Notes

---

## 🔹 What is a Divisor?
A number `d` is a **divisor** of another number `n` if `n % d == 0`. This means that `n` is perfectly divisible by `d`.

**Example:**
- Divisors of 12 = {1, 2, 3, 4, 6, 12}
- Divisors of 15 = {1, 3, 5, 15}

Divisors are also sometimes referred to as **factors**.

---

## 🔹 Basic Properties of Divisors

### 1. **Total Number of Divisors (T(n))**
To find how many divisors a number `n` has, you need to:

1. Perform prime factorization:
   - Example: \( n = 60 = 2^2 \cdot 3^1 \cdot 5^1 \)
2. Use the formula:
   - \( T(n) = (a_1 + 1)(a_2 + 1)...(a_k + 1) \), where each \( a_i \) is the exponent in the prime factorization

**Explanation:**
Each exponent contributes to how many options you have to choose from (0 up to that exponent), and multiplying those choices gives the total number of divisors.

**Example:**
- For \( 60 = 2^2 \cdot 3^1 \cdot 5^1 \)
- Total divisors: \( (2+1)(1+1)(1+1) = 3 \cdot 2 \cdot 2 = 12 \)

---

### 2. **Sum of Divisors (S(n))**
This gives the sum of all positive divisors of `n`.

**Formula:**
\[ S(n) = \prod_{i=1}^{k} \left( \frac{p_i^{a_i+1} - 1}{p_i - 1} \right) \]

**Explanation:**
This comes from the geometric series sum for each prime power, as divisors include all combinations of the primes from 0 to their powers.

**Example:**
- For \( 12 = 2^2 \cdot 3^1 \):
- \( S(12) = \left(\frac{2^3 - 1}{2 - 1}\right) \cdot \left(\frac{3^2 - 1}{3 - 1}\right) = 7 \cdot 4 = 28 \)
- Divisors = {1, 2, 3, 4, 6, 12} → Sum = 28

---

### 3. **Divisors Come in Pairs**
If `d` divides `n`, then `n/d` is also a divisor.

**Example:**
- 36 → Pairs: (1,36), (2,18), (3,12), (4,9), (6,6)

**Optimization:**
To find all divisors, you only need to iterate up to \( \sqrt{n} \). For each `i` where `n % i == 0`, both `i` and `n/i` are divisors.

---

### 4. **Odd and Even Divisors**
- An **even divisor** must include the factor 2.
- An **odd divisor** is a divisor that does not include 2 as a factor (in prime factorization).

To find only odd divisors:
- Remove all powers of 2 from `n`.
- Find the divisors of the remaining number.

**Example:**
- 60 = 2^2 * 3 * 5 → Odd divisors of 60 are divisors of 15 (i.e. 1, 3, 5, 15)

---

### 5. **Perfect Squares Have Odd Number of Divisors**
This happens because one divisor pair is repeated.

**Example:**
- 36 → {1,2,3,4,6,9,12,18,36} = 9 divisors → odd count
- Pair (6,6) is repeated → counted once

---

### 6. **Power of 2 Property**
If a number is a power of 2, like 2, 4, 8, 16, 32, etc., it has no odd divisors other than 1.

**Why?**
All of its divisors will also be powers of 2, and thus even. Only 1 is odd.

**How to check if a number is a power of 2?**
- Keep dividing `n` by 2. If it becomes 1 → it’s a power of 2
- OR use: `n & (n - 1) == 0` (bit manipulation trick)

---

### 7. **How to Efficiently Get All Divisors**
```python
for i in range(1, int(sqrt(n)) + 1):
    if n % i == 0:
        divisors.add(i)
        divisors.add(n // i)
```
✅ Time complexity: `O(√n)`

---

## 🔹 Useful Tricks in Competitive Programming

### ✔ Use Cases:
- GCD/LCM optimizations
- Counting how many numbers divide a number or set
- Range-based queries on divisors
- Subarray analysis using GCD (common divisors)

### ✔ Optimization Techniques:
- **Sieve of Divisors:** Precompute number of divisors for all numbers up to N
- Use **bitmasks** for subset/divisor representation
- Use **prefix GCD** arrays for fast queries

---

## 🔹 Related Formulas

| Concept                  | Formula                                                     |
|--------------------------|-------------------------------------------------------------|
| GCD of a & b            | `gcd(a, b) = gcd(b, a % b)`                                   |
| LCM of a & b            | `lcm(a, b) = (a * b) / gcd(a, b)`                            |
| Divisors of all numbers | Modified Sieve approach (for 1 to N)                         |
| Count of odd divisors   | Remove powers of 2 from n, then count divisors of result     |
