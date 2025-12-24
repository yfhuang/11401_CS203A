# Study Note: Tree

## Description

A Tree is a non-linear hierarchical data structure consisting of connected nodes without cycles. Each node may have zero or more children, forming parent–child relationships, and the entire structure represents hierarchical data (file systems, organization charts, decision models).

## Transition: Linked List → Tree (Pointers → Hierarchy)

A **linked list** is the simplest pointer-based structure: each node stores data and a pointer to the *next* node, forming a **linear** chain.

A **tree** generalizes this idea by letting each node store pointers to **multiple** other nodes (its children), forming a **hierarchy** instead of a single sequence:
- A node can have **0..k child pointers** (general tree), or **up to 2** (binary tree).
- The structure has a **root** (entry point), and every node (except the root) has **exactly one parent**.
- With pointers branching outward, relationships become **parent → children**, enabling multi-level organization (subtrees).

In short:  
**Linked list = one “next” pointer (1D)** → **Tree = multiple child pointers (hierarchical / multi-level)**.

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


## Complexity
### Time Complexity

**Balanced Binary Search Tree:**
- Search: O(log n)
- Insert: O(log n)
- Delete: O(log n)

**Unbalanced Tree (worst case):**
- Search: O(n)
- Insert: O(n)
- Delete: O(n)

### Space Complexity

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

## Pros and Cons

### Pros
- **Represents hierarchy naturally**: models parent–child relationships directly (folders, org charts, syntax trees).
- **Efficient search when ordered/balanced**: in a balanced BST, search/insert/delete are typically **O(log n)**.
- **Supports multiple access patterns**: traversals (pre/in/post/level-order) enable sorted output, expression evaluation, and systematic visiting.
- **Flexible for many problem types**: variations (heap, trie, B-tree, segment tree) fit different needs like priority queues, prefix search, disk indexing, and range queries.
- **Localizes work to subtrees**: many operations (queries/updates) can be confined to a subtree, which helps in divide-and-conquer solutions.

### Cons
- **Performance depends on shape**: unbalanced trees can degrade to a linked-list-like structure, making operations **O(n)**.
- **More complex than linear structures**: implementation and debugging (pointers, recursion, rotations) are harder than arrays/linked lists.
- **Extra memory overhead**: pointer-based nodes store child pointers (and sometimes parent pointers/balance metadata), increasing per-node space.
- **Recursion depth risk**: recursive traversals can overflow the call stack on very deep trees; iterative traversal may be needed.
- **Choosing the right tree matters**: the “wrong” variant (e.g., BST without balancing, array-based tree when sparse) can cause poor time or space efficiency.

## Variations

### General Tree (k-ary / Multiway Tree)
- Each node can have **0..k** children (not limited to 2).
- Common representation: **Left-Child Right-Sibling (LCRS)** to store a general tree using binary-tree pointers.

### Binary Tree
- Each node has **at most 2 children**: `left`, `right`.
- Special cases:
   - **Full Binary Tree**: every internal node has exactly 2 children.
   - **Perfect Binary Tree**: all internal nodes have 2 children and all leaves are at the same level.
   - **Complete Binary Tree**: all levels filled except possibly the last, filled left-to-right (good for array storage).

### Binary Search Tree (BST)
- Ordering property:
   - `left subtree < root < right subtree`
- Enables ordered operations (search/min/max/successor), but can degrade to **O(n)** if unbalanced.

### Self-Balancing BST
- Maintains height close to **O(log n)** using rotations.
- Examples:
   - **AVL Tree**: strict balance (balance factor −1/0/+1), faster lookup, more rotations on updates.
   - **Red–Black Tree**: looser balance, fewer rotations, widely used in libraries (e.g., maps/sets).

### Heap (Priority Queue Tree)
- **Complete binary tree** with heap-order property:
   - **Max-Heap**: parent ≥ children
   - **Min-Heap**: parent ≤ children
- Efficient operations:
   - Insert / delete-root: **O(log n)**
   - Peek root: **O(1)**
- Typically stored in an **array**.

### B-Tree Family (Multiway Balanced Search Trees)
- Optimized for **disk/IO** and large branching factors.
- **B-Tree**: all keys stored in internal nodes too; balanced height.
- **B+ Tree**: all records/keys stored in leaves; leaves often linked for fast range queries.

### Trie (Prefix Tree)
- Stores strings by characters along root-to-leaf paths.
- Operations are **O(L)** where `L` is the string length (independent of number of stored keys).
- Variants: **Compressed Trie / Radix Tree** (path compression to reduce nodes).

### Spatial / Specialized Trees (Common in Practice)
- **Expression Tree**: represents arithmetic/boolean expressions (useful with inorder/postorder evaluation).
- **Segment Tree**: range query + updates in **O(log n)** (e.g., sum/min/max on intervals).
- **Fenwick Tree (BIT)**: compact structure for prefix sums with **O(log n)** update/query.
- **k-d Tree / Quadtree**: partition space for nearest-neighbor and range searching.
- **Decision Tree**: hierarchical decision model used in ML/classification.