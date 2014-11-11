/* Anders Stadum
** CIS330
** Assignment 2 Part 2
** 01-20-2014
*/

#ifndef __SQUARE2_H_
#define __SQUARE2_H_

/* Allocate a square of size "size" (a 2-D array of char) */
void allocateNumberSquare(const int size, char ***square);

/* Initialize the 2-D square array */
void initializeNumberSquare(const int size, char **square);

/* Print a formatted square */
void printNumberSquare(const int size, char **square);

/* Free the memory for the 2-D square array */
void deallocateNumberSquare(const int size, char **square);

#endif
