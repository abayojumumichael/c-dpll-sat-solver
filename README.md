# DPLL SAT Solver

An implementation of a SAT solver using the Davis-Putnam-Logemann-Loveland (DPLL) algorithm.

The solver reads a propositional formula in **DIMACS CNF** format and prints:

- `true` for satisfiable formulas
- `false` for unsatisfiable formulas

## Features

- DIMACS CNF parser (`DIMACS.c`)
- Clause and clause-set data structures (`Clause.*`, `ClauseSet.*`)
- Core DPLL search
- Unit propagation
- Recursive branching on a literal
- Basic input/error handling in the executable entrypoint (`DPLLMain.c`)

## Project Structure

- `src/DPLLMain.c`: program entrypoint and CLI handling
- `src/DPLL.c`, `src/DPLL.h`: DPLL implementation
- `src/DIMACS.c`, `src/DIMACS.h`: DIMACS parser
- `src/Clause.c`, `src/Clause.h`: clause operations
- `src/ClauseSet.c`, `src/ClauseSet.h`: clause set operations
- `src/example1.cnf`, `src/example2.cnf`, `src/example3.cnf`: sample SAT instances
- `src/Makefile`: build rules

## Requirements

- `clang`
- `make`

## Build

From the repository root:

```bash
make -C src
```

This produces the executable:

```text
src/DPLLMain
```

Clean build artifacts with:

```bash
make -C src clean
```

## Usage

```bash
./src/DPLLMain <path-to-dimacs-file>
```

Example:

```bash
./src/DPLLMain src/example1.cnf
```

If the command-line arguments are invalid or parsing fails, the program prints:

```text
Input Error
```

## Example Runs

```bash
./src/DPLLMain src/example1.cnf  # true
./src/DPLLMain src/example2.cnf  # true
./src/DPLLMain src/example3.cnf  # false
```

## DIMACS Input Notes

Expected format:

1. Optional comment lines starting with `c`
2. Header line: `p cnf <num_variables> <num_clauses>`
3. Exactly `<num_clauses>` clauses, each terminated by `0`

Example:

```text
c simple example
p cnf 3 2
1 -2 0
-1 2 3 0
```

## Current Limits

The code uses fixed-size arrays:

- Maximum variables: `100` (`MAX_VARS`)
- Maximum literals per clause: `100` (`MAX_LITERALS`)
- Maximum clauses: `100` (`MAX_CLAUSES`)

Formulas exceeding these limits are rejected.