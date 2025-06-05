
# 📘 HEAP NOTES (Min Heap / Max Heap) – For DSA, CP, and Placements

## 🔍 What is a Heap?
A **heap** is a **complete binary tree** with a special property:
- **Min-Heap:** `parent ≤ children` → smallest at the top
- **Max-Heap:** `parent ≥ children` → largest at the top

### Properties:
- Stored as an array.
- For node at index `i`:
  - Left Child → `2*i + 1`
  - Right Child → `2*i + 2`
  - Parent → `(i - 1) / 2`

## 🔧 Types of Heaps in C++ STL

### ✅ Min Heap
```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```

### ✅ Max Heap (Default)
```cpp
priority_queue<int> maxHeap;
```

### ✅ Custom Heap (with pairs or structs)
```cpp
struct compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // Min-heap by second element
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
```

## 🧠 When to Use a Heap
- **Top K elements** (min/max)
- **Dijkstra’s algorithm** (shortest path)
- **Merge K sorted lists/arrays**
- **Scheduling problems** (like Task Scheduler)
- **Greedy choice extraction**
- **Simulation / Event-based problems**
- **Sliding Window problems with fixed size max/min**

## 🔨 Common Heap Problems & Patterns

| 🔢 Problem Type | 💡 Idea |
|----------------|--------|
| Kth largest/smallest | Use min/max heap of size K |
| Task scheduling | Greedy + max heap for frequency |
| Top K frequent | Frequency map + heap |
| Merge K sorted lists | Push first elements of each list, pop and push next |
| Sliding window max | Max heap + index or monotonic queue (heap can be used but slower) |
| Reorganize string | Max heap of char freq |
| Is N Straight Hand | Min heap of freq sorted cards |
| Huffman encoding | Min heap of frequencies |

## 🧩 Complexity Analysis

| Operation         | Heap     |
|------------------|----------|
| Insertion         | O(log N) |
| Deletion (pop)    | O(log N) |
| Access top        | O(1)     |
| Heapify (make_heap) | O(N)     |

👉 Use `priority_queue` when top priority element is frequently needed.  
👉 Avoid when you need random access or updates (use balanced BST or multiset).

## 🛑 Gotchas / Mistakes to Avoid
- **For custom comparator**, define `struct` outside the function/class if using locally in CP.
- **Empty heap access = runtime error** – always check `.empty()` before `.top()`.
- **Min/Max confusion** – double-check `greater<>` or `less<>`.
- `priority_queue` in C++ is **by default Max Heap**.
- Be cautious when modifying contents inside the heap (not allowed directly).
- **No decrease-key** operation in STL `priority_queue` → need to push duplicates and ignore stale ones (like Dijkstra in C++).

## 🎯 Important STL Functions
```cpp
priority_queue<int> pq;
pq.push(x);     // O(log N)
pq.top();       // O(1)
pq.pop();       // O(log N)
pq.size();      // O(1)
pq.empty();     // O(1)
```

## 📦 Heap Building Tools (from scratch)

### Min Heap using array (custom):
```cpp
void heapify(vector<int>& arr, int n, int i) {
    int smallest = i, l = 2*i + 1, r = 2*i + 2;
    if(l < n && arr[l] < arr[smallest]) smallest = l;
    if(r < n && arr[r] < arr[smallest]) smallest = r;
    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
```

## 🔥 Must Practice Problems

- ✅ [LC 703. Kth Largest Element in Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
- ✅ [LC 215. Kth Largest Element in Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- ✅ [LC 347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
- ✅ [LC 621. Task Scheduler](https://leetcode.com/problems/task-scheduler/)
- ✅ [LC 295. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)
- ✅ [LC 767. Reorganize String](https://leetcode.com/problems/reorganize-string/)
- ✅ [LC 378. Kth Smallest in Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)
- ✅ [LC 846. Is N Straight Hand](https://leetcode.com/problems/hand-of-straights/)
- ✅ [Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
- ✅ [LC 973. K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)

## 🚀 Final Tips
- 🔄 When **order matters**, heap is your best friend.
- 💡 Try dry-running with a paper and heap state — helps debug better.
- ❗ Think twice before using a heap — maybe a multiset or TreeMap is more suitable.
