/*
 * Module interface for simple DIMACS parser implementation
 *
 */

#ifndef DIMACS_H
#define DIMACS_H

#include <stdio.h>
#include "ClauseSet.h"

#define MAX_VARS 100

/*
 * Struct to represent a DIMACS file that has been opened for parsing
 */
typedef struct DIMACS DIMACS;
struct DIMACS {
    FILE *stream;
    int number_of_clauses;
    int number_of_variables;
};


/*
 * Opens the specified file for reading and assumes a DIMACS format.
 *
 * @param filename the name of the DIMACS file to open.
 * @return a DIMACS struct representing the file stream and number of clauses and variables
 * that should be readable from the file.
 * If the function was unable to parse the DIMACS header, the stream is set to NULL.
 *
 */
DIMACS DIMACS_open(char *filename);


/*
 * Closes the stream for the given DIMACS struct.
 *
 * @param this pointer to the DIMACS struct containing the stream that is to be closed
 * @return 0 on successful completion or EOF otherwise in which case and the global variable
 * errno is set to indicate the error.
 *
 */
int DIMACS_close(DIMACS* this);


/*
 * Attempts to read the next literal from the stream specified in the DIMACS struct.
 *
 * @param this pointer to the DIMACS struct to use when attempting to parse the next literal.
 * @return the next valid literal as an integer where 0 indicates the end of a line
 * and returns MAX_VARS + 1 if no value could be read (for example when at end of stream)
 *
 */
int DIMACS_nextLiteral(DIMACS* this);


/*
 * Attempts to read all the clauses form the stream in the specified DIMACS struct into the specified ClauseSet struct.
 *
 * @param this pointer to the DIMACS struct to use when attempting to parse the next literal.
 * @param clauses pointer to the CaluseSet struct which is to be populated with clauses from the DIMACS
 * @return true on success or false otherwise
 *
 */
bool DIMACS_readClauses(DIMACS* this, ClauseSet* clauses);


#endif
