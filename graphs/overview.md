## 🔹 Graph Basics

* **Representation**

  * Adjacency List (space-efficient, common in CP).
  * Adjacency Matrix (dense graphs, O(V²) space).
* **Directed vs Undirected, Weighted vs Unweighted, Cyclic vs Acyclic.**
* **Connected Components** – find how many disjoint subgraphs exist.

---

## 🔹 Traversals 

* **DFS** – recursion/stack, used in:

  * Cycle detection
  * Topological sorting
  * Strongly connected components (Kosaraju/Tarjan)
* **BFS** – queue, used in:

  * Shortest path in unweighted graphs
  * Bipartite graph check (coloring)

---

## 🔹 Important Concepts

* **Cycle detection**

  * Undirected → DFS with parent tracking / Union-Find
  * Directed → DFS with recursion stack
* **Topological Sort**

  * Only for DAGs
  * Kahn’s Algo (BFS + in-degree) / DFS approach
* **Bipartite Graph**

  * BFS/DFS coloring
  * Application: Matching problems

---

## 🔹 Shortest Paths

* **Dijkstra’s Algorithm** → Single source shortest path (non-negative weights).
* **Bellman-Ford** → Handles negative weights (detects -ve cycles).
* **Floyd-Warshall** → All-pairs shortest path (DP approach, O(V³)).
* **0-1 BFS** → Optimized BFS for weights 0/1.

---

## 🔹 Minimum Spanning Tree (MST)

* **Prim’s Algo** → Greedy, uses priority queue.
* **Kruskal’s Algo** → Greedy + Union-Find DS.
* Application: network design, clustering.

---

## 🔹 Advanced Topics (depends how far you want to go)

* **Union-Find (DSU)** → cycle detection, Kruskal, dynamic connectivity.
* **Bridges & Articulation Points** → Tarjan’s Algo (critical edges/nodes).
* **Strongly Connected Components (SCCs)** → Kosaraju/Tarjan.
* **Network Flow**

  * Max Flow (Ford-Fulkerson, Edmonds-Karp, Dinic).
  * Min-Cut problems.
* **Eulerian & Hamiltonian Paths**

  * Eulerian → check degree conditions
  * Hamiltonian → NP-hard, so usually backtracking/DP.

---

## 🔹 Graph Trickery (Interview-friendly)

* Grid problems → treat as graphs (BFS/DFS on cells).
* Topological sort usage → course scheduling, dependency resolution.
* Bipartite + Matching → job assignment problems.
* “Number of Islands” → classic DFS/BFS/Union-Find.

---

👉 Suggestion: In interviews, they rarely throw *network flow* at you unless it’s super advanced. Most common: **BFS/DFS, shortest paths, MST, bipartite, topological sort, cycle detection**.

---