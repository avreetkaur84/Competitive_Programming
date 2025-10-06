### Warm-up (focus on recursion mechanics)

* **543. Diameter of Binary Tree** → Very similar to coins: return height, update global max diameter.
* **104. Maximum Depth of Binary Tree** → Return depth only (no global state, simpler).
* **110. Balanced Binary Tree** → Return height; global check for balance.

---

### Intermediate (helper + global ans pattern really shows up)

### Warm-up
* 🟢 **543. Diameter of Binary Tree — <span style="color:green">Done (2025-09-30)**</span>
* 🟢 **437. Path Sum III** → multiple start points, running sum backtracking (current challenge)  — <span style="color:green">Done (2025-09-30)**</span> 
    #### Tree + Backtracking / Path Sums Practice: For successfully solving 437 Ques
    ##### 1️⃣ Tree + Path Sums
    * 🟢 **112. Path Sum** → simpler problem, only root-to-leaf paths  — <span style="color:green">Done (2025-09-30)**</span>  
    * 🟢 **113. Path Sum II** → collect all root-to-leaf paths, practice tracking multiple paths  — <span style="color:green">Done (2025-09-30)**</span>   

    ##### 2️⃣ General Recursion + Backtracking / Combinations
    - **39. Combination Sum** → track partial sums, explore all combinations.  
    - **40. Combination Sum II** → like 39, but remove duplicates; practice pruning + backtracking.  
    - **77. Combinations** → generate all combinations of k numbers from 1..n.  
    - **46. Permutations** → track multiple states while backtracking.  
    - **47. Permutations II** → permutations with duplicates, decide which states to keep/discard.

    ##### 3️⃣ Mental Model for Tree Path Sum Problems
    - Think of each node as a **starting point**.  
    - From each starting point, do a **DFS downwards**, keeping a **running sum**.  
    - Whenever the running sum equals `targetSum`, increment your counter.  
    - Recurse to left and right children.  
    - Backtrack naturally as recursion unwinds; no explicit undo is needed if running sum is passed as a parameter.

* **337. House Robber III** → Return two values per node (rob or not rob).
* **236. Lowest Common Ancestor of a Binary Tree** → Return boolean to parent, global answer updated when both sides found.

---

### Advanced (multi-return logic & trickier balances)

* 🟢  **979. Distribute Coins in Binary Tree - <span style="color:green">Done (2025-09-30)**</span>
* **968. Binary Tree Cameras** → Each node returns state (covered, has camera, needs camera).
* **814. Binary Tree Pruning** → Return pruned subtree recursively.
* **333. Largest BST Subtree** → Return tuple (isBST, size, min, max), update global max.
* **865. Smallest Subtree with all the Deepest Nodes** → Return depth + subtree root.

---

### Boss level (forces you to think *what to return vs what to track*)

* **212. Word Search II** (DFS + trie).
* **51. N-Queens** (backtracking tree).
* **22. Generate Parentheses** (build string via recursion).
* **131. Palindrome Partitioning** (return list of lists).
* **472. Concatenated Words** (recursion + memoization).

---

⚡ My advice:
For each problem, write down on paper before coding:

* **What do I return to my parent?**
* **What do I record globally (or pass via reference)?**

That habit will kill your “intuition vs code mismatch” problem over time.

---