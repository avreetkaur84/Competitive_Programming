# 📘 Bellman-Ford Algorithm – Revision Notes

---

## 🔹 Purpose

* **Single source shortest path** algorithm.
* Works on **directed + undirected graphs** (undirected treated as bidirectional edges).
* Handles **negative weight edges**.
* Can **detect negative weight cycles** (Dijkstra cannot).

---

## 🔹 Core Idea

* Relax all edges **V−1 times** (where V = number of vertices).
* Each relaxation step guarantees shortest paths of length ≤ k edges after k iterations.
* After V−1 iterations, all shortest paths are finalized (since the longest possible simple path has V−1 edges).
* Run **one more iteration** to check for changes → if distance still decreases → **negative cycle detected**.

---

## 🔹 Steps

1. Initialize distances:

   * `dist[src] = 0`, all others = ∞.
2. Repeat **V−1 times**:

   * For each edge (u, v, w):
     if `dist[u] + w < dist[v]` → update `dist[v]`.
3. Extra pass:

   * If any distance improves → negative cycle exists.

---

## 🔹 Code
```
struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    const int INF = 1e9;
    vector<int> dist(V, INF);
    dist[src] = 0;

    // Step 1 & 2: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative weight cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Negative weight cycle detected\n";
            return;
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << i << "\tINF\n";
        else
            cout << i << "\t" << dist[i] << "\n";
    }
}

```

---

## 🔹 Characteristics

* Works for: Directed / Undirected, Weighted (positive + negative).
* Fails only when: Graph contains a **negative weight cycle** reachable from source.
* Complexity:

  * Relaxation = O(E) per iteration.
  * Total = **O(V·E)**.
  * Space = O(V).
* Nature: **Dynamic Programming** (not greedy).

---

## 🔹 Comparison with Dijkstra

| Feature                  | Dijkstra                   | Bellman-Ford             |
| ------------------------ | -------------------------- | ------------------------ |
| Graph type               | Directed/Undirected        | Directed/Undirected      |
| Edge weights             | Non-negative only          | Handles negative weights |
| Negative cycle detection | ❌                          | ✅                        |
| Complexity               | O((V+E) log V) (with heap) | O(V·E)                   |
| Algorithm type           | Greedy                     | DP / Relaxation          |

---

## 🔹 Applications

* Shortest paths in graphs with **negative weights**.
* **Detecting arbitrage** in currency exchange (negative cycle = profit loop).
* Network routing (distance-vector protocols like RIP).

---

## 🔹 Key Interview Lines

* “Bellman-Ford relaxes all edges V−1 times; shortest paths settle within V−1 edges.”
* “A final V-th iteration detects negative cycles.”
* “Unlike Dijkstra, it is safe for negative weights but slower (O(V·E)).”

---

