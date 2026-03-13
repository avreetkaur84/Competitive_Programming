# 1. What is KMP? (Definition)

**KMP (Knuth–Morris–Pratt)** is a **pattern searching algorithm** used to find occurrences of a **pattern string P** in a **text string T** efficiently.

It was developed by

* Donald Knuth
* James H. Morris
* Vaughan Pratt

### Purpose

Avoid **rechecking characters that we already know match**.

### Time Complexity

* **O(n + m)**
  Where:
* n = length of text
* m = length of pattern

---

# 2. Problem with Naive String Matching

Suppose:

Text

```
ABABDABACDABABCABAB
```

Pattern

```
ABABCABAB
```

Naive algorithm:

1. Compare pattern from start
2. If mismatch occurs → shift pattern by **1**
3. Start comparison again

Worst case:

```
Text:    AAAAAAAAAAAA
Pattern: AAAAAB
```

This causes repeated comparisons.

Time complexity becomes:

```
O(n * m)
```

---

# 3. Core Idea of KMP

Instead of restarting comparison from the beginning of pattern, KMP **uses information from previous matches**.

It builds a table called:

### LPS Array

**Longest Prefix which is also a Suffix**

For every position in the pattern, LPS tells:

> "If mismatch occurs here, where should we continue in the pattern?"

So we **skip useless comparisons**.

---

# 4. What is LPS (Longest Prefix Suffix)?

Definition:

For each index **i** in the pattern:

```
LPS[i] = length of the longest proper prefix
         which is also a suffix
         for substring pattern[0..i]
```

**Proper prefix** means prefix that is **not the whole string**.

---

# 5. Example of LPS

Pattern:

```
ABABCABAB
```

Step-by-step LPS:

| Index | Pattern | Prefix | Suffix | LPS |
| ----- | ------- | ------ | ------ | --- |
| 0     | A       | -      | -      | 0   |
| 1     | B       | A      | B      | 0   |
| 2     | A       | A      | A      | 1   |
| 3     | B       | AB     | AB     | 2   |
| 4     | C       | ABAB   | BABC   | 0   |
| 5     | A       | A      | A      | 1   |
| 6     | B       | AB     | AB     | 2   |
| 7     | A       | ABA    | ABA    | 3   |
| 8     | B       | ABAB   | ABAB   | 4   |

Final LPS:

```
[0,0,1,2,0,1,2,3,4]
```

---

# 6. How the Matching Works

Text:

```
ABABDABACDABABCABAB
```

Pattern:

```
ABABCABAB
```

Process:

1. Compare characters
2. If match → move both pointers
3. If mismatch → use **LPS value**
4. Do **NOT restart from beginning**

Example:

```
Mismatch at j

j = lps[j-1]
```

This shifts the pattern intelligently.

---

# 7. KMP Algorithm Steps

### Step 1

Build **LPS array**

Time:

```
O(m)
```

---

### Step 2

Start comparing text and pattern.

Pointers:

```
i → text
j → pattern
```

Rules:

1️⃣ If match

```
i++
j++
```

2️⃣ If mismatch and j ≠ 0

```
j = lps[j-1]
```

3️⃣ If mismatch and j = 0

```
i++
```

4️⃣ If j == pattern length

Pattern found.

---

# 8. Visualization

Text

```
ABABDABACDABABCABAB
```

Pattern

```
ABABCABAB
```

At mismatch:

Instead of shifting by **1**, KMP shifts based on **prefix-suffix knowledge**.

That’s why it stays **linear time**.

---

# 9. Time Complexity

| Step      | Complexity |
| --------- | ---------- |
| Build LPS | O(m)       |
| Search    | O(n)       |

Total:

```
O(n + m)
```

---

# 10. Space Complexity

```
O(m)
```

For LPS array.

---

# 11. Why KMP is Efficient

Because:

> Characters that were already matched will never be compared again.

This avoids repeated work.

---

# 12. Advantages

✔ Linear time
✔ Efficient for large texts
✔ No backtracking in text

---

# 13. Disadvantages

❌ Extra preprocessing (LPS array)
❌ Harder to understand than naive algorithm

---

# 14. Common Viva Questions

### 1️⃣ What does KMP stand for?

Knuth–Morris–Pratt.

---

### 2️⃣ What problem does it solve?

Efficient **pattern searching in a string**.

---

### 3️⃣ Time complexity?

```
O(n + m)
```

---

### 4️⃣ What is LPS?

Longest prefix which is also suffix.

---

### 5️⃣ Why is KMP better than naive?

Because it **avoids redundant comparisons**.

---

### 6️⃣ Space complexity?

```
O(m)
```

---

# 15. Real Applications

KMP is used in:

* **Text editors**
* **Search engines**
* **DNA sequence matching**
* **Plagiarism detection**
* **Compiler design**

---

# 16. Short Viva Answer (30-second version)

If examiner says **“Explain KMP in short”**:

> KMP is a pattern matching algorithm that searches a pattern in a text in **O(n + m)** time. It avoids unnecessary comparisons by preprocessing the pattern and building an **LPS array**, which stores the longest prefix that is also a suffix. When a mismatch occurs, the algorithm uses the LPS value to shift the pattern without rechecking characters that already matched.

---