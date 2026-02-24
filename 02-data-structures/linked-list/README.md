# LinkedList

## Definition
1. A linked list is a dynamic linear data structure made of `Node` objects.
2. Each `Node` holds a value and one or more pointers (e.g. `next`, and optionally `prev`);
3. The list is accessed via a `head` pointer; an optional `tail` pointer points to the last node.

## Purpose 
1. Store a sequence of elements with dynamic size (no contiguous memory required).
2. Support cheap insertions and removals when you already have a pointer to the insertion/removal position (constant time).
3. Useful when element count changes a lot or when you must splice lists without copying large blocks

## Core criteria / invariants to satisfy
1. Node structure: contains the payload and required pointer(s).
2. `head` is `nullptr` for an empty list. If you keep `tail`, it should point to the last node or be `nullptr` when empty.
3. Pointer integrity: `next`/`prev` links must always be consistent (no dangling pointers).
4. Proper ownership and memory management: no leaks, free nodes on removal and on destruction.
5. Provide a clear API: create/destroy, `is_empty`, `size` (optional cached), `push_front`, `push_back`, `insert_after`, `remove`, `find`, and iteration.
6. Maintain expected complexity: O(1) for push/pop at head (and tail if `tail` maintained), O(n) for random access or searches.

## Tradeoffs / performance
1. Pros: dynamic size, O(1) insert/remove at known positions, easy splicing.
2. Cons: O(n) random access, extra memory per element for pointers, poorer cache locality than arrays.

## Minimal tests to include
1. Empty list behavior (`is_empty`, `size`).
2. Single-element insert/remove.
3. Insert/remove at head, tail, and middle.
4. Iteration order correctness.
5. Memory/leak checks and repeated insert/remove stability.