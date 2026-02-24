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
    if (argc != 2) {
        printf("Input Error\n");
        return 0;
    }
    
    char* filename = argv[1];
    DIMACS file = DIMACS_open(filename);
    ClauseSet cnf = new_ClauseSet();

    if (!DIMACS_readClauses(&file, &cnf)) {
        DIMACS_close(&file);
        printf("Input Error\n");
        return 0;
    }

    if (DPLL(&cnf)) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }

    return 0;
}
