# 🚀 Dijkstra’s Algorithm – Complete Notes

---

## 🔹 1. What is Dijkstra’s Algorithm?

* **Purpose:** Find the **shortest path** from a **source node** to all other nodes in a **weighted graph** (with **non-negative weights**).
* Works with:

  * **Graphs**: Directed or undirected
  * **Edge weights**: Non-negative only (important constraint!)
* Fails / needs modification when:

  * **Negative edge weights exist** → Use **Bellman-Ford** instead.

---

## 🔹 2. Core Idea

* **Greedy algorithm**: Always expands the node with the current shortest distance.
* Think of it as "spreading ripples outward from the source" — each step finalizes the shortest distance for the closest unvisited node.

---

## 🔹 3. Core Steps (Vanilla Dijkstra)

1. **Initialize**

   * `dist[]` = distance array, set all = `∞` (INT\_MAX), except `dist[src] = 0`.
   * Use a **min-heap / priority\_queue** to pick the next closest node.
2. **Relax edges**

   * Pop `(d, node)` from heap.
   * For every neighbor `(v, weight)`:

     * If `dist[node] + weight < dist[v]`, update and push `(dist[v], v)` into heap.
3. **Stop**

   * When all nodes processed OR when we only care about reaching `dst`.

⏱ **Time Complexity:**

* Using adjacency list + min-heap: **O((V+E) log V)**
* Worst case: \~ `O(E log V)`

---

## 🔹 4. Implementation Styles

1. **Priority Queue (Best, classical form)**

   * Standard Dijkstra, always picks minimum distance node next.
   * Great when all you care about is shortest distances.

2. **Queue / BFS-style (when edges represent steps, not weights)**

   * Sometimes used in variations (like your **k-stops flights** problem).
   * Simpler but careful: may revisit nodes multiple times.

---

## 🔹 5. Variants & Tricks (Very Important for CP + Interviews)

### ✅ Standard Single-Source Shortest Path

* **dist\[src] = 0**, update neighbors via min-heap.

---

### ✅ K-Stops / Limited Steps Constraint

* Along with `(dist, node)`, store **steps taken**.
* Discard if `steps > k`.
* Helps in problems like "Cheapest Flight Within K Stops".

---

### ✅ Path Reconstruction

* Maintain a `parent[]` array.
* Whenever you relax `v` via `u`, update `parent[v] = u`.
* At the end, trace back from `dst` to `src` for actual path.

---

### ✅ Multiple Sources

* Push all sources into heap initially with `dist[source] = 0`.
* Then proceed normally.
* (Useful in problems where you start from multiple nodes simultaneously).

---

### ✅ Early Stopping

* If only `dist[dst]` matters, stop when you first pop `dst` from heap.
* Saves time for large graphs.

---

### ✅ Dijkstra + State Encoding (Powerful Trick!)

Sometimes you need more than just `dist[node]`.
You track "state" as well:

* Example: `(dist, node, steps)`
* Example: `(dist, node, fuel_left)`
  This allows solving many **graph + constraints** type problems.

---

## 🔹 6. Pitfalls & Gotchas

1. **Negative edges?** ❌ Don’t use Dijkstra. Use Bellman-Ford / SPFA.
2. **Large weights?** Always use `long long`, avoid integer overflow.
3. **Dense graphs (E \~ V²)?** Dijkstra still works, but **Floyd-Warshall** may be cleaner.
4. **Multiple relaxations:** Don’t forget to check if `dist[node] < d` before processing a heap pop (to discard stale entries).

---

## 🔹 7. When to Choose Dijkstra vs Other Algorithms

* **Dijkstra**: Non-negative weights, shortest paths.
* **Bellman-Ford**: Handles negative weights (O(VE)).
* **Floyd-Warshall**: All-pairs shortest path (O(V³)).
* **0-1 BFS**: Special case when edges are 0 or 1 → O(V+E).
* **BFS**: Unweighted graphs (edge weight = 1).

---

## 🔹 8. Template Code (C++17, Priority Queue)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, int>

vector<ll> dijkstra(int n, int src, vector<vector<pair<int,int>>>& adj) {
    const ll INF = 1e18;
    vector<ll> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // stale entry

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

---

## 🔹 9. Cheat-Sheet Summary

* Dijkstra = shortest path, non-negative weights.
* Use `priority_queue` (min-heap).
* Dist array init to `∞`, dist\[src] = 0.
* Variants: k-stops, path reconstruction, multiple sources, early stopping.
* Pitfalls: negative weights, int overflow.
* Complexity: `O(E log V)`

---