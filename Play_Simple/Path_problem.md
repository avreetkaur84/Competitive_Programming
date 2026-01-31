### Notes
1. Very first thing comes in undirected graph for finding shortest path is bfs. Since, bfs ensures that a node at distance k will be visited first then a node at k+1 distance.

---

## 🟢 Beginner — BFS on unweighted graphs / grids

(If edge weight = 1, your brain should scream **BFS**)

1. **733. Flood Fill**
2. **200. Number of Islands** *(distance implicit)*
3. **542. 01 Matrix**
4. **994. Rotting Oranges**
5. **1091. Shortest Path in Binary Matrix**
6. **1926. Nearest Exit from Entrance in Maze**

👉 Focus:

* Queue discipline
* Visited marking (timing matters)

---

## 🟡 Intermediate — BFS with states / constraints

(BFS, but spicy 🌶️)

7. **127. Word Ladder**
8. **752. Open the Lock**                                               🟢 Done  
9. **847. Shortest Path Visiting All Nodes**
10. **1293. Shortest Path in a Grid with Obstacles Elimination**
11. **1129. Shortest Path with Alternating Colors**
12. **864. Shortest Path to Get All Keys**

👉 Focus:

* State = `(node, extra info)`
* Visited must include state, not just node

---

## 🟠 Weighted graphs — Dijkstra / 0-1 BFS

(If weights exist, BFS cries, Dijkstra smiles)

13. **743. Network Delay Time**
14. **787. Cheapest Flights Within K Stops**
15. **1631. Path With Minimum Effort**
16. **1514. Path with Maximum Probability**
17. **1976. Number of Ways to Arrive at Destination**
18. **882. Reachable Nodes In Subdivided Graph**

👉 Focus:

* Priority queue
* When to relax edges
* Why early stopping sometimes lies

---

## 🔵 Advanced — Multi-source, reverse, tricks

(Interviewers love these 😈)

19. **934. Shortest Bridge**
20. **1368. Minimum Cost to Make at Least One Valid Path in a Grid** *(0-1 BFS)*
21. **499. The Maze III**
22. **505. The Maze II**
23. **2045. Second Minimum Time to Reach Destination**

👉 Focus:

* Multi-source BFS
* Reverse graph thinking
* Tracking second-best distances

---

## 🧠 Suggested Solve Order (trust me)

1. 994 → 542 → 1091
2. 127 → 752 → 1129
3. 743 → 787 → 1631
4. 864 → 847 → 2045

---
