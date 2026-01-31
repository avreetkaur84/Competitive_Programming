# 📘 Floyd–Warshall Algorithm – Revision Notes

---

## 🔹 Purpose

* **All-pairs shortest path** algorithm.
* Finds shortest distances between **every pair of vertices**.
* Works on **directed + undirected graphs**.
* Handles **negative weight edges**.
* Can **detect negative weight cycles**.

---

## 🔹 Core Idea

* Use **Dynamic Programming**.
* Gradually allow intermediate vertices in paths.
* At step `k`, shortest paths are computed using only vertices `{0 … k}` as intermediates.
* If allowing a vertex `k` shortens the path from `i → j`, update it.

Mathematical relation:

```
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
```

---

## 🔹 Steps

1. Initialize distance matrix:

   * `dist[i][j] = weight(i, j)` if edge exists.
   * `dist[i][i] = 0`
   * Else `∞`
2. For each intermediate vertex `k`:

   * For each pair `(i, j)`:

     * Update `dist[i][j]` using vertex `k`
3. Negative cycle detection:

   * If `dist[i][i] < 0` for any `i`, negative cycle exists.

---

## 🔹 Floyd–Warshall Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist, int V) {
    // Main Floyd-Warshall logic
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Negative cycle detection
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative weight cycle detected\n";
            return;
        }
    }

    // Print result
    cout << "All-Pairs Shortest Distances:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int V = 4;

    vector<vector<int>> dist = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(dist, V);
    return 0;
}
```

---

## 🔹 Characteristics

* Computes shortest paths between **all pairs**.
* Handles negative edges safely.
* Detects negative cycles.
* Works even on **dense graphs**.
* Uses **adjacency matrix**, not edge list.

---

## 🔹 Complexity

* **Time:** `O(V³)`
* **Space:** `O(V²)`
* Suitable when:

  * V is small (≤ 400 approx)
  * Graph is dense

---

## 🔹 Comparison with Other Algorithms

### Floyd–Warshall vs Dijkstra vs Bellman–Ford

| Feature                  | Dijkstra       | Bellman-Ford    | Floyd–Warshall      |
| ------------------------ | -------------- | --------------- | ------------------- |
| Shortest paths           | Single source  | Single source   | All pairs           |
| Negative weights         | ❌              | ✅               | ✅                   |
| Negative cycle detection | ❌              | ✅               | ✅                   |
| Time complexity          | O((V+E) log V) | O(V·E)          | O(V³)               |
| Graph representation     | Adjacency list | Edge list       | Adjacency matrix    |
| Algorithm type           | Greedy         | DP / Relaxation | Dynamic Programming |

---

## 🔹 Applications

* **All-pairs routing tables**.
* Finding shortest distances between **every city pair**.
* **Transitive closure** of a graph.
* **Detecting negative cycles** in weighted graphs.
* Used in **network analysis** and **path planning**.

---

## 🔹 Key Interview Lines

* “Floyd–Warshall uses dynamic programming over intermediate vertices.”
* “At iteration `k`, paths using vertices `{0…k}` are considered.”
* “Negative cycles are detected if `dist[i][i] < 0`.”
* “It computes all-pairs shortest paths in O(V³) time.”

---

## 🔹 When to Use Floyd–Warshall?

✅ Need **all-pairs shortest paths**
✅ Graph is **dense**
✅ Vertex count is **small**
❌ Large sparse graphs → use Dijkstra / Bellman-Ford instead

---