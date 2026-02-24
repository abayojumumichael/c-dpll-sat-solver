CC=clang
CFLAGS=-Wall -Wextra -c -g
EXEC=DPLLMain


DPLLMain: DPLLMain.o DPLL.o DIMACS.o ClauseSet.o Clause.o 
	$(CC) -o DPLLMain DPLLMain.o DPLL.o DIMACS.o ClauseSet.o Clause.o

DPLLMain.o: DPLLMain.c
	$(CC) $(CFLAGS) DPLLMain.c

DPLL.o: DPLL.c DPLL.h
	$(CC) $(CFLAGS) DPLL.c

DIMACS.o: DIMACS.c DIMACS.h
	$(CC) $(CFLAGS) DIMACS.c

ClauseSet.o: ClauseSet.c ClauseSet.h
	$(CC) $(CFLAGS) ClauseSet.c

Clause.o: Clause.c Clause.h
	$(CC) $(CFLAGS) Clause.c

clean:
	rm -f DPLLMain *.o
