## 📌 Topological Sort – Complete Notes

## 1️⃣ What is Topological Sort?

Topological Sort is a **linear ordering of vertices in a Directed Acyclic Graph (DAG)** such that for every directed edge `u → v`, **vertex `u` appears before `v`** in the ordering.

But this isn't just a "graph definition"—it's about **cause and effect**.

---

### 🧠 Intuition

Imagine a world where some tasks **depend** on other tasks. You **cannot break the order** of these dependencies. Topological sort gives you **one valid sequence** of execution that respects these rules.

Think of it like a "to-do list" where you can't just do things randomly.

---

### 🎯 Real-Life Analogies

#### 1. **Course Scheduling**

You want to finish your degree:

```
DSA → Graphs → Topological Sort Problems
```

* You **cannot** learn "Topo Sort Problems" before "Graphs."
* You **cannot** learn "Graphs" before "DSA."

Topo sort ensures you study in a **dependency-respecting sequence.**

✅ Possible valid order:
`[DSA, Graphs, Topological Sort Problems]`

---

#### 2. **Cooking Recipe**

You want to make pasta:

```
Boil Water → Add Pasta → Drain Pasta → Serve
```

* You can't "Drain Pasta" if you haven’t "Boiled Water" and "Added Pasta."
* You can't "Serve" before draining.

Topo sort gives you the **legal execution order** so dinner doesn't turn into chaos. 🍝

---

#### 3. **Project Build System**

In software compilation:

```
Compile Utils → Compile Main → Link → Run
```

If you try to "Link" before compiling, the compiler screams.
Topo sort is exactly what build systems use to decide the correct order.

---

### 💡 Key Points

* **Only for DAG:**
  If there's a cycle (`A → B → C → A`), you have a deadlock. No valid order exists because you're stuck in infinite dependency.

* **Not Unique:**
  There may be **many valid orders**.
  Example: If `A → C` and `B → C`, you can do `A, B, C` or `B, A, C` — both are valid.

* **Represents Dependency Resolution:**
  Instead of "sorting numbers," you are **sorting tasks in a way that respects prerequisites.**

---

### 🏗 Mental Model (Dependency Stack)

Picture topo sort as a game:

1. Pick any task with **no prerequisites left.**
2. Do it.
3. Remove it from the board.
4. Repeat until everything is done.

If at any point nothing is available to pick but tasks remain → you have a cycle (invalid scenario).

This is why topological sort is **the universal tool for ordering tasks in a dependency chain.**

---

## 4. Algorithms

#### **A. DFS Approach**

1. Create a visited array.
2. For every unvisited node, run DFS.
3. In DFS:

   * Visit all children first.
   * Push current node onto a stack **after visiting all children**.
4. Reverse the stack to get the topo order.

```cpp
vector<int> topoSortDFS(int n, vector<vector<int>>& adj) {
    vector<int> visited(n, 0);
    stack<int> st;

    function<void(int)> dfs = [&](int node) {
        visited[node] = 1;
        for (auto neigh : adj[node]) {
            if (!visited[neigh]) dfs(neigh);
        }
        st.push(node); // post-order push
    };

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i);
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}
```

---

#### **B. BFS Approach (Kahn's Algorithm)**

1. Calculate **indegree** for every node.
2. Put all nodes with indegree `0` in a queue.
3. Pop from the queue, add to result, and reduce the indegree of its neighbors.
4. If a neighbor’s indegree becomes `0`, push it into the queue.
5. Continue until queue is empty.

```cpp
vector<int> topoSortBFS(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; u++) {
        for (auto v : adj[u]) indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto neigh : adj[node]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0) q.push(neigh);
        }
    }
    return topo;
}
```

---

### 5️. Example Walkthrough

Graph:

```
5 → 0 ← 4
↓
2 → 3
1 → 3
```

**Step-by-step Kahn's Algorithm:**

1. Indegree: \[1,1,1,2,0,0]
2. Queue: \[4, 5]
3. Pick 4 → topo: \[4] → unlock 0
4. Pick 5 → topo: \[4, 5] → unlock 2
5. Pick 0 → topo: \[4, 5, 0]
6. Pick 2 → topo: \[4, 5, 0, 2] → unlock 3
7. Pick 1 → topo: \[4, 5, 0, 2, 1]
8. Pick 3 → topo: \[4, 5, 0, 2, 1, 3] ✅

---

### 6️. Complexity

* **DFS Approach:** `O(V + E)`
* **BFS Approach:** `O(V + E)`
* **Space Complexity:** `O(V + E)` for graph + `O(V)` for visited/indegree.

---

### 7️. When to Use DFS vs BFS?

| DFS (Stack)                            | BFS (Kahn)                            |
| -------------------------------------- | ------------------------------------- |
| Good for recursion lovers.             | Good for iterative style.             |
| Natural post-order intuition.          | Direct dependency tracking.           |
| Can detect cycles with visited states. | Can detect cycles if result size < N. |

---

### 8️. Key Insights

* Topo sort is **NOT about smallest/largest value sorting** → it's **dependency sorting**.
* **Cycle detection:**

  * DFS: use a recursion stack to detect back edges.
  * BFS (Kahn): if you can't process all nodes, a cycle exists.
* **Multiple valid orders:** As long as dependencies hold, order can vary.

---

### 9️. Real-Life Applications

* Course Scheduling
* Build Systems (compilation order)
* Package Dependency Resolution
* Task Scheduling in Operating Systems
* Game Level Unlocking Logic

---

## ✅ TL;DR

Topological Sort = **Dependency Order**

* DFS → Post-order stack.
* BFS → Indegree queue.
* Think **"What has no prerequisites yet? Do that first."**

---