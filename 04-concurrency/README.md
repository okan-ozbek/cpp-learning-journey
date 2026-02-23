# Concurrency

This directory explores multithreading and concurrent programming in C++.

Concurrency is a critical component of modern high-performance systems, enabling applications to utilize multiple CPU cores efficiently.

The projects here focus on:

* Thread management
* Synchronization primitives
* Race condition avoidance
* Parallel performance measurement

## Why This Matters

Quantitative trading and low-latency systems rely heavily on concurrency to process data streams, execute strategies, and handle network events simultaneously.

Understanding concurrency is essential for:

* Performance engineering
* Lock-free programming
* Systems design
* Scalability

## Subfolders

### prime-finder/

Multithreaded prime number computation.

Concepts covered:

* Work distribution
* Thread creation and joining
* Performance comparison between single and multi-threaded approaches

### producer-consumer/

Implementation of the classic producer-consumer pattern.

Concepts covered:

* Mutexes
* Condition variables
* Shared buffers
* Synchronization patterns

### thread-pool/

Thread pool implementation for task execution.

Concepts covered:

* Task queues
* Worker threads
* Scheduling strategies
* Resource reuse
