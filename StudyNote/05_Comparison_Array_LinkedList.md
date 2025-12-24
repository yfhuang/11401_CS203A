# Comparison: Array vs. Linked List

## Summary

| Aspect | Array | Linked List |
|---|---|---|
| Memory layout | Contiguous | Non-contiguous (nodes) |
| Random access | **O(1)** index access | **O(n)** traversal |
| Insert/Delete (middle) | **O(n)** due to shifting | **O(1)** if you already have the node (otherwise **O(n)** to find) |
| Insert/Delete (front) | **O(n)** (shift) | **O(1)** (with head pointer) |
| Insert/Delete (end) | Amortized **O(1)** append (dynamic array), but may resize | **O(1)** with tail pointer; otherwise **O(n)** to reach end |
| Memory overhead | Low | Higher (pointers + allocator overhead) |
| Cache friendliness | **High** | Lower (pointer chasing) |
| Resize | Requires reallocation/copy (dynamic arrays) | Grows node-by-node without moving existing elements |

## When an Array is the Better Choice

- **Frequent random reads by index** (e.g., `a[i]`): arrays provide **O(1)** access.
- **Tight loops / performance-sensitive code**: contiguous memory is **cache-friendly**.
- **Memory efficiency matters**: minimal per-element overhead.
- **Mostly append + iterate**: dynamic arrays typically give fast amortized appends and fast traversal.

**Examples:** lookup tables, buffers, vectors of data for computation, storing items for sorting/searching by index.

## When a Linked List is the Better Choice

- **Frequent insertions/deletions near a known position**, especially near the **front**, where shifting an array would be costly.
- **Splicing/concatenation** (linking sequences) can be done by pointer updates without moving elements.
- **Unpredictable growth** without needing large contiguous blocks (though allocator overhead can be significant).

**Examples:** implementing stacks/queues (especially with O(1) push/pop at ends), adjacency lists in graphs, scenarios where you already hold node references and mutate structure often.

## Key Takeaways

- Choose **arrays** for **fast indexing and fast iteration**.
- Choose **linked lists** for **structural edits (insert/delete/splice)** when you can avoid repeated searches.
- For many real-world cases, dynamic arrays outperform linked lists due to **cache locality**, even when asymptotic complexity looks similar.