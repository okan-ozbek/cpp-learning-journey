//
// Created by Dorza on 2/24/2026.
//

#ifndef CEASAR_CYPHER_CEASAR_CYPHER_H
#define CEASAR_CYPHER_CEASAR_CYPHER_H
#include <string>

namespace memory_experiments {
    class ceasar_cypher {
    public:
        explicit ceasar_cypher(unsigned int shift);

        void shift(std::string* message) const;

        void unshift(std::string* message) const;

    private:
        unsigned int shift_{};
        unsigned char a_{'a'};
        unsigned char z_{'z'};

        void rotate_to_start(char& c) const;
        void rotate_to_end(char& c) const;
    };
} // memory_experiments

#endif //CEASAR_CYPHER_CEASAR_CYPHER_H