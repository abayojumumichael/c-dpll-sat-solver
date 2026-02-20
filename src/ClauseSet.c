/*
 * Source file for implementation of the ClauseSet declared in ClauseSet.h
 */

#include "ClauseSet.h"

// TODO: Implement all the the functions declared in the ClauseSet.h interface

ClauseSet new_ClauseSet() {
    ClauseSet clauseSet = {.size = 0};
    return clauseSet;
}

bool addClause(ClauseSet* this, Clause clause) {
    if (this == NULL) {
        return false;
    }
    
    if (this->size >= MAX_CLAUSES) {
        return false;
    }

    this->clauses[this->size++] = clause;
    return true;
}

bool removeClause(ClauseSet* this, int index) {
    if (this == NULL) {
        return false;
    }
    
    if (index < 0 || index >= this->size) {
        return false;
    }
    
    for (int i = index; i < this->size - 1; i++) {
        this->clauses[i] = this->clauses[i + 1];
    }
    this->size--;
    return true;
}

Clause* getClause(ClauseSet* this, int index) {
    if (this == NULL) {
        return NULL;
    }

    if (index < 0 || index >= this->size) {
        return NULL;
    }

    return &this->clauses[index];
}

int numberOfClauses(ClauseSet* this) {
    if (this == NULL) {
        return 0;
    }

    return this->size;
}

bool isEmptyClauseSet(ClauseSet* this) {
    if (this == NULL) {
        return false;
    }
    
    return this->size == 0;
}

bool containsEmptyClause(ClauseSet* this) {
    if (this == NULL) {
        return false;
    }
    
    for (int i = 0; i < this->size; i++) {
        if (isEmptyClause(&this->clauses[i])) {
            return true;
        }
    }
    return false;
}

int findUnitClause(ClauseSet* this) {
    if (this == NULL) {
        return -1;
    }    

    for (int i = 0; i < this->size; i++) {
        if (isUnitClause(&this->clauses[i])) {
            return i;
        }
    }
    return -1;
}