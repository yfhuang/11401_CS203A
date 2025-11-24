# Study Note: Heap

## Description
A heap is a complete binary tree that satisfies the heap-order property.

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

## Time Complexity
- **Insert**: O(log n) - may need to bubble up
- **Extract Max/Min**: O(log n) - may need to bubble down
- **Peek**: O(1) - just return root
- **Build Heap**: O(n) - using bottom-up approach
- **Heapify**: O(log n) - restore heap property

## Space Complexity
- **Array representation**: O(n) - stores n elements
- **No additional space needed** for pointers (unlike other tree structures)
- **Parent-child relationships**: 
  - Parent of node at index i: (i-1)/2
  - Left child of node at index i: 2i+1
  - Right child of node at index i: 2i+2
