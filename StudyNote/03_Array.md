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

## Time Complexity

## Space Complexity
