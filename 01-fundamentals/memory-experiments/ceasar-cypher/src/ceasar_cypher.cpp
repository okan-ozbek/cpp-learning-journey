//
// Created by Dorza on 2/24/2026.
//

#include "../include/ceasar_cypher.h"

#include <iostream>
#include <ostream>

namespace memory_experiments {
    ceasar_cypher::ceasar_cypher(const unsigned int shift) {
        shift_ = shift;
    }

    void ceasar_cypher::shift(std::string *message) const {
        for (char& c : *message) {
            if (c + shift_ > 'z') {
                rotate_to_start(c);
                continue;
            }

            c = {static_cast<char>(c + shift_)};
        }
    }

    void ceasar_cypher::unshift(std::string *message) const {
        for (char& c : *message) {
            if (c - shift_ < 'a') {
                rotate_to_end(c);
                continue;
            }

            c = {static_cast<char>(c - shift_)};
        }
    }

    void ceasar_cypher::rotate_to_start(char& c) const {
        const unsigned remainder = ((c + shift_) % z_);

        if (remainder > 0) {
            c = static_cast<char>(a_ + remainder - 1);
        }
    }

    void ceasar_cypher::rotate_to_end(char& c) const {
        const unsigned remainder = (a_ % (c - shift_));

        if (remainder > 0) {
            c = static_cast<char>(z_ - remainder + 1);
        }
    }

} // memory_experiments