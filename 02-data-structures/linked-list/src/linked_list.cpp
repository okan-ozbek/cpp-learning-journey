//
// Created by Okan Ozbek on 2/24/2026.
//

#include "../include/linked_list.h"

#include <iostream>

void linked_list::push_front(node *node) {
    if (head_ == nullptr) {
        head_ = node;
        tail_ = node;
    }

    node->setPrev(nullptr);
    node->setNext(head_);

    head_->setPrev(node);
    head_ = node;
    size_++;
}

void linked_list::push_back(node *node) {
    if (tail_ == nullptr) {
        push_front(node);
        return;
    }

    tail_->setNext(node);

    node->setPrev(tail_);
    node->setNext(nullptr);

    tail_ = node;
    size_++;
}

void linked_list::insert_after(node *prev, node *node) {
    node->setPrev(prev);
    node->setNext(prev->getNext());

    prev->getNext()->setPrev(node);
    prev->setNext(node);
    size_++;
}


node* linked_list::findByValue(const int value) const {
    node* current = head_;

    while (current->getValue() != value) {
        if (current->getValue() == value) {
            return current;
        }

        current = current->getNext();
    }

    return nullptr;
}

void linked_list::remove(node *node) {
    if (node == head_) {
        node->getNext()->setPrev(nullptr);
        size_--;
        return;
    }

    if (node == tail_) {
        node->getPrev()->setNext(nullptr);
        size_--;
        return;
    }

    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());
    size_--;
}

void linked_list::print() const {
    if (size_ == 0) {
        std::cout << "List is empty!" << std::endl;
        return;
    }

    const node* current = head_;

    while (current != nullptr) {
        if (current == tail_) {
            std::cout << current->getValue() << std::endl;
        } else {
            std::cout << current->getValue() << " -> ";
        }

        current = current->getNext();
    }
}

bool linked_list::is_empty() const {
    return size_ == 0;
}

std::size_t linked_list::size() const {
    return size_;
}





