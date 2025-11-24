# Study Note: Tree

## Description

A Tree is a non-linear hierarchical data structure consisting of connected nodes without cycles. Each node may have zero or more children, forming parent–child relationships, and the entire structure represents hierarchical data (file systems, organization charts, decision models).

**Binary Tree**: A special tree where each node has at most two children (left and right).

**Binary Search Tree (BST)**: A binary tree where nodes satisfy: Left subtree < Parent < Right subtree.

## Visualization

### Tree Structure
- Hierarchical nodes
- Root, internal nodes, leaf nodes, edges
- Left/right children (binary tree)
- Levels, depth (height), and subtrees

### Binary Tree
```
         A
      /    \
     B      C
    /  \    /
   D   E  F
```

### Binary Search Tree (BST)
```
         52
      /     \
    18       82
   /  \     /  \
  7   36  69   95
```

### Array Representation (Binary Tree/BST)
Binary Tree (level-order): index-based storage
- Parent at i
- Left child = 2i
- Right child = 2i + 1

## Abstract Data Type

**Binary Tree Operations:**
- `Create()`: create an empty binary tree
- `IsEmpty(bt)`: true if bt is empty
- `MakeBT(bt1, item, bt2)`: construct a new binary tree with left subtree bt1, item as root, right subtree bt2
- `Lchild(bt)`: return left subtree
- `Rchild(bt)`: return right subtree
- `Data(bt)`: return item at root

**Implementation Approaches:**
1. **Pointer-based representation** (common for BST)
2. **Array-based representation** (heaps, complete trees)
3. **Left Child–Right Sibling Representation** (general trees)

**Traversal Algorithms:**
- Preorder (root-left-right)
- Inorder (left-root-right)
- Postorder (left-right-root)
- Level-order (BFS with queue)

## Time Complexity

**Balanced Binary Search Tree:**
- Search: O(log n)
- Insert: O(log n)
- Delete: O(log n)

**Unbalanced Tree (worst case):**
- Search: O(n)
- Insert: O(n)
- Delete: O(n)

## Space Complexity

- **Pointer-based**: O(n) for n nodes
- **Array-based**: O(capacity) - may waste space for sparse trees
- **Traversal**: O(h) where h is height (recursion stack)

**Characteristics:**
- Non-linear, hierarchical
- One root node
- Nodes connected by edges
- Each node has zero or more children
- Supports various traversal methods

**Limitations:**
- Performance depends on tree shape
- Unbalanced trees degrade to linked lists
- Array implementation can be space-inefficient
- Maintaining balance requires complex algorithms
