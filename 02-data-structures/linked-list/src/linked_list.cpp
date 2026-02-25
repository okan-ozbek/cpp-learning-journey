//
// Created by Okan Ozbek on 2/24/2026.
//

#include "../include/linked_list.h"

#include <iostream>

linked_list::~linked_list() {
    const node* current = head_;

    while (current != nullptr) {
        const node* next = current->getNext();
        delete current;

        current = next;
    }
}

void linked_list::pushFront(const int value) {
    auto* n = new node{value};

    if (head_ == nullptr) {
        head_ = tail_ = n;
        head_->setNext(nullptr);
        tail_->setPrev(nullptr);

        size_++;

        return;
    }

    n->setNext(head_);
    head_->setPrev(n);
    head_ = n;

    size_++;
}

void linked_list::pushBack(const int value) {
    auto* n = new node{value};

    if (head_ == nullptr) {
        head_ = tail_ = n;
        head_->setNext(nullptr);
        tail_->setPrev(nullptr);

        size_++;

        return;
    }

    if (tail_ == nullptr) {
        tail_ = n;
        tail_->setPrev(head_);
        head_->setNext(tail_);
        size_++;

        return;
    }

    tail_->setNext(n);
    n->setPrev(tail_);
    tail_ = n;

    size_++;
}

void linked_list::insertBefore(const int value, node* before) {
    if (before == nullptr) {
        return;
    }

    auto* n = new node{value};

    n->setNext(before);
    n->setPrev(before->getPrev());

    before->getPrev()->setNext(n);
    before->setPrev(n);

    size_++;
}

void linked_list::insertAfter(const int value, node* after) {
    if (after == nullptr) {
        return;
    }

    auto* n = new node{value};

    n->setNext(after->getNext());
    n->setPrev(after);

    after->getNext()->setPrev(n);
    after->setNext(n);

    size_++;
}

node* linked_list::findByIndex(std::size_t index) const {
    if (index >= size_) {
        return nullptr;
    }

    if (index == 0) {
        return head_;
    }

    if (index == size_ - 1) {
        return tail_;
    }

    node* current = head_;
    for (int i{0}; i < index; i++) {
        current = current->getNext();
    }

    return current;
}


node* linked_list::findByValue(const int value) const {
    node* current = head_;

    if (head_ == nullptr) {
        return nullptr;
    }

    while (current != nullptr) {
        if (current->getValue() == value) {
            return current;
        }
        current = current->getNext();
    }

    return nullptr;
}

node* linked_list::getHead() const {
    return head_;
}

node* linked_list::getTail() const {
    return tail_;
}

void linked_list::remove(const node *node) {
    if (node == head_) {
        head_ = head_->getNext();
    }

    if (node == tail_) {
        tail_ = tail_->getPrev();
    }

    if (node->getPrev() != nullptr) {
        node->getPrev()->setNext(node->getNext());
    }

    if (node->getNext() != nullptr) {
        node->getNext()->setPrev(node->getPrev());
    }

    delete node;
    size_--;
}

void linked_list::print() const {
    if (size_ == 0) {
        std::cout << "List is empty!" << std::endl;
        return;
    }

    const node* current = head_;
    while (current != nullptr) {
        std::cout << current->getValue() << " ";
        current = current->getNext();
    }
}

bool linked_list::isEmpty() const {
    return size_ == 0;
}

std::size_t linked_list::size() const {
    return size_;
}





