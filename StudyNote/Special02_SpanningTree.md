# Special Topic: Spanning Tree - Finding the Minimal Connected Structure in a Graph

## 1. What is a spanning tree?

### 1.1 Informal definition

A **spanning tree** of a connected graph G is a subgraph that:

* **Spans** all vertices of G (includes every vertex)
* Forms a **tree** (connected and acyclic)
* Uses the **minimum number of edges** to keep all vertices connected

Key properties:
* For a graph with n vertices, a spanning tree has exactly **n-1 edges**
* **Connects all vertices** with no cycles
* **Not unique** - a graph can have multiple spanning trees

Examples:
* Complete graph K₄ has 16 possible spanning trees
* A tree itself has only 1 spanning tree (itself)

### 1.2 Why spanning trees matter

Applications in real world:
* **Network design**: Connect all nodes with minimum cables/connections
* **Circuit design**: Electrical circuits without loops
* **Transportation**: Road/railway networks connecting all cities
* **Communication**: Broadcasting messages to all nodes efficiently

> Key insight: A spanning tree gives us the **backbone structure** of a graph - the essential connections needed to reach everything.

---

## 2. Minimum Spanning Tree (MST)

### 2.1 Weighted graphs and MST definition

When edges have **weights** (costs, distances, etc.):

* **Minimum Spanning Tree (MST)**: spanning tree with the **smallest total edge weight**
* Goal: connect all vertices with **minimum total cost**

Example applications:
* Laying cables: minimize total cable length
* Network routing: minimize total latency
* Clustering: group similar items with minimum dissimilarity

### 2.2 MST properties

**Cut Property**: For any cut (partition) of vertices, the minimum weight edge crossing the cut is in some MST.

**Cycle Property**: For any cycle in the graph, the maximum weight edge in that cycle is not in any MST.

These properties form the theoretical foundation for MST algorithms.

---

## 3. MST Algorithms: Greedy approaches

### 3.1 Kruskal's Algorithm

**Strategy**: Build MST by adding edges in order of increasing weight.

**Algorithm**:
1. Sort all edges by weight (ascending)
2. Initialize each vertex as its own component (Union-Find)
3. For each edge (u,v) in sorted order:
    - If u and v are in different components: add edge, union components
    - If u and v are in same component: skip (would create cycle)
4. Stop when we have n-1 edges

**Data structure**: Union-Find (Disjoint Set Union)

**Time complexity**: O(E log E) for sorting edges

### 3.2 Prim's Algorithm

**Strategy**: Grow MST from a starting vertex by adding minimum edge to new vertex.

**Algorithm**:
1. Start with any vertex, add to MST
2. Repeat until all vertices are in MST:
    - Find minimum weight edge connecting MST to a non-MST vertex
    - Add that edge and vertex to MST

**Data structure**: Priority queue (min-heap)

**Time complexity**: O(E log V) with binary heap, O(E + V log V) with Fibonacci heap

### 3.3 Comparison: Kruskal vs Prim

| Aspect | Kruskal's | Prim's |
|--------|-----------|---------|
| Strategy | Edge-based (global view) | Vertex-based (local growth) |
| Data structure | Union-Find | Priority Queue |
| Best for | Sparse graphs | Dense graphs |
| Edge consideration | All edges sorted | Edges from current MST |
| Implementation | Simpler conceptually | More intuitive growth |

---

## 4. Tree vs Graph: Structural perspective

### 4.1 From graph to tree

**Spanning tree extraction** transforms a graph into a tree:

* **Graph**: May have cycles, multiple paths between vertices
* **Spanning tree**: No cycles, exactly one path between any two vertices

This is **structure simplification**:
* Remove redundant connections (edges that create cycles)
* Keep essential connectivity

### 4.2 Tree properties in spanning trees

Once we have a spanning tree T of graph G:

* **Unique path**: Exactly one path between any two vertices in T
* **Adding any edge**: Creates exactly one cycle
* **Removing any edge**: Disconnects the tree into two components
* **Tree traversals**: DFS/BFS on the spanning tree visits all vertices

### 4.3 Multiple spanning trees and choice

A graph typically has **many possible spanning trees**:

* Different algorithms may produce different spanning trees
* In weighted graphs, MST may not be unique (ties in edge weights)
* Choice depends on optimization criteria:
  - Minimum total weight (MST)
  - Maximum reliability
  - Balanced structure

---

## 5. Implementation patterns and data structures

### 5.1 Union-Find for Kruskal's

```
Union-Find operations:
- Find(x): Which component contains x?
- Union(x,y): Merge components containing x and y
- Connected(x,y): Are x and y in same component?
```

**Path compression** and **union by rank** optimizations make operations nearly constant time.

### 5.2 Priority Queue for Prim's

```
Priority Queue operations:
- Insert edge with priority (weight)
- Extract minimum weight edge
- Update edge weights (decrease-key)
```

**Binary heap** or **Fibonacci heap** implementations provide different time complexities.

### 5.3 Graph representation impact

* **Adjacency Matrix**: O(V²) space, good for dense graphs
* **Adjacency List**: O(V + E) space, good for sparse graphs
* **Edge List**: Simple for Kruskal's algorithm

Choice affects algorithm performance and memory usage.

---

## 6. Advanced topics and extensions

### 6.1 Minimum Spanning Forest

For **disconnected graphs**:
* Cannot have a single spanning tree
* **Spanning forest**: Collection of spanning trees, one per connected component
* Algorithms adapt naturally: find MST for each component

### 6.2 Dynamic MST

When graph changes over time:
* **Edge insertions**: May need to update MST
* **Edge deletions**: May need to reconnect components
* **Specialized data structures** maintain MST incrementally

### 6.3 Applications in other algorithms

Spanning trees appear in:
* **Graph algorithms**: DFS/BFS trees
* **Network analysis**: Finding bottlenecks and critical connections
* **Machine learning**: Feature selection and clustering
* **Computational geometry**: Euclidean MST for point sets

> **Big picture**: Spanning trees bridge the gap between the **full complexity of graphs** and the **simple structure of trees**, giving us the essential connectivity with minimal overhead.
