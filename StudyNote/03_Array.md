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

## Time Complexity

## Space Complexity

