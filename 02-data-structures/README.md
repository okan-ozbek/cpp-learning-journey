# Data Structures

This directory contains custom implementations of fundamental data structures.

Rather than relying solely on the C++ Standard Library, these implementations are written from scratch to develop a deeper understanding of:

* Memory layout
* Pointer manipulation
* Cache behavior
* Performance characteristics
* Trade-offs between different structures

## Why This Matters

High-performance systems frequently require specialized or optimized data structures. Understanding how data structures work internally is essential for:

* Low-latency engineering
* Systems programming
* Performance optimization
* Interview preparation

Engineers who understand memory and data layout can design faster systems.

## Subfolders

### dynamic-array/

Implementation of a vector-like container.

Concepts covered:

* Dynamic memory allocation
* Capacity growth strategies
* Copy and move semantics
* Iterator basics

### linked-list/

Implementation of singly or doubly linked lists.

Concepts covered:

* Pointer manipulation
* Node ownership
* Memory fragmentation considerations
* Traversal complexity

### stack/

Stack implementation using either arrays or linked structures.

Concepts covered:

* LIFO behavior
* Abstraction over underlying storage
* Constant-time operations

### queue/

Queue implementation demonstrating FIFO behavior.

Concepts covered:

* Circular buffers
* Efficient enqueue/dequeue operations
* Memory reuse

### hash-table/

Custom hash table implementation.

Concepts covered:

* Hash functions
* Collision resolution
* Load factors
* Performance trade-offs
