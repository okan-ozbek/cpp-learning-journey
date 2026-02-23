//
// Created by Dorza on 2/23/2026.
//

#include <iostream>

#include "../include/ceasar_cypher.h"

int main() {
    using memory_experiments::ceasar_cypher;

    const ceasar_cypher cypher(3);

    std::string message = "abcxyz";

    std::cout << message << std::endl;

    cypher.shift(&message);

    std::cout << message << std::endl;

    cypher.unshift(&message);

    std::cout << message << std::endl;

    return 0;
}
