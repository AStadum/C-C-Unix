/* Anders Stadum
** CIS330
** Assignment 3 Part 1
** 01-27-2014
*/

#ifndef __BUILDARRAY_H_
#define __BUILDARRAY_H_

int startRow(int size, char **arrayPointer);
int startCol(int size, char **arrayPointer);
int endRow(int size, char **arrayPointer);
int endCol(int size, char **arrayPointer);
int moveRight(int direction);
int moveLeft(int direction);
int move(int size, char **arrayPointer,int x, int y);
int canYouGo(int size, char **arrayPointer,int x, int y);

void deallocateArray(int size, char **arrayPointer);
void initializeArray(int size, char **arrayPointer, FILE *filePointer);
void allocateArray(int size, char ***arrayPointer);
void solveMaze(int size, char **arrayPointer, int x, int y);

#endif

