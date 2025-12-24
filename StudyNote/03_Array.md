# Study Note: Array

## Description  

Array: A contiguous block of memory that stores elements of the same data type. Arrays provide O(1) random access to elements by index, but insertion and deletion operations in the middle are costly O(n) due to the need to shift elements.

## Visualization  

![Array](./images/Array.png)

## Abstract Data Type

An array is an abstract data type (ADT) that represents a collection of elements, each identified by at least one array index or key. The array ADT supports the following operations:

- **Access**: Retrieve the value of an element at a specific index. Time complexity: O(1).
- **Update**: Modify the value of an element at a specific index. Time complexity: O(1).
- **Insert**: Add an element at a specific position, shifting subsequent elements. Time complexity: O(n).
- **Delete**: Remove an element at a specific position, shifting subsequent elements. Time complexity: O(n).
- **Traversal**: Visit each element in the array sequentially. Time complexity: O(n).

Arrays are widely used due to their simplicity and efficiency in accessing elements by index.

## Array Declaration

### Static Array

#### Declaration
```c
// 1D array with five elements
int array[5];
```

#### Initialization
```c
// Initialize the integer array with 10, 20, 30, 40, 50
int array[5] = {10, 20, 30, 40, 50};

// Initialize by for loop
for (int i = 0; i < 5; i++) {
    array[i] = i + 1;
}
```

#### Access
```c
// Retrieve the third element from array
printf("%d", array[2]);
```

#### Traverse
```c
// Traverse the entire array and print
for (int i = 0; i < 5; i++) {
    printf("%d", array[i]);
}
```

### Resize

Static arrays are allocated at **compile time**, so their size is fixed and **cannot be resized** during runtime; to change the size, you must declare a new array (or use a dynamic array instead).

### Dynamic Array

#### Declaration
```c
// Dynamic array initialization by malloc()
int *array;
int n = 10;
array = (int *) malloc(n * sizeof(int));
```

#### Initialization
```c
// Initialize by for loop
for (int i = 0; i < n; i++) {
    array[i] = i + 1;
}
```

#### Access
```c
// Access the element by index
for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
}
```

#### Traverse
```c
// Traverse the entire array and print
for (int i = 0; i < 5; i++) {
    printf("%d", array[i]);
}
```

### Resize

To resize a dynamic array, you can use the `realloc` function to allocate more memory. Below is an example:

```c
int *array;
int n = 10;
array = (int *) malloc(n * sizeof(int));

// Initialize the array
for (int i = 0; i < n; i++) {
    array[i] = i + 1;
}

// Double the size of the array
n = n * 2;
int *temp = (int *) realloc(array, n * sizeof(int));

if (temp == NULL) {
    free(array);
    return -1; // Handle memory allocation failure
}

array = temp;

// Initialize the new elements
for (int i = n / 2; i < n; i++) {
    array[i] = i + 1;
}
```

This code demonstrates how to resize a dynamic array, ensuring that the new memory is properly initialized and handling potential memory allocation failures.

## Complexity

### Time Complexity

Let \(n\) be the number of elements in the array.

- **Access (read by index)**: \(O(1)\)
- **Update (write by index)**: \(O(1)\)
- **Traversal (visit all elements)**: \(O(n)\)
- **Search**
    - **Unsorted array (linear search)**: \(O(n)\)
    - **Sorted array (binary search)**: \(O(log n)\)
- **Insert**
    - **At end (if capacity available, e.g., dynamic array)**: amortized \(O(1)\)
    - **At end (if reallocation needed)**: \(O(n)\)
    - **At beginning or middle**: \(O(n)\) (shift elements)
- **Delete**
    - **At end**: \(O(1)\)
    - **At beginning or middle**: \(O(n)\) (shift elements)

### Space Complexity

- **Storage for elements**: \(O(n)\)
- **Auxiliary space for operations (typical)**: \(O(1)\)
- **Dynamic array extra capacity**: \(O(n)\) total allocated space; unused capacity can be up to \(O(n)\) depending on the growth strategy.
- **Resizing (`realloc`)**: \(O(1)\) extra space if grown in place; up to \(O(n)\) extra space temporarily if a new block is allocated and elements are copied.

## Pros & Cons

### Pros

- **O(1) random access** by index for reads/writes.
- **Cache-friendly** due to contiguous memory layout; fast traversal in practice.
- **Low overhead**: minimal per-element metadata compared to linked structures.
- **Simple and predictable**: straightforward indexing and iteration.
- **Dynamic arrays can grow** (via `realloc`) to accommodate more elements when used appropriately.

### Cons

- **Static arrays have fixed size** (decided at compile time); cannot resize without creating a new array.
- **Insert/Delete in the middle is expensive**: requires shifting elements, \(O(n)\).
- **Resizing dynamic arrays can be costly**: `realloc` may allocate a new block and copy elements, \(O(n)\), and may invalidate old pointers.
- **Memory limits still apply**: dynamic arrays are constrained by available physical memory / OS-managed heap and allocation fragmentation.
- **Usage matters**: frequent small growth/shrink operations can cause performance issues; growth strategies (e.g., doubling capacity) are important.
- **Manual memory management (in C)**: must `free` memory; risk of leaks or use-after-free bugs.


## Two Sum

> Origin: LeetCode — [Two Sum](https://leetcode.com/problems/two-sum/)

### Problem
Given an integer array `array` and an integer `target`, find **two different indices** `i` and `j` such that:

\[
array[i] + array[j] = target,\quad i \ne j
\]

Return the indices (or report not found).

---

### Approach: Brute Force (Two Loops)
Check all pairs `(i, j)`.

- **Time**: \(O(n^2)\)  
- **Space**: \(O(1)\)

```c
#include <stdio.h>

int two_sum_bruteforce(const int array[], int n, int target, int *out_i, int *out_j) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] + array[j] == target) {
                *out_i = i;
                *out_j = j;
                return 1; // found
            }
        }
    }
    return 0; // not found
}
```
