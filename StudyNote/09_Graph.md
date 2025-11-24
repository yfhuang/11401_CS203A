# Study Note: Graph

## Description
A collection of vertices (nodes) connected by edges that can represent relationships between entities. 
Unlike trees, graphs can have cycles and edges can be directed or undirected. 
Graphs are used to model networks like social connections, transportation systems, or web pages with hyperlinks.

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
```
Graph ADT:
- addVertex(vertex): Add a new vertex
- addEdge(v1, v2): Add edge between vertices
- removeVertex(vertex): Remove vertex and its edges
- removeEdge(v1, v2): Remove edge between vertices
- getNeighbors(vertex): Get adjacent vertices
- hasEdge(v1, v2): Check if edge exists
- getVertices(): Get all vertices
```

## Time Complexity
| Operation | Adjacency Matrix | Adjacency List |
|-----------|-----------------|----------------|
| Add Vertex | O(V²) | O(1) |
| Add Edge | O(1) | O(1) |
| Remove Vertex | O(V²) | O(V + E) |
| Remove Edge | O(1) | O(V) |
| Check Edge | O(1) | O(V) |
| Get Neighbors | O(V) | O(degree) |

## Space Complexity
- **Adjacency Matrix**: O(V²) - fixed space regardless of edge count
- **Adjacency List**: O(V + E) - space efficient for sparse graphs
- **Edge List**: O(E) - minimal space usage

## Common Algorithms
- **Traversal**: BFS O(V + E), DFS O(V + E)
- **Shortest Path**: Dijkstra O((V + E)logV), Bellman-Ford O(VE)
- **Minimum Spanning Tree**: Kruskal O(ElogE), Prim O(ElogV)
