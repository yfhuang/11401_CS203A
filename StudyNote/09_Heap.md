# Study Note: Heap

## Description

Heap: A complete binary tree (typically stored in an array) that satisfies the heap-order property—**max-heap**: each parent ≥ its children; **min-heap**: each parent ≤ its children. Heaps provide **O(1)** access to the extreme element (root) and **O(log n)** insertion and deletion (via sift up/down), making them ideal for **priority queues** and **heap sort**.

### Shape Property (Structure)
The heap is a complete binary tree:
- Every level is completely filled, except possibly the last level.
- The last level's nodes are filled from left to right.
- This property guarantees that the heap can be stored efficiently in an array (no gaps).

### Heap Property (Order)
**Max heap:**
- Each parent node's key is always greater than or equal to their children (parent ≥ children).
- The maximum element is always at the root.

**Min heap:**
- Each parent node's key is always less than or equal to their children (parent ≤ children).
- The minimum element is always at the root.

Heaps are commonly used to implement priority queues and for heap sort algorithms.

## Visualization
```
Max Heap Example:        Min Heap Example:
      100                      1
     /   \                    / \
    80    90                 3   2
   / \   / \                / \ / \
  70 60 85 75              7  5 8  4
```

## Abstract Data Type
- **Insert(key)**: Add a new element to the heap
- **ExtractMax/Min()**: Remove and return the root element
- **Peek()**: Return the root element without removing it
- **IncreaseKey/DecreaseKey(index, newKey)**: Update a key value
- **Delete(index)**: Remove element at specific index
- **BuildHeap(array)**: Convert an array into a heap

## Complexity
### Time Complexity
- **Insert**: O(log n) - may need to bubble up
- **Extract Max/Min**: O(log n) - may need to bubble down
- **Peek**: O(1) - just return root
- **Build Heap**: O(n) - using bottom-up approach
- **Heapify**: O(log n) - restore heap property

### Space Complexity
- **Array representation**: O(n) - stores n elements
- **No additional space needed** for pointers (unlike other tree structures)
- **Parent-child relationships**: 
  - Parent of node at index i: (i-1)/2
  - Left child of node at index i: 2i+1
  - Right child of node at index i: 2i+2

## Pros and Cons

### Pros
- **Efficient priority access**: Peek (min/max) is **O(1)**; extract is **O(log n)**.
- **Fast insertion**: Insert is **O(log n)** and works well for dynamic workloads.
- **Space-efficient representation**: Uses a compact **array layout** (complete binary tree) with **O(n)** space and good cache locality.
- **Strong for scheduling/selection**: Well-suited for **priority queues**, event simulation, and **top-k** queries.
- **In-place sorting option**: Heap sort runs in **O(n log n)** time and **O(1)** extra space (in-place).

### Cons
- **Slow search for arbitrary keys**: Finding a specific element is typically **O(n)** (no global ordering like a BST).
- **Limited ordered operations**: Operations like predecessor/successor, range queries, or iteration in sorted order are inefficient.
- **Update/delete-by-index needs extra support**: Decrease/increase-key or delete often requires knowing the element’s index (commonly needs an auxiliary map), adding complexity.
- **Not stable for sorting**: Heap sort is **not stable** by default.
- **Worse constants than some alternatives**: For some workloads, balanced BSTs or specialized queues can outperform heaps despite similar asymptotic bounds.


## Variations

Common heap variations include:

- **Binary Heap**: The standard heap (min-heap or max-heap) using a complete binary tree; typically stored in an array.
- **d-ary Heap**: Each node has up to *d* children (e.g., 4-ary heap). Can reduce tree height and sometimes speed up decrease-key operations in practice.
- **Binomial Heap**: A collection of binomial trees supporting efficient *merge (union)* operations; useful for meldable priority queues.
- **Fibonacci Heap**: An advanced meldable heap with very fast amortized operations (notably *decrease-key*), often used in theoretical analyses (e.g., Dijkstra’s algorithm).
- **Pairing Heap**: A simpler meldable heap with good practical performance; often used as a Fibonacci-heap alternative.
- **Leftist Heap**: A meldable heap that maintains a “null-path length” property to keep the tree skewed for efficient merges.
- **Skew Heap**: A self-adjusting meldable heap; merge is simple and does not require storing balance information.
- **Min-Max Heap**: Supports both **FindMin** and **FindMax** efficiently by alternating min/max levels in the tree.
- **Double-Ended Priority Queue (DEPQ)**: A structure (often implemented via min-max heap or interval heap) supporting efficient extraction of both min and max.
- **Interval Heap**: Stores elements in node intervals \[min, max\] to support double-ended operations efficiently.
- **Soft Heap**: An approximate heap that allows some keys to become “corrupted” to achieve faster amortized performance (useful in certain selection algorithms).
- **Beap (Bi-parental Heap)**: A 2D heap-like structure supporting efficient search with array-based storage.
- **Treap (Tree + Heap)**: A randomized BST where priorities satisfy heap order while keys satisfy BST order; supports expected logarithmic search/insert/delete.
