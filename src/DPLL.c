/*
 * DPLL.c
 * Source file for the implementation of DPLL
 *
 *
 */


#include <stdio.h>
#include "DPLL.h"

/*
 * Simplify a clause set by assigning a literal to true.
 *
 * Mutates the given clause set in place:
 * - removes any clause that already contains literal (satisfied clause)
 * - removes -literal from remaining clauses
 *
 * Parameters:
 *   set: clause set to simplify
 *   literal: literal to set true
 */
static void simplifyWithLiteral(ClauseSet* set, int literal) {
    if (set == NULL) {
        return;
    }

    for (int i = 0; i < set->size;) {
        if (containsLiteral(&set->clauses[i], literal)) {
            removeClause(set, i);
            continue;
        }   
        else if (containsLiteral(&set->clauses[i], -literal)) {
            removeLiteral(&set->clauses[i], -literal);
            i++;
        }
        else {
            i++;
        }        
    }
}

/*
 * Perform iterative unit propagation on a clause set.
 *
 * Repeatedly finds unit clauses and simplifies the set using each unit
 * literal until no unit clause remains or a contradiction is produced.
 *
 * Parameters:
 *   set: clause set to propagate over
 *
 * Returns:
 *   true  when propagation completes without producing an empty clause
 *   false when propagation fails (invalid input or contradiction)
 */
static bool unitPropagate(ClauseSet* set) {
    if (set == NULL) {
        return false;
    }
    
    while (true) {
        int unitClauseIndex = findUnitClause(set);

        if (unitClauseIndex < 0) {
            return true;
        }

        Clause* unitClause = getClause(set, unitClauseIndex);
        if (unitClause == NULL) {
            return false;
        }

        int unitLiteral = getLiteral(unitClause, 0);
        if (unitLiteral == 0) {
            return false;
        }

        simplifyWithLiteral(set, unitLiteral);
        if (containsEmptyClause(set)) {
            return false;
        }
    }
    return true;
}


bool DPLL(ClauseSet* this) {
    if (this == NULL) {
        return false;
    }
    if (isEmptyClauseSet(this)) {
        return true;
    }
    else if (containsEmptyClause(this)) {
        return false;
    }
    
    ClauseSet reduced = *this;
    if (!unitPropagate(&reduced)) {
        return false;
    }
    
    if (isEmptyClauseSet(&reduced)) {
        return true;
    }

    Clause* c0 = getClause(&reduced, 0);
    if (c0 == NULL) {
        return false;
    }

    int lit = getLiteral(c0, 0);
    if (lit == 0) {
        return false;
    }
    
    ClauseSet left = reduced;
    simplifyWithLiteral(&left, lit);
    if (DPLL(&left)) {
        return true;
    }
    ClauseSet right = reduced;
    simplifyWithLiteral(&right, -lit);
    return DPLL(&right);
}
