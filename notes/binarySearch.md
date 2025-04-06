# **BINARY SEARCH**

## 📌 **Lower Bound**

### **Definition**  
The lower bound of `x` in a sorted array is the **first index** where the element is **greater than or equal to `x`**.

---

### **Use-case**   
- Find the **position to insert `x`** without breaking the order  
- Check **how many elements are less than `x`**

---

### **When to use**
- Finding **first occurrence of `x`** or the **next greater element** if `x` doesn’t exist  
- Problems involving **count of elements**, **range queries**, or **insertion position**  
- When the array has **duplicate values** and you want the **first valid index**

---

### 🧠 Quick Binary Search Condition 

```cpp
if(arr[mid] >= x) {
    idx = mid;
    high = mid - 1;
} else {
    low = mid + 1;
}
```

---

### 🔹 STL Function
```cpp
int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
```
- Returns iterator to the **first element ≥ x**
- Time Complexity: **O(log n)**

---

## 📌 **Upper Bound**

### **Definition**  
The upper bound of `x` in a sorted array is the **first index** where the element is **strictly greater than `x`**.

---

### **Use-case**   
- Find the **next higher element than `x`**
- Useful in problems that involve **exclusive ranges** or **removing duplicates**

---

### **When to use**
- Finding **count of elements equal to `x`** using: `upper_bound - lower_bound`
- In problems involving **strictly greater elements** or **partitioning data**

---

### 🧠 Quick Binary Search Condition 

```cpp
if(arr[mid] > x) {
    idx = mid;
    high = mid - 1;
} else {
    low = mid + 1;
}
```

---

### 🔹 STL Function
```cpp
int idx = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
```
- Returns iterator to the **first element > x**
- Time Complexity: **O(log n)**

---

## 📌 **Floor**

### **Definition**  
The floor of `x` in a sorted array is the **largest element that is less than or equal to `x`**.

---

### **Use-case**   
- Find the **greatest element ≤ x** (especially if `x` may not exist in the array)
- Useful when you're looking for **closest smaller or equal value**

---

### 🧠 Quick Binary Search Condition (for Floor)

```cpp
if(arr[mid] <= x) {
    idx = mid;
    low = mid + 1;
} else {
    high = mid - 1;
}
```

---

## 📌 **Ceil**

### **Definition**  
The ceil of `x` in a sorted array is the **smallest element that is greater than or equal to `x`** — which is the same as **Lower Bound**.

---
