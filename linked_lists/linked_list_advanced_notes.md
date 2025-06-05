
# 🔗 Linked List - Advanced Notes (DSA + CP + Placements)

## 🔁 1. Cycle Detection in Linked List
- **Floyd’s Tortoise and Hare Algorithm** (Slow and Fast pointers)
  - Time: `O(n)`, Space: `O(1)`
  - Can be extended to:
    - Detect cycle entry point
    - Remove loop
- **Caution**: Don't write `while(slow != fast)` without checking for `nullptr` on `fast` or `fast->next`.

---

## 🔄 2. Reversing a Linked List
- Reverse entire list (iterative/recursive)
- Reverse a sub-list (between positions m and n)
- Reverse in groups of K (LeetCode 25)

---

## 👑 3. Merge Sorted Linked Lists
- Merge Two Sorted Lists
- Merge K Sorted Lists
  - Min Heap Approach (`priority_queue`)
  - Divide and Conquer

---

## 🎯 4. Middle of Linked List
- Use slow and fast pointer technique
- Applications:
  - Palindrome check
  - Split list for MergeSort
  - Detect cycle entry

---

## 🔃 5. Palindrome Linked List
- Find middle
- Reverse second half
- Compare both halves
- Restore original structure (if required)

---

## 📐 6. Intersection of Two Linked Lists
- Length difference method
- HashSet (space trade-off)
- Convert to cycle trick

---

## 🎣 7. Detect & Remove Cycle
- Use Floyd’s algorithm to detect
- Reset one pointer to head to find start of loop
- Modify `next` pointer of the node before loop starts

---

## 🧹 8. Remove N-th Node From End
- Use dummy node
- Use fast & slow pointer with `n` gap
- Single traversal solution

---

## 🧬 9. Copy List with Random Pointer
- HashMap to store mapping original->copy
- Optimized:
  - Interweave copied nodes with original nodes
  - Reconnect random pointers and restore

---

## 💥 10. Flatten a Multilevel Linked List / K-List
- Recursively flatten
- Use Stack or Min Heap

---

## 📏 11. Length-based Problems
- Get length of loop
- Difference in lengths of lists
- Get K-th node from end

---

## ♻️ 12. Rotating Linked List
- Rotate Right by K places
- Form cycle and break at appropriate position

---

## 🪓 13. Segregate Even/Odd or 0/1/2
- Maintain multiple sub-lists
- Common trick: Dummy nodes

---

## 🧙‍♂️ 14. Skip K delete M nodes pattern
- Tricky pointer pattern
- Good for pointer manipulation practice

---

## 🔀 15. Merge Sort on Linked List
- Recursively find middle and split
- Merge sorted lists
- Time: `O(n log n)`, Space: `O(log n)`

---

## 💡 16. Design Questions
- LRU Cache – Doubly Linked List + HashMap
- LFU Cache
- Browser History / Undo-Redo systems

---

## ✅ Practice Tips
- Use dummy nodes to avoid head handling issues
- Master slow-fast pointer patterns
- Always preserve `next` pointer during re-links
- Build muscle memory for common tricks
