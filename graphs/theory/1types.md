# 📚 Types of Graphs in Data Structures

Graphs come in various forms depending on **direction**, **weight**, **connectivity**, **structure**, and **properties**. Below is a complete classification with examples, usage, and important notes.

---

## 🔁 1. Directed vs Undirected Graphs

### 🔸 Directed Graph (Digraph)
- Edges have direction: (u → v)
- Example: Prerequisite graph, web page links
- Can have self-loops

### 🔹 Undirected Graph
- Edges are bidirectional: (u — v)
- Example: Friendships in social networks

> 📌 Representation: Adjacency list/matrix differs. For directed, only one direction is recorded.

---

## ⚖️ 2. Weighted vs Unweighted Graphs

### 🏋️ Weighted Graph
- Each edge has an associated weight or cost.
- Example: Road networks with distances, network latency

### 🧊 Unweighted Graph
- All edges are treated equally.
- Example: Friend graph, simple mazes

> 💡 Dijkstra’s, Prim’s require weighted graphs.

---

## 🔄 3. Cyclic vs Acyclic Graphs

### 🔁 Cyclic Graph
- Contains at least one cycle (i.e., a path that starts and ends at same node).
- Example: Flight routes that loop back

### 🚫 Acyclic Graph
- No cycles.
- If Directed → DAG (Directed Acyclic Graph)  
  Used in: Task scheduling, Build Systems (e.g., Makefile dependencies)

---

## 🔗 4. Connected vs Disconnected Graphs

### 🔄 Connected Graph
- Every node is reachable from every other node (in undirected graphs).
- In directed graphs, if each node is reachable from every other → **Strongly Connected**

### ❌ Disconnected Graph
- Some nodes are isolated / unreachable from others.
- Useful in finding **connected components**.

---

## 🏁 5. Complete Graph (K<sub>n</sub>)

- Every pair of distinct vertices has a direct edge.
- Number of edges: `n * (n - 1) / 2` (undirected)

Example:


For 4 vertices:
```
0 -- 1
\| / |
2 -- 3
```

> 🧠 Used in brute-force approaches (e.g., TSP).

---

## 🧮 6. Eulerian and Hamiltonian Graphs

### 🌀 Eulerian Path / Circuit
- Visits **every edge exactly once**
- Eulerian Circuit: Path ends at the starting point

#### Conditions (Undirected):
- Circuit: All vertices have even degree  
- Path only: Exactly two vertices have odd degree

### ♟ Hamiltonian Path / Circuit
- Visits **every vertex exactly once**
- Circuit: Path ends at the starting vertex

> 🧠 No polynomial-time algorithm exists to find Hamiltonian paths → NP-complete problem.

---

## 🧱 7. Tree and Forest

### 🌲 Tree
- Connected acyclic graph
- Has exactly `n-1` edges for `n` nodes
- Always a DAG (if directed)

### 🌳 Forest
- A disjoint union of trees (i.e., multiple tree components)

---

## 🔢 8. Sparse vs Dense Graphs

- **Sparse**: Very few edges compared to number of nodes (E ≪ V²)  
- **Dense**: Number of edges is close to maximum (E ≈ V²)

> ⚠️ Algorithm and data structure choice (adj list vs matrix) often depends on this.

---

## 🧠 9. Planar Graph

- Can be drawn in a plane without any edges crossing
- Example: Maps, circuits

> Used in geographical problem modeling.

---

## 🛠️ 10. Trivial, Null, and Regular Graphs

### 🎯 Trivial Graph
- Only one vertex, no edges

### ⛔ Null Graph
- `n` vertices, **no edges**

### ➖ Regular Graph
- All vertices have the **same degree**

---

## 🧩 Bonus: Special Graph Types

| Type             | Property |
|------------------|----------|
| Bipartite        | Can divide vertices into two sets with no internal edges |
| Multigraph       | Multiple edges allowed between two vertices |
| Pseudograph      | Multigraph + self-loops |
| Directed Acyclic Graph (DAG) | Directed, no cycles |
| Grid Graph       | Vertices arranged in 2D matrix (used in maze, image problems) |

---

## 📌 Summary Table

| Type                | Directed? | Weighted? | Cyclic? | Connected? |
|---------------------|-----------|-----------|---------|------------|
| Simple Graph        | ✔️ / ❌    | ✔️ / ❌    | ✔️ / ❌  | ✔️ / ❌     |
| Complete Graph      | ✔️ / ❌    | ✔️ / ❌    | ❌      | ✔️         |
| Tree                | ✔️ / ❌    | ✔️ / ❌    | ❌      | ✔️         |
| Eulerian            | ✔️ / ❌    | ❌        | ✔️      | ✔️         |
| Hamiltonian         | ✔️ / ❌    | ❌        | ✔️      | ✔️         |
| DAG                 | ✔️        | ✔️ / ❌    | ❌      | ✔️ / ❌     |
| Bipartite           | ✔️ / ❌    | ✔️ / ❌    | ✔️ / ❌  | ✔️ / ❌     |

---

## 🧭 Tags
#graph-theory #types-of-graphs #revision #dsa-notes #visualization
