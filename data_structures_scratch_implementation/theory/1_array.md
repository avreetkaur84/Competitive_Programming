# 📚 Arrays - Complete Notes for DSA, CP, and Interviews

---

## 🔸 What is an Array?

An **array** is a data structure that stores elements of the same type in **contiguous memory locations**. It allows **random access** using indexing.

```cpp
int arr[5] = {1, 2, 3, 4, 5};  // Array of 5 integers
````

---

## 🔸 Key Properties of Arrays

| Property          | Description                                                          |
| ----------------- | -------------------------------------------------------------------- |
| Fixed Size        | Size is defined at the time of declaration (in static arrays).       |
| Contiguous Memory | All elements are stored back-to-back in memory.                      |
| Indexing          | Starts at `0`. Direct access to any index in O(1) time.              |
| Homogeneous       | All elements are of the same data type.                              |
| Memory Allocation | - Static arrays use stack memory<br>- Dynamic arrays use heap memory |

---

## 🔸 Memory: Stack vs Heap

| Memory | Used For               | Characteristics                                                 |
| ------ | ---------------------- | --------------------------------------------------------------- |
| Stack  | Static arrays          | Fast access, limited size (\~1MB), auto deallocated             |
| Heap   | Dynamic arrays (`new`) | Manual allocation, large memory, must be explicitly deallocated |

> ✅ Dynamic arrays (like vectors) are preferred for flexible memory usage in CP and interviews.

---

## 🔸 Time Complexities

| Operation          | Time Complexity |
| ------------------ | --------------- |
| Access by Index    | O(1)            |
| Insertion at End   | O(1) (if space) |
| Insertion at Index | O(n)            |
| Deletion at Index  | O(n)            |
| Search (Linear)    | O(n)            |
| Search (Binary)    | O(log n)        |

---

## 🔸 Must-Know Patterns

* ✅ **Kadane’s Algorithm** – Max subarray sum
* ✅ **Sliding Window** – Max/min/fixed sum subarrays
* ✅ **Prefix Sum** – Range queries, subarrays with target sum
* ✅ **Two Pointer Technique** – Sorted arrays, unique pairs, duplicates
* ✅ **Binary Search Variants** – Peak element, rotated array, lower/upper bounds
* ✅ **In-place Operations** – Move zeroes, reverse array, rotate array

---

## 🔸 Popular Interview Questions

| Topic            | Example Problem                                   |
| ---------------- | ------------------------------------------------- |
| Prefix Sum       | Subarray Sum Equals K                             |
| Sliding Window   | Max Sum Subarray of Size K                        |
| Two Pointers     | Remove Duplicates, Pair with Given Sum            |
| Sorting          | Sort 0s, 1s, 2s (Dutch National Flag Problem)     |
| Binary Search    | First/Last Occurrence, Peak Element               |
| Hashing          | Count Frequencies, Longest Subarray with Zero Sum |
| Greedy           | Max Profit (Buy/Sell Stocks)                      |
| Bit Manipulation | XOR for Missing/Duplicated Numbers                |

---

## 🔸 Advanced CP Tricks with Arrays

* **Modulo Arithmetic in Arrays**

  * `(a + b) % mod = ((a % mod) + (b % mod)) % mod`
* **Difference Array**

  * Efficient range updates in O(1)
* **Binary Search on Answer**

  * Used in problems like “Minimum capacity to ship packages”
* **Precomputation**

  * Factorials, Prefix Sums, Bit counts, etc.

---

## 🔸 Array vs Vector (C++)

| Feature     | Array (Static)  | Vector (Dynamic)     |
| ----------- | --------------- | -------------------- |
| Memory      | Stack           | Heap                 |
| Size        | Fixed           | Resizeable           |
| STL Support | No              | Yes (many functions) |
| Performance | Slightly faster | Slightly slower      |
| Use in CP   | Less preferred  | More preferred       |

---

## 🔸 Limitations of Arrays

* Fixed size in static arrays
* Insertion and deletion from middle is expensive
* Not ideal for frequent resizing (unless dynamic or using `vector`)
* Linear search for unsorted arrays is inefficient

---

## 🔸 Extra Interview Insights

* **Why arrays are cache-friendly?**
  Contiguous memory → better CPU cache locality → faster access.

* **Why not use arrays for dynamic data?**
  Reallocating arrays is expensive (O(n)). Linked lists or dynamic containers like `vector` handle this better.

* **How do `vector`/dynamic arrays work internally?**
  Double the size when full, copy old elements, then add new.

---

## 🔸 Practice Problems to Master Arrays

1. Move Zeroes to End (In-place)
2. Max Sum Subarray (Kadane’s)
3. Subarray Sum Equals K (Prefix + HashMap)
4. Rotate Array (with and without extra space)
5. Peak Element (Binary Search variant)
6. Find Duplicate using Floyd's Cycle
7. Set Matrix Zeroes (in-place)
8. Maximum Product Subarray
9. Merge Sorted Arrays
10. Longest Consecutive Sequence

---

## 🔸 Pro Tips for Arrays

* Always check bounds before accessing `arr[i]`
* In coding rounds, prefer `vector<int>` over raw arrays
* For huge inputs, use `ios::sync_with_stdio(false); cin.tie(0);` for faster I/O

---

🧠 **Next Step:**
Master recursion + sliding window + binary search + hashing with arrays — unlock 70% of DSA questions!

