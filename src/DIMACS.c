/*
  Source file for simple DIMACS parser implementation.

  The DIMACS format is a format for storing SAT problems
  This parser might not handle every slightly badly formatted
  SAT instance out there!

  Here is an example of a DIMACS file:

c example cnf file
c
p cnf 3 2
1 -3 0
2 3 -1 0

  The format is:
  Lines that start c are comments. They can only appear at the start
  The 'p' line defines the problem. For us it always starts 'p cnf' followed by
  the number of variables and number of clauses. Variables are represented by
  integers, so if you have N variables, these will be 1..N. Lastly, the file
  contains a line for each clause.

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "DIMACS.h"
#include "ClauseSet.h"

#define BUFF_SIZE 1000



/*
 * static helper functions
 */


static void readLine(char* buffer, int buf_size, FILE* stream) {
    // clear buffer to make sure we do not get tricked by
    // fgets not reading
    memset(buffer, 0, buf_size);

    fgets(buffer, buf_size, stream);

    if (strlen(buffer) <= 1) {
        printf("Blank line!");
        exit(1);
    }

    if (buffer[strlen(buffer) - 1] != '\n' && !feof(stream)) {
        printf("Line too long for buffer!\n");
        exit(1);
    }
}


/*
 * non-static (functions that are listed in the header file (module interface)
 */

 
DIMACS DIMACS_open(char *filename) {
    DIMACS this = {NULL, -1, -1};
    FILE *stream = fopen(filename, "r");
    if (stream != NULL) {
        char buffer[BUFF_SIZE];
        do {
            readLine(buffer, BUFF_SIZE, stream);
        } while(buffer[0] == 'c');

        int number_of_variables, number_of_clauses;
        if(sscanf(buffer, "p cnf %d %d", &number_of_variables, &number_of_clauses) != 2) {
            printf("Invalid p line: '%s'\n", buffer);
            exit(1);
        }
        this.stream = stream;
        this.number_of_clauses = number_of_clauses;
        this.number_of_variables = number_of_variables;
    }
    return this;
}


int DIMACS_close(DIMACS* this) {
    return fclose(this->stream);
}


int DIMACS_nextLiteral(DIMACS* this) {
    int literal;
    if (fscanf(this->stream, "%d", &literal) == 1) {
        return literal;
    }
    return MAX_VARS + 1;
}


bool DIMACS_readClauses(DIMACS* this, ClauseSet* clauses) {
    if (this->number_of_clauses > MAX_CLAUSES) {
        return false;
    }
    if (this->number_of_variables > MAX_LITERALS) {
        return false;
    }
    for(int i = 1 ; i <= this->number_of_clauses ; i++) {
        Clause c = new_Clause();
        int read_val = DIMACS_nextLiteral(this);
        while(read_val) {
            if(!addLiteral(&c, read_val)) {
                return false;
            }
            read_val = DIMACS_nextLiteral(this);
        }
        if(!addClause(clauses, c)) {
            return false;
        }
    }
    return true;
}