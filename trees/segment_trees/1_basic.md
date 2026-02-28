# Segment Tree

## Overview

A **Segment Tree** is a tree-based data structure used for efficient range queries and updates on arrays. It allows operations like range sum, minimum, maximum, or greatest common divisor (GCD) queries in logarithmic time.

Segment trees are particularly useful when:

* The array is static or dynamically updated.
* Frequent range queries are required.
* Brute force (O(n)) per query is too slow.

---

## Key Idea

A segment tree divides an array into segments (intervals) and stores useful information about each segment.

Each node represents a range of indices:

* Root → entire array
* Internal nodes → subranges
* Leaf nodes → individual elements

The value of a parent node is computed by merging results from its children.

Example for range sum:

```
parent = left_child + right_child
```

---

## Tree Structure

For an array of size `n`:

* Height of tree = `O(log n)`
* Number of nodes ≈ `4n` (safe allocation size)

### Node Representation

Each node represents:

```
[node_left, node_right]
```

* Leaf node → single element
* Internal node → merge of two child ranges

---

## Memory Representation

Segment trees are stored in a single array (like a binary heap).

### 0-based indexing (common approach)

```
Root index → 0
Left child → 2*i + 1
Right child → 2*i + 2
```

The tree structure is simulated using index relationships rather than pointers.

### Array Size

To avoid overflow:

```
size = 4 * n
```

This guarantees enough space for all nodes.

---

## Segment Tree Construction (Build)

### Purpose

Construct the tree from the original array.

### Approach

The tree is built recursively using divide-and-conquer.

### Steps

1. Start from root representing full range `[0, n-1]`.
2. If range contains one element:

   * Store array value.
3. Otherwise:

   * Split range into two halves.
   * Recursively build left and right children.
   * Merge child results.

### Recurrence

```
if left == right:
    leaf node

else:
    build left subtree
    build right subtree
    merge results
```

### Time Complexity

```
O(n)
```

Every element contributes to building the tree once.

---

## Range Query

### Goal

Compute result over a query range `[QL, QR]`.

### Three Cases of Overlap

For a node range `[left, right]`:

#### 1. No Overlap

```
QR < left OR QL > right
```

Return identity value.

* Sum → 0
* Min → +∞
* Max → −∞

#### 2. Complete Overlap

```
QL <= left AND right <= QR
```

Return stored node value directly.

#### 3. Partial Overlap

Split query into:

```
left subtree
right subtree
merge results
```

### Time Complexity

```
O(log n)
```

Only relevant branches are visited.

---

## Point Update

### Purpose

Update a single element in the array and propagate changes.

### Steps

1. Update corresponding leaf node.
2. Recompute parent values while returning up the tree.

### Time Complexity

```
O(log n)
```

---

## Interval Representation

Segment trees typically use **closed intervals**:

```
[left, right]
```

Splitting:

```
mid = (left + right) / 2

left child  → [left, mid]
right child → [mid + 1, right]
```

Consistency in interval definition is critical for correct overlap handling.

---

## Merge Operation

Segment tree behavior depends on the merge operation.

### Common Examples

| Operation     | Merge Rule       |
| ------------- | ---------------- |
| Range Sum     | left + right     |
| Range Minimum | min(left, right) |
| Range Maximum | max(left, right) |
| GCD           | gcd(left, right) |

The merge operation must be:

* Associative
* Efficient to compute

---

## Time and Space Complexity

| Operation | Complexity          |
| --------- | ------------------- |
| Build     | O(n)                |
| Query     | O(log n)            |
| Update    | O(log n)            |
| Space     | O(n) (typically 4n) |

---

## Advantages

* Fast range queries and updates.
* Works with multiple operations (sum, min, max, etc.).
* Predictable logarithmic performance.
* Suitable for competitive programming and large datasets.

---

## Limitations

* Higher memory usage than simple arrays.
* Implementation complexity.
* Slower than prefix sums for static arrays with no updates.

---

## Comparison with Other Structures

| Structure                          | Query    | Update   | Notes                       |
| ---------------------------------- | -------- | -------- | --------------------------- |
| Prefix Sum                         | O(1)     | O(n)     | Static arrays only          |
| Fenwick Tree (Binary Indexed Tree) | O(log n) | O(log n) | Simpler, limited operations |
| Segment Tree                       | O(log n) | O(log n) | More flexible               |

---

## Common Implementation Pitfalls

* Mixing closed and half-open intervals.
* Incorrect overlap conditions.
* Wrong identity value for operation.
* Incorrect tree size allocation.
* Inconsistent indexing (0-based vs 1-based).
* Forgetting to propagate updates.

---

## When to Use Segment Tree

Use when:

* Frequent range queries are required.
* Array values change dynamically.
* Query and update operations must be efficient.
* Operations require associative merging.

Typical problems include:

* Range sum queries
* Range minimum queries
* Frequency counting
* Interval processing
* Competitive programming tasks

---

## Extensions (Advanced Topics)

* Lazy Propagation (range updates)
* Persistent Segment Trees
* 2D Segment Trees
* Iterative Segment Trees
* Dynamic Segment Trees

These extend the structure for more complex query/update patterns.