/*
 * Source file for implementation of the Clause declared in Clause.h
 */

#include "Clause.h"

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

int getLiteral(Clause* this, int index) {
    if (this == NULL) {
        return 0;
    }

    if (index < 0 || index >= this->size) {
        return 0;
    }
    
    return this->literals[index];
}

int numberOfLiterals(Clause* this) {
    if (this == NULL) {
        return 0;
    }

    return this->size;
}

bool removeLiteral(Clause* this, int literal) {
    if (this == NULL || literal == 0) {
        return false;
    }

    int write = 0;
    bool removed = false;

    for (int read = 0; read < this->size; read++) {
        if (this->literals[read] != literal) {
            this->literals[write++] = this->literals[read];
        }
        else {
            removed = true;
        }
    }
    
    this->size = write;
    return removed;    

}

bool containsLiteral(Clause* this, int literal) {
    if (this == NULL) {
        return false;
    }

    if (literal == 0) {
        return false;
    }

    for (int i = 0; i < this->size; i++) {
        if (this->literals[i] == literal) {
            return true;
        }
    }
    return false;
}

bool isEmptyClause(Clause* this) {
    if (this == NULL) {
        return false;
    }

    return this->size == 0;
}

bool isUnitClause(Clause* this) {
    if (this == NULL) {
        return false;
    }
    
    return this->size == 1;
}