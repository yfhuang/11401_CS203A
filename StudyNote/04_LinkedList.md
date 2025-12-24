# Study Note: Linked List

## Description  

Linked List: A linked list is a sequence of nodes stored in non-contiguously memory. Each node contains a value field and a pointer field that links to the next node. Traversal is sequential O(n), but insertion or deletion (given a node) is O(1).

## Transition: From Arrays to Linked Lists

You can think of a linked list as an "array-like" sequence where adjacency is not implied by memory location. Instead, each element (node) explicitly stores a pointer to the next element:

- In an **array**, elements are placed **contiguously**, so the “next” element is found by index (e.g., `i + 1`).
- In a **linked list**, elements are **not contiguous**; each node stores a **`next` pointer** that tells you where the next node is.

So the transition is:

> **Array element + explicit pointer to the next element ⇒ Linked List node**

Each node looks like:

- `value`: the data
- `next`: a reference/pointer to the next node (or `null` if it is the last node)

## Visualization

![Linked List](./images/LinkedList.png)

## Abstract Data Type

A linked list can be represented as an Abstract Data Type (ADT) with the following operations:

- **Create**: Initialize an empty linked list.
- **Insert**: Add a new node with a given value at a specific position.
- **Delete**: Remove a node at a specific position.
- **Search**: Find a node containing a specific value.
- **Traverse**: Visit each node in the linked list sequentially.
- **Update**: Modify the value of a node at a specific position.

These operations allow for dynamic memory usage and efficient insertion/deletion compared to arrays.

## Complexity
### Time Complexity

Let \(n\) be the number of nodes.

- **Access / Traverse (by index)**: \(O(n)\) — must walk node-by-node from the head.
- **Search (by value)**: \(O(n)\) — linear scan.
- **Insert**
    - **At head**: \(O(1)\)
    - **At tail**: \(O(1)\) if a tail pointer is maintained; otherwise \(O(n)\)
    - **At position / after a given node**: \(O(n)\) to locate the position, then \(O(1)\) to relink pointers
- **Delete**
    - **At head**: \(O(1)\)
    - **Given a node / predecessor is known**: \(O(1)\)
    - **By value / at position**: \(O(n)\) to locate, then \(O(1)\) to unlink
- **Update (by index)**: \(O(n)\) to reach the node, then \(O(1)\) to modify the value

### Space Complexity

- **Storage for nodes**: \(O(n)\)
- **Per-node overhead**: \(O(1)\) extra space for pointer(s) (one `next` for singly linked lists; `prev` + `next` for doubly linked lists)
- **Auxiliary space for typical operations**: \(O(1)\) (iterative traversal); recursive traversal would use \(O(n)\) call stack

## Pros & Cons

### Pros

- **Dynamic size**: Grows/shrinks at runtime without needing to reallocate a contiguous block.
- **Fast insert/delete when node (or predecessor) is known**: Pointer relinking is \(O(1)\), especially at the head.
- **No contiguous memory requirement**: Works well even when memory is fragmented.
- **Convenient for certain structures**: Natural building block for stacks/queues (especially with head/tail pointers) and adjacency lists.

### Cons

- **Slow random access**: No direct indexing; accessing the \(i\)-th element requires traversal \(O(n)\).
- **Extra memory overhead**: Each node stores one or more pointers (`next`, optionally `prev`).
- **Poor cache locality**: Nodes may be scattered in memory, often slower than arrays in practice.
- **More pointer/edge-case complexity**: Must handle `null` pointers, head/tail updates, and potential memory management issues.
- **Search remains linear**: Finding by value is typically \(O(n)\), same as an unsorted array.

## Variations

- **Singly Linked List**: Each node stores a value and a pointer to the next node (`next`). Traversal is one-way.
- **Circular Linked List**: The last node points back to the first node (the `next` of the tail is the head). This is useful for round-robin scheduling and cyclic data processing. Circular lists can be singly or doubly linked.
- **Doubly Linked List**: Each node stores pointers to both the previous and next nodes (`prev`, `next`), enabling bidirectional traversal. This can make deletions and insertions (given a node) easier, at the cost of extra memory and pointer maintenance.
- **Circular Doubly Linked List**: A combination where `tail.next = head` and `head.prev = tail`, supporting efficient forward/backward cycling through nodes.
