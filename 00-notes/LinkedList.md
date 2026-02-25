# Bugs
### 1. `push_front` — corrupts list when non-empty
   When the list is not empty, you still fall through past the if block. The first node added gets its `prev` set to itself.
```c++
void linked_list::push_front(node *node) {
   if (head_ == nullptr) {
      head_ = node;
      tail_ = node;
      node->setPrev(nullptr);
      node->setNext(nullptr);
      size_++;
      return;               // <-- must return here
   }

   node->setPrev(nullptr);
   node->setNext(head_);
   head_->setPrev(node);
   head_ = node;
   size_++;
}
```
### 2. `findByValue` — logic is inverted and will crash
   The while condition already checks the value, so the inner if is dead code. It also dereferences nullptr when the value isn't found.
```c++
node* linked_list::findByValue(const int value) const {
   node* current = head_;

   while (current != nullptr) {      // guard against nullptr
      if (current->getValue() == value) {
         return current;
      }
      current = current->getNext();
   }

   return nullptr;
}
```
### 3. `insert_after` — crashes when inserting after tail
   `prev->getNext()` is `nullptr` at the tail, so `->setPrev(node)` segfaults. Also doesn't update `tail_`.
```c++
void linked_list::insert_after(node *prev, node *newNode) {
   newNode->setPrev(prev);
   newNode->setNext(prev->getNext());

   if (prev->getNext() != nullptr) {
      prev->getNext()->setPrev(newNode);
   } else {
      tail_ = newNode;
   }

   prev->setNext(newNode);
   size_++;
}
```
### 4. `remove` — doesn't update `head_`/`tail_`, crashes on single-element list
   When removing the only node, `node->getNext()` is `nullptr`.
```c++
void linked_list::remove(node *node) {
   if (node == head_) {
      head_ = node->getNext();
   }
   
   if (node == tail_) {
      tail_ = node->getPrev();
   }
   
   if (node->getPrev() != nullptr) {
      node->getPrev()->setNext(node->getNext());
   }
   
   if (node->getNext() != nullptr) {
      node->getNext()->setPrev(node->getPrev());
   }
   
   size_--;
}
```
### Should the list own the nodes?
Yes — the list should own its nodes. The current design forces the caller to manage node lifetimes, which leads to:
No delete anywhere → memory leaks
Dangling pointers if the caller frees a node still in the list
No destructor cleaning up nodes
The standard approach: the list allocates nodes internally and exposes values, not nodes.
```c++
void linked_list::push_front(int value) {
    auto* n = new node(value);
    // ... link it in ...
}

void linked_list::remove(node* n) {
   // ... unlink ...
   delete n;
}

linked_list::~linked_list() {
   node* current = head_;
   
   while (current != nullptr) {
      node* next = current->getNext();
      delete current;
      current = next;
   }
}
```
This way the list fully manages memory, the user only passes int values, and the destructor prevents leaks. You can still return `node*` from `findByValue` for O(1) removal, but the user should never delete them directly.