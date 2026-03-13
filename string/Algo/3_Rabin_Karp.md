# 1. What is Rabin–Karp? (Definition)

**Rabin–Karp** is a **string matching algorithm** that finds a pattern in a text using **hash values**.

Instead of comparing characters one by one every time, it:

1. Computes a **hash of the pattern**
2. Computes **hashes of text substrings**
3. Compares the hashes first
4. Only if hashes match → verify characters

Think of it like checking **fingerprints before checking the whole person**.

---

# 2. Problem It Solves

Find a **pattern P** inside a **text T**.

Example:

Text

```
ABCCDDAEFG
```

Pattern

```
CDD
```

Goal → find where **CDD** occurs in the text.

---

# 3. Core Idea

Instead of comparing the pattern with every substring directly, Rabin–Karp:

1️⃣ Converts strings into **numeric hash values**

2️⃣ Compares **hash(pattern)** with **hash(text window)**

3️⃣ If equal → verify actual characters

This dramatically reduces comparisons.

---

# 4. Rolling Hash (Most Important Concept)

This is the heart of Rabin–Karp.

When sliding the pattern window over the text:

Instead of recomputing hash from scratch, we **update the hash efficiently**.

Example:

Text

```
ABCDE
```

Pattern length = 3

Windows:

```
ABC
BCD
CDE
```

Instead of computing hash again:

```
hash(BCD) = remove 'A' from hash(ABC) + add 'D'
```

This is called **Rolling Hash**.

---

# 5. Hash Function

Typical polynomial hash formula:

```
hash(s) = s[0]*d^(m-1) + s[1]*d^(m-2) + ... + s[m-1]
```

Where:

* **d** = number of characters in alphabet
* **m** = pattern length

Usually:

```
d = 256
```

Then modulo is applied:

```
hash = (hash % q)
```

where **q** is a prime number.

---

# 6. Example

Text

```
ABCCDDAEFG
```

Pattern

```
CDD
```

Pattern hash:

```
hash("CDD")
```

Now compute hash of first window:

```
ABC
```

Slide window:

```
BCD
CCD
CDD  ← hash match
```

Now verify characters.

Pattern found.

---

# 7. Rabin–Karp Algorithm Steps

### Step 1

Compute hash of pattern.

```
hash_p
```

---

### Step 2

Compute hash of first window of text.

```
hash_t
```

---

### Step 3

Compare hashes.

If

```
hash_p == hash_t
```

Then check characters.

---

### Step 4

Slide window using rolling hash.

Update:

```
hash_t =
(d*(hash_t - text[i]*h) + text[i+m]) % q
```

Where:

```
h = d^(m-1) % q
```

---

# 8. Time Complexity

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(n + m)   |
| Average | O(n + m)   |
| Worst   | O(n*m)     |

Worst case happens due to **hash collisions**.

---

# 9. Space Complexity

```
O(1)
```

Only few variables needed.

---

# 10. What is Hash Collision?

When:

```
hash(A) = hash(B)
```

but

```
A ≠ B
```

Example:

```
"abc" and "bca"
```

might produce the same hash.

So Rabin–Karp **verifies characters after hash match**.

---

# 11. Advantages

✔ Faster when searching **multiple patterns**
✔ Efficient using hashing
✔ Good for plagiarism detection

---

# 12. Disadvantages

❌ Hash collisions possible
❌ Worst-case slower than **Knuth–Morris–Pratt Algorithm**

---

# 13. Rabin–Karp vs KMP (Professors love this)

| Feature           | Rabin–Karp | KMP           |
| ----------------- | ---------- | ------------- |
| Technique         | Hashing    | Prefix-suffix |
| Preprocessing     | Hash       | LPS array     |
| Best case         | O(n+m)     | O(n+m)        |
| Worst case        | O(n*m)     | O(n+m)        |
| Multiple patterns | Very good  | Not ideal     |

---

# 14. Real Applications

Rabin–Karp is used in:

* **Plagiarism detection**
* **Virus signature detection**
* **DNA sequence matching**
* **Large text searching**
* File comparison tools

---

# 15. Short Viva Answer (20–30 sec)

If examiner asks **“Explain Rabin–Karp.”**

You say:

> Rabin–Karp is a string matching algorithm that uses hashing to find a pattern in a text. It computes the hash of the pattern and compares it with the hash of text substrings using a rolling hash technique. If the hash values match, the algorithm verifies the characters. Its average time complexity is O(n + m), but the worst case can be O(n*m) due to hash collisions.

---

# 16. Common Viva Questions

**1️⃣ Who invented Rabin–Karp?**

Michael O. Rabin and
Richard M. Karp.

---

**2️⃣ What is rolling hash?**

Efficiently updating the hash when sliding the window.

---

**3️⃣ Why use modulo?**

To keep hash values small and avoid overflow.

---

**4️⃣ What causes worst case?**

Hash collisions.

---

**5️⃣ Which is better: KMP or Rabin–Karp?**

* **Single pattern** → KMP
* **Multiple patterns** → Rabin–Karp

---