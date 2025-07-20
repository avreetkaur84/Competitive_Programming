
# XOR Properties for DSA & Competitive Programming 🚀

XOR (Exclusive OR) is a fundamental bitwise operation with surprisingly powerful properties. 
Here's a compact yet detailed guide with explanations and examples to help you conquer XOR in DSA and CP.

---

## 🔹 Property 1: XOR of a number with itself is 0

**Statement:**  
```
a ^ a = 0
```

**Explanation:**  
Each bit of a number XORed with itself gives 0.  
For example, `5 ^ 5 = 0` → binary: `101 ^ 101 = 000`.

**Use Case:**  
Canceling out duplicates in arrays.

---

## 🔹 Property 2: XOR of a number with 0 is the number itself

**Statement:**  
```
a ^ 0 = a
```

**Explanation:**  
XOR with 0 leaves the number unchanged.  
Example: `12 ^ 0 = 12`

**Use Case:**  
Initialize XOR computations. Handy when reducing values.

---

## 🔹 Property 3: XOR is commutative and associative

**Statements:**  
```
a ^ b = b ^ a  
(a ^ b) ^ c = a ^ (b ^ c)
```

**Explanation:**  
You can rearrange and group terms however you like.

**Use Case:**  
When reducing an array:  
```cpp
int res = 0;
for(int i = 0; i < n; i++) res ^= arr[i];
```

---

## 🔹 Property 4: XOR can be used to find the missing/single element

**Example Problem:**  
Every number appears twice except one, find it.  
```cpp
int res = 0;
for(int i : nums) res ^= i;
return res;
```

**Why it works:**  
All duplicates cancel each other, leaving the odd one out.

```
❌ BUT! If you have:
    - Multiple numbers appearing once
    - Or some elements more than twice
    - Or you want to remove all duplicates and keep distinct values
→ XOR won’t help you.
You’ll need a set, unordered_map, or sorting + two-pointer approach.
```
---

## 🔹 Property 5: XOR of numbers from 1 to N follows a pattern

**Pattern:**  
```text
n % 4 == 0 → result = n  
n % 4 == 1 → result = 1  
n % 4 == 2 → result = n + 1  
n % 4 == 3 → result = 0
```

**Function:**  
```cpp
int xorUpto(int n) {
    if(n % 4 == 0) return n;
    else if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n + 1;
    return 0;
}
```

**To compute XOR from L to R:**  
```cpp
xorUpto(R) ^ xorUpto(L - 1);
```

---

## 🔹 Property 6: Swap two numbers using XOR (without a temp variable)

```cpp
a = a ^ b;
b = a ^ b; // becomes original a
a = a ^ b; // becomes original b
```

**Caution:**  
Only works if `a` and `b` refer to distinct memory locations.

---

## 🔹 Property 7: Set Bit Count Trick (XOR with powers of two)

Use XOR with `(1 << i)` to toggle the ith bit of a number.

**Example:**  
```cpp
int a = 10; // 1010
a = a ^ (1 << 1); // Toggles 2nd bit → becomes 1000
```

---

## 🔹 Applications in CP / DSA:

- Finding missing/single numbers in arrays
- Detecting parity (even/odd)
- Efficient range XORs
- XOR-based prefix tricks
- Gray code generation
- Graph coloring
- Cryptography & OS-level optimizations

---

🔥 **TL;DR**: XOR is a magician — it cancels, finds, swaps, and compresses! Keep this cheat sheet handy and decode the wizardry during contests and coding interviews.

Stay curious. Keep XOR-ing. 😄
