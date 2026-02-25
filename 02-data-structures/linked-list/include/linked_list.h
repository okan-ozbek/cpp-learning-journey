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
    ~linked_list();

    void pushFront(int value);
    void pushBack(int value);
    void insertBefore(int value, node* before);
    void insertAfter(int value, node* after);
    void remove(const node* node);
    void print() const;

    [[nodiscard]] node* findByIndex(std::size_t index) const;
    [[nodiscard]] node* findByValue(int value) const;
    [[nodiscard]] node* getHead() const;
    [[nodiscard]] node* getTail() const;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] std::size_t size() const;

private:
    std::size_t size_{0};
    node* head_{nullptr};
    node* tail_{nullptr};
};


#endif //CPP_LEARNING_JOURNEY_LINKED_LIST_H