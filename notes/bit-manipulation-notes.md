
# 🧠 Bit Manipulation Notes for DSA & Competitive Programming

Bit manipulation is a powerful technique used to perform operations directly on binary representations of numbers. 
This is especially useful in competitive programming due to its efficiency and performance benefits.

---

## 1️⃣ Decimal to Binary Conversion

### ❓ Explanation:
Every integer is stored in binary. To convert decimal to binary manually, divide by 2 and store the remainder.

### 💻 Code (C++):
```cpp
void decimalToBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
}
```

---

## 2️⃣ Left Shift (<<) and Right Shift (>>)

### ❓ Explanation:
- Left shift (`n << k`) multiplies `n` by `2^k`.
- Right shift (`n >> k`) divides `n` by `2^k`.

### 💻 Code:
```cpp
int shiftedLeft = n << k;
int shiftedRight = n >> k;
```

> ⚠️ Right shift of negative numbers is implementation-dependent.

---

## 3️⃣ 1's Complement and 2's Complement

### ❓ Explanation:
- 1's complement flips all bits (`~n`).
- 2's complement represents negative numbers in binary. It's calculated as `~n + 1`.

### 💻 Code:
```cpp
int onesComp = ~n;
int twosComp = (~n) + 1;
```

---

## 4️⃣ Swap Two Numbers Using XOR

### ❓ Explanation:
XOR-ing two values and reversing the operation can help swap them without using extra space.

### 💻 Code:
```cpp
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

---


## 5️⃣ Bit Masking

### ❓ What is Bit Masking?

Bit masking is a technique used to **manipulate individual bits** of a number using **bitwise operators** like `AND (&)`, `OR (|)`, `XOR (^)`, `NOT (~)` along with left shifts `<<`.

A **bit mask** is simply a number that you use to isolate or modify certain bits of another number.

---

### 🧠 Why Use Bit Masking?

Bit masking allows:
- Checking if a bit is set
- Setting or clearing specific bits
- Toggling bits
- Efficient permission handling (e.g., access control)
- Working with subsets and combinatorics in DSA

---

## 🧠 `1 << cnt` vs `y << cnt`

### 🔹 `1 << cnt`
- **Meaning**: Shifts the number `1` to the left by `cnt` positions.
- **Purpose**: Used to create a **bitmask** with only the `cnt`-th bit set.
- **Effect**: Equivalent to `2^cnt`.

#### ✅ Example:
```cpp
int cnt = 3;
int res = 1 << cnt; // 1 << 3 = 8 → Binary: 00001000
```

### 🔹 `y << cnt`
- **Meaning**: Shifts the entire binary representation of y to the left by cnt positions.
- **Purpose**: Used to multiply y by 2^cnt or shift its bits left.
- **Effect**: All bits in y are shifted; trailing zeros are added.

#### ✅ Example:
```cpp
int y = 5;       // Binary: 00000101
int cnt = 2;
int res = y << cnt; // 5 << 2 = 20 → Binary: 00010100
```

| Expression | Purpose              | Result                         |
| ---------- | -------------------- | ------------------------------ |
| `1 << cnt` | Create a bitmask     | Single bit set at `cnt`-th pos |
| `y << cnt` | Shift value `y` left | Multiply `y` by `2^cnt`        |


---

## 6️⃣ Check if i-th Bit is Set

### ❓ Explanation:
Use bitwise AND to check if the i-th bit is 1.

### 💻 Code:
```cpp
bool isSet = (n & (1 << i)) != 0;
```

---

## 7️⃣ Set i-th Bit

### ❓ Explanation:
Use bitwise OR to set the i-th bit to 1.

### 💻 Code:
```cpp
n = n | (1 << i);
```

---

## 8️⃣ Clear i-th Bit

### ❓ Explanation:
Use bitwise AND with the NOT of bitmask to clear the i-th bit.

### 💻 Code:
```cpp
n = n & ~(1 << i);
```

---

## 9️⃣ Toggle i-th Bit

### ❓ Explanation:
Use XOR to toggle the i-th bit (flip 0 to 1 or 1 to 0).

### 💻 Code:
```cpp
n = n ^ (1 << i);
```

---

## 🔟 Check if Number is Even or Odd

### ❓ Explanation:
If the least significant bit is 1, number is odd; else even.

### 💻 Code:
```cpp
if (n & 1) {
    cout << "Odd";
} else {
    cout << "Even";
}
```

---

## 🔥 BONUS: Useful Bit Tricks

### ✅ Count Number of Set Bits (Brian Kernighan's Algorithm)
```cpp
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
```

### ✅ Power of Two Check
```cpp
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

### ✅ Isolate Rightmost Set Bit
```cpp
int rsb = n & (-n);
```

### ✅ Turn Off Rightmost Set Bit
```cpp
n = n & (n - 1);
```

### ✅ Turn On Rightmost 0 Bit
```cpp
n = n | (n + 1);
```

---

## 📌 Tips for CP

- Use `__builtin_popcount(n)` in GCC/Clang to count set bits in `int`.
- Apply bitmasking to solve subset/combinatorial problems.
- Efficient for toggling, flipping, checking individual bits.
- Common in problems involving constraints like "up to 2^N subsets", permissions, toggles, etc.

---

Happy Coding! 🚀  
Stay consistent with practicing and applying these tricks!
