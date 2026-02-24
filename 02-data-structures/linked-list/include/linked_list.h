//
// Created by Okan Ozbek on 2/24/2026.
//

#ifndef CPP_LEARNING_JOURNEY_LINKED_LIST_H
#define CPP_LEARNING_JOURNEY_LINKED_LIST_H
#include <cstddef>

#include "node.h"


class linked_list {
public:
    linked_list() = default;

    void push_front(node* node);
    void push_back(node* node);
    void insert_after(node* prev, node* node);
    void remove(node* node);
    void print() const;

    [[nodiscard]] node* findByValue(int value) const;
    [[nodiscard]] bool is_empty() const;
    [[nodiscard]] std::size_t size() const;

private:
    std::size_t size_{0};
    node* head_{nullptr};
    node* tail_{nullptr};
};


#endif //CPP_LEARNING_JOURNEY_LINKED_LIST_H