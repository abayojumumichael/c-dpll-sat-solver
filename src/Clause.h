/*
 * Clause.h
 *
 * Module interface for a single Clause
 *
 */

#ifndef CLAUSE_H_
#define CLAUSE_H_

#include <stdbool.h>

/* Maximum number of literals you can have in a clause */
#define MAX_LITERALS 100

typedef struct Clause Clause;

/* Defines the Clause struct*/
struct Clause {
    int literals[MAX_LITERALS];
    int size;
};


/*
 * Returns the new empty clause.
 */
Clause new_Clause();

/*
 * Adds a literal to the specified clause.
 * @param this a pointer to the clause to which to add the literal
 * @param literal the literal to add
 * @return true if literal was added successfully, false otherwise
 *
 * A literal is an integer (except 0) with positive integers
 * representing non-negated variables and negative integers
 * representing negated variables.
 * Variable numbers should be in the range 1 .. "number of variables" as specified in the DIMACS file.
 * See DIMACS.c
 */
bool addLiteral(Clause* this, int literal);


/*
 * Returns the literal at the specified index in the specified clause.
 * @param this a pointer to the clause
 * @param index the index of the literal to return
 * @return the literal at the specified index in this clause or 0 on failure.
 */
int getLiteral(Clause* this, int index);


/*
 * Returns the number of literals in the specified clause.
 * @param this a pointer to the clause
 * @return the number of literals in this clause
 */
int numberOfLiterals(Clause* this);


/*
 * Removes a literal from the specified clause.
 * @param this a pointer to the clause from which to remove the literal
 * @param literal the literal to remove
 * @return false if the given literal was not in the clause
 *
 * When true is returned, ALL occurrences of the given literal should
 * have been removed from the clause.
 * The order of remaining literals is not specified.
 */
bool removeLiteral(Clause* this, int literal);


/*
 * Returns true if the specified clause contains the given literal
 * @param this a pointer to the clause to check
 * @param literal the literal to check
 * @return true if literal was in the clause
 */
bool containsLiteral(Clause* this, int literal);


/*
 * Checks whether a clause is empty or not
 * @param this a pointer to the clause to check
 * @return true if this clause is empty
 */
bool isEmptyClause(Clause* this);


/*
 * Checks whether a clause is a unit clause
 * @param this a pointer to the clause to check
 * @return true if this clause is a unit clause
 */
bool isUnitClause(Clause* this);


#endif /* CLAUSE_H_ */
