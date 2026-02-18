/*
 * Header file (module interface) for a set of clauses
 */

#include <stdbool.h>
#include <stdio.h>

#ifndef CLAUSESET_H_
#define CLAUSESET_H_

#include "Clause.h"

/* Maximum number of clauses you can have in a clause set*/
#define MAX_CLAUSES 100

typedef struct ClauseSet ClauseSet;

/* TODO: Define ClauseSet struct*/
struct ClauseSet {
};


/*
 * Creates a new empty ClauseSet
 * @return the new empty clause set
 */
ClauseSet new_ClauseSet();


/*
 * Adds a clause to the specified ClauseSet
 * @param this a pointer to the ClauseSet to which to add the given clause
 * @param clause the clause to add
 * @return true if clause was added successfully, false otherwise
 */
bool addClause(ClauseSet* this, Clause clause);


/*
 * Removes
 * @param this a pointer to the ClauseSet
 * @return true if the clause was successfully removed
 * @return false if no clause was removed
 */
bool removeClause(ClauseSet* this, int index);


/*
 * Gets the specified clause (by index) from the given clause
 * @param this a pointer to the ClauseSet
 * @param the index of the clause to get
 * @return a pointer to Clause with given index in the ClauseSet or NULL if one doens't exist
 */
Clause* getClause(ClauseSet* this, int index);


/*
 * Gets the number of clauses in the given ClauseSet.
 * @param this a pointer to the ClauseSet
 * @return the current size of the given ClauseSet
 */
int numberOfClauses(ClauseSet* this);


/*
 * Checks whether the given ClauseSet is empty
 * @param a pointer to the ClauseSet to check
 * @return true if the specified ClauseSet is empty
 *
 */
bool isEmptyClauseSet(ClauseSet* this);


/*
 * Checks whether the ClauseSet contains at least one empty clause
 * @param this a pointer to the ClauseSet to check
 * @return true if this ClauseSet contains at least one empty clause
 */
bool containsEmptyClause(ClauseSet* this);


/*
 * Attempts to find a unit clause in the given ClauseSet and return its index
 * @param this a pointer to the ClauseSet to search
 * @return the index of a unit clause (if one exists in the given ClauseSet)
 */
int findUnitClause(ClauseSet* this);


#endif /* CLAUSESET_H_ */
