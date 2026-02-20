/*
 * Source file for implementation of the Clause declared in Clause.h
 */

#include "Clause.h"

// TODO: Implement all the the functions declared in the Clause.h interface
Clause new_Clause() {
    Clause clause = {.size = 0};
    return clause;
}

bool addLiteral(Clause* this, int literal) {
    if (this == NULL) {
        return false;
    }

    if (literal == 0) {
        return false;
    }

    if (this->size >= MAX_LITERALS) {
        return false;
    }

    this->literals[this->size++] = literal;
    return true;
}

