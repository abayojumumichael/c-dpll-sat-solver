/*
 * DPLLMain.c
 *
 * Program entry point for running the DPLL SAT solver on a DIMACS CNF file.
 *
 * Expected usage:
 *   ./program <path-to-dimacs-file>
 *
 * The program reads the CNF formula from the given file, runs DPLL, and
 * prints "true" if satisfiable, otherwise "false".
 */


#include "DPLL.h"
#include "DIMACS.h"

/*
 * Run DPLL on a CNF instance loaded from a DIMACS file.
 *
 * Precondition:
 *   A valid DIMACS filename is provided in argv[1].
 */
int main(int argc, char *argv[]) {
    char* filename = argv[1];
    DIMACS file = DIMACS_open(filename);
    ClauseSet cnf = new_ClauseSet();
    DIMACS_readClauses(&file, &cnf);
    if (DPLL(&cnf)) {
        printf("true");
    }
    else {
        printf("false");
    }

    return 0;
}

