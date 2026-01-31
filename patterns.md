# DSA Patterns Cheat Sheet
### Problems List -> https://docs.google.com/document/d/1Zx3FUZqjwqri5X6jGeuJ47QO4aO_7C_YKiKpaneeHI8/edit?tab=t.0

## 1. Strings & Its Patterns
- KMP Algorithm
- Z-Algorithm
- Rabin-Karp Algorithm
- Longest Common Subsequence (LCS)
- Edit Distance
- Regular Expression Matching
- Palindrome Problems

## 2. Dynamic Programming (DP) & Its Patterns
- Fibonacci / Simple Recurrence
- 0/1 Knapsack
- Unbounded Knapsack
- Longest Common Subsequence (LCS)
- Longest Increasing Subsequence (LIS)
- Grid-Based DP
- Interval DP
- Tree DP
- Bitmasking / State Compression
- Digit DP
- Probability / Expectation DP

## 3. Graphs & Its Patterns
- DFS / BFS Traversal
- Shortest Path Algorithms (Dijkstra, Bellman-Ford, Floyd-Warshall)
- Topological Sort
- Cycle Detection
- Connected Components
- Minimum Spanning Tree (MST)
- Union-Find (Disjoint Set Union - DSU)
- Grid-Based Graph Problems
- Graph Coloring
- Strongly Connected Components (SCC)
- Eulerian & Hamiltonian Paths
- Planets & Queries (Advanced Graph Problems)

## 4. Trees & Its Patterns
- Distance Between Nodes (LCA, BFS/DFS)
- Sum of Distances (Rerooting Technique)
- Subtree Queries (Segment Trees, Heavy-Light Decomposition)
- Binary Lifting (LCA Optimization)
- Tree DP (Dynamic Programming on Trees)
- Path Queries (Prefix Sums, Binary Lifting)
- Tree Construction (BST, Trie, etc.)

## 5. Heap (Priority Queue) & Its Patterns
- Top K Elements
- Merge K Sorted Structures
- Two Heaps for Medians
- Sliding Window Heaps
- Greedy Heap Applications
- Heap-based Game Theory

## 6. Linked Lists & Its Patterns
- Fast and Slow Pointers (Two Pointers)
- Reversing Linked Lists
- Merging and Partitioning Lists
- Dummy Node Technique
- List Manipulation Operations
- List Transformations
- Basic List Operations Implementation

---

## → Secondary / Supporting Data Structures for Interviews
- **Hash Maps / Hash Sets** – used in string matching, graph traversals, etc.
- **Stacks & Queues** – used in DFS/BFS, parsing, etc.
- **Binary Search Trees (BST)** – used in some tree-based problems
- **Trie (Prefix Tree)** – used in string matching problems
- **Segment Trees & Fenwick Trees** – used in range queries, subtree problems
- **Monotonic Stacks/Queues** – used in sliding window problems



## Helpful references (internal KB):
- Search the subarray with the maximum/minimum sum (array, greedy, dp-1d)
    - When to use: When you need to find the contiguous subarray within a one-dimensional array of numbers that has the largest or smallest sum, typically in linear time.
    - Idea: This algorithm efficiently finds the maximum (or minimum) sum of a contiguous subarray by iterating through the array and maintaining a current sum, resetting it if it becomes detrimental. It operates in O(N) time complexity with O(1) space complexity.
    - Invariants: `global_max` holds the maximum sum of any contiguous subarray encountered up to the current element.; `current_max` holds the maximum sum of a contiguous subarray ending at the current element.
    - Tips: Initialize current and global maximums appropriately (e.g., to negative infinity or first element).; Adapt for minimum sum by resetting current sum if it becomes positive.
    - Pitfalls: Failing to correctly initialize maximum/minimum sum variables.; Not handling arrays where all elements are negative (for max sum) or positive (for min sum).
- Generating all K-combinations (array, enumeration, greedy)
    - When to use: Use this when you need to iterate through all possible subsets of a fixed size K from a larger set, especially when a specific order like lexicographical is required.
    - Idea: This algorithm systematically generates all unique combinations of K elements from a set of N elements. It typically proceeds in lexicographical order, allowing for efficient enumeration of all C(N, K) possibilities.
    - Invariants: The current combination C is always sorted: C[0] < C[1] < ... < C[K-1].; All elements C[i] are distinct and within the range [0, N-1] (assuming 0-indexed).
    - Tips: Start with the smallest lexicographical combination (e.g., {1, 2, ..., K}).; To find the next combination, locate the rightmost element that can be incremented.
    - Pitfalls: Incorrectly handling boundary conditions when incrementing elements.; Duplicating combinations if not careful with the increment logic.
- Scheduling jobs on two machines (array, greedy)
    - When to use: Use when optimizing the order of a sequence of tasks on two machines to minimize total idle time or makespan. It is typically applied when a greedy exchange argument can prove optimality.
    - Idea: This algorithm determines an optimal sequence for jobs on two machines by iteratively applying a greedy choice, often proven optimal via an exchange argument. It typically achieves an optimal solution in polynomial time, commonly O(N log N) or O(N^2).
    - Invariants: The relative order of jobs already placed in the schedule is optimal.; The total idle time for the current prefix of scheduled jobs is correctly calculated.
    - Tips: Focus on the local effect of swapping adjacent elements to derive the greedy criterion.; Identify a metric (e.g., total idle time or makespan) that changes predictably with swaps.
    - Pitfalls: The greedy choice might not be globally optimal for problems with more than two machines.; Incorrectly defining the cost function for idle time or makespan can lead to suboptimal solutions.