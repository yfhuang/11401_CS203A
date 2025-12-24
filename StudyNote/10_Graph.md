# Study Note: Graph

## Description

Graph: A collection of **vertices (nodes)** connected by **edges** that model relationships between entities. Edges can be **undirected** (two-way) or **directed** (one-way), and graphs may contain **cycles** (unlike trees). Graphs are commonly used to represent real-world networks such as social connections, transportation routes, and hyperlinks on the web.  

## Graph in Discrete Mathematics

In **discrete mathematics**, a graph is defined formally as an ordered pair:

- **Undirected graph**: \(G = (V, E)\)  
    - \(V\): a **non-empty finite set** of vertices  
    - \(E \subseteq \{\{u,v\} \mid u,v \in V,\ u \neq v\}\): a set of **unordered pairs** (edges)

- **Directed graph (digraph)**: \(G = (V, E)\)  
    - \(E \subseteq V \times V\): a set of **ordered pairs** \((u,v)\) (arcs)

### Key terms
- **Adjacent vertices**: \(u\) and \(v\) are adjacent if \(\{u,v\} \in E\) (undirected) or \((u,v) \in E\) (directed)
- **Degree** (undirected): \($\deg$(v)\) = number of edges incident to \(v\)  
    **In-degree / Out-degree** (directed): \($\deg$^{-}(v)\), \($\deg^{+}(v)\)
- **Walk / Trail / Path**:
    - **Walk**: sequence of vertices where consecutive vertices are connected by edges
    - **Trail**: walk with no repeated edges
    - **Path**: walk with no repeated vertices
- **Cycle**: a path that starts and ends at the same vertex (length \($\ge$ 1\))
- **Simple graph**: no loops and no multiple edges  
    **Multigraph**: may contain multiple edges between the same vertices  
    **Pseudograph**: may contain loops

### Handshaking Lemma (undirected)
\[
$\sum_{v \in V} \deg(v) = 2|E|$
\]  
A consequence: the number of vertices with **odd degree** is **even**.

## Visualization
```
Undirected Graph:        Directed Graph:
    A --- B                A ---> B
    |     |                |      |
    |     |                v      v
    C --- D                C ---> D
```

## Representation
- **Adjacency Matrix**: 2D array where matrix[i][j] indicates edge between vertex i and j
- **Adjacency List**: Array of linked lists, each list contains neighbors of a vertex
- **Edge List**: List of all edges as pairs of vertices

## Abstract Data Type
A graph can be represented as an Abstract Data Type (ADT) with the following operations:

- **Create**: Initialize an empty graph (optionally specify directed/undirected, weighted/unweighted).
- **Add Vertex**: Add a new vertex to the graph.
- **Add Edge**: Add an edge between two vertices (optionally with a weight/cost; direction depends on graph type).
- **Remove Vertex**: Remove a vertex and all incident edges.
- **Remove Edge**: Remove the edge between two vertices.
- **Get Neighbors**: Return the set/list of vertices adjacent to a given vertex (out-neighbors for directed graphs).
- **Has Edge**: Check whether an edge exists between two vertices.
- **Get Vertices**: Return all vertices currently in the graph.
- **Get Edges (optional)**: Return all edges currently in the graph.

These operations support building and querying graphs independently of the underlying representation (adjacency matrix, adjacency list, or edge list).

## Complexity
### Time Complexity
| Operation | Adjacency Matrix | Adjacency List |
|-----------|-----------------|----------------|
| Add Vertex | O(V²) | O(1) |
| Add Edge | O(1) | O(1) |
| Remove Vertex | O(V²) | O(V + E) |
| Remove Edge | O(1) | O(V) |
| Check Edge | O(1) | O(V) |
| Get Neighbors | O(V) | O(degree) |

### Space Complexity
- **Adjacency Matrix**: O(V²) - fixed space regardless of edge count
- **Adjacency List**: O(V + E) - space efficient for sparse graphs
- **Edge List**: O(E) - minimal space usage

## Common Algorithms
- **Traversal**: BFS O(V + E), DFS O(V + E)
- **Shortest Path**: Dijkstra O((V + E)logV), Bellman-Ford O(VE)
- **Minimum Spanning Tree**: Kruskal O(ElogE), Prim O(ElogV)

## Pros and Cons

### Pros
- **Flexible modeling**: represents many real-world relationships (networks, dependencies, routes).
- **Generalizes other structures**: trees, lists, and grids can be seen as special cases of graphs.
- **Rich algorithm toolbox**: traversal (BFS/DFS), shortest paths, connectivity, spanning trees, matching, etc.
- **Multiple representations**: choose adjacency matrix/list/edge list based on density and operations.
- **Scales to large systems**: sparse graphs with adjacency lists support efficient processing in practice.

### Cons
- **Implementation complexity**: more edge cases than trees (cycles, disconnected components, parallel edges, self-loops).
- **Algorithmic cost can be high**: some problems are expensive or intractable (e.g., NP-complete problems like Hamiltonian path).
- **Memory trade-offs**: adjacency matrices use **O(V²)** space, which is costly for large graphs.
- **Ambiguity without conventions**: directed vs undirected, weighted vs unweighted, and handling duplicates must be defined clearly.
- **Harder to visualize/debug**: large graphs are difficult to inspect compared to simpler structures.

## Variations
- **Directed vs Undirected**: edges have direction (arcs) or not.
- **Weighted vs Unweighted**: edges (or vertices) carry costs/weights.
- **Simple graph / Multigraph / Pseudograph**: no parallel edges/loops vs allowing them.
- **Connected vs Disconnected**: all vertices mutually reachable vs multiple components.
- **Cyclic vs Acyclic**:
    - **DAG** (Directed Acyclic Graph): used in scheduling, dependencies, compilers.
- **Complete graph** \(K_n\): every pair of distinct vertices is connected.
- **Bipartite graph**: vertices split into two sets; edges go only across sets (used in matching).
- **Planar graph**: drawable without edge crossings.
- **Tree / Forest**: connected acyclic undirected graph / collection of trees.
- **Special forms**: grid graphs, random graphs, hypergraphs (edges can connect > 2 vertices).
