//
// Created by Okan Ozbek on 2/24/2026.
//

#ifndef CPP_LEARNING_JOURNEY_NODE_H
#define CPP_LEARNING_JOURNEY_NODE_H


class node {
public:
    explicit node(int value, node* next = nullptr, node* prev = nullptr) : value_{}, next_{nullptr}, prev_{nullptr} {
        value_ = {value};
        next_ = {next};
        prev_ = {prev};
    }

    ~node() = default;

    int getValue() const;
    void setValue(int value);

    node* getNext() const;
    void setNext(node* next);

    node* getPrev() const;
    void setPrev(node* prev);

private:
    int value_;
    node* next_;
    node* prev_;
};


#endif //CPP_LEARNING_JOURNEY_NODE_H