//
// Created by Okan Ozbek on 2/24/2026.
//

#include <iostream>

#include "../include/linked_list.h"

#pragma region SIMPLE_ALLOCATION_CHECKER
static int alloc_count = 0;

void* operator new(std::size_t size) {
    alloc_count++;
    return std::malloc(size);
}

void operator delete(void* ptr) noexcept {
    alloc_count--;
    std::free(ptr);
}

void operator delete(void* ptr, std::size_t size) noexcept {
    alloc_count--;
    std::free(ptr);
}
#pragma endregion

int main() {
    {
        std::cout << "Alloc count 1: " << alloc_count << std::endl;
        linked_list list{};

        list.pushBack(1);
        list.pushBack(2);
        list.pushBack(3);
        list.remove(list.findByIndex(0));
        list.print();
        std::cout << "\nAlloc count 2: " << alloc_count << std::endl;
    }

    std::cout << "Alloc count 3: " << alloc_count << std::endl;
    return 0;
}
