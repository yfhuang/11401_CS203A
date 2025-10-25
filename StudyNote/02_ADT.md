# Study Note: Abstract Data Type (ADT)

## Description
Abstract Data Types (ADTs) are a fundamental concept in computer science. They define a data structure purely in terms of its behavior, focusing on the supported operations and the rules for their use, rather than the implementation details.

## Abstract Data Type
An ADT specifies:
- A set of operations.
- The mathematical model of the data.

### Common Examples
- Stacks
- Queues
- Lists
- Sets

By abstracting implementation details, ADTs enable developers to concentrate on problem-solving without being concerned about low-level intricacies.

## Examples of ADTs

### Standard Template Library (STL)
The Standard Template Library (STL) in C++ exemplifies ADTs. It offers a collection of well-defined data structures such as:
- `vector`
- `list`
- `stack`
- `queue`

These data structures are defined by their behavior and supported operations, while their implementation details are abstracted. This separation allows developers to use them effectively without needing to understand their internal workings.

### Boost C++ Libraries
The Boost C++ Libraries also illustrate ADTs. In Boost:
- The library headers define the ADT by specifying the interface and behavior.
- The corresponding `.cpp` files provide the implementation.

This separation of interface and implementation aligns with ADT principles, enabling developers to utilize the library's features without delving into the underlying code.