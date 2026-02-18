/*
 * DPLL.h
 *
 * This is the module interface to the DPLL implementation
 */

#include "ClauseSet.h"

/*
 * Run DPLL over the given ClauseSet
 * @param this a pointer to the ClauseSet to check
 * @return true if the ClauseSet is satisfiable and false otherwise
 */
bool DPLL(ClauseSet* this);

