//
// Created by Okan Ozbek on 2/24/2026.
//

#include <iostream>

#include "../include/linked_list.h"

int main() {
    linked_list list{};

    node n1 {1};
    node n2 {2};
    node n3 {3};
    node n4 {4};

    // List is empty!
    list.print();

    // 1 -> 2 -> 3
    list.push_back(&n1);
    list.push_back(&n2);
    list.push_back(&n3);
    list.print();

    // 1 -> 3
    list.remove(&n2);
    list.print();

    // 1 -> 4 -> 3
    list.insert_after(&n1, &n4);
    list.print();

    // 4
    const node* value1 {list.findByValue(4)};
    std::cout << value1->getValue() << std::endl;

    // TODO: Why doesn't this work properly?
    if (const node* value2 {list.findByValue(7)}; value2 == nullptr) {
        std::cout << "Value not found!" << std::endl;
    }

    return 0;
}
