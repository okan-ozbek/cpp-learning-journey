//
// Created by Okan Ozbek on 2/24/2026.
//

#include "../include/node.h"

int node::getValue() const {
    return value_;
}

node* node::getNext() const {
    return next_;
}

node* node::getPrev() const {
    return prev_;
}

void node::setValue(const int value) {
    value_ = value;
}

void node::setNext(node* next) {
    next_ = next;
}

void node::setPrev(node* prev) {
    prev_ = prev;
}
