/* Anders Stadum
** CIS330
** Assignment 3 Part 1
** 01-27-2014
*/

#ifndef __MYMAZE_H_
#define __MYMAZE_H_
#include <stdbool.h>

int * findEntrance(int size, char **arrayPointer);
int moveRight(int direction);
int moveLeft(int direction);
int move(int size, char **arrayPointer,int *x, int *y);
bool canYouGo(int size, char **arrayPointer,int x, int y, int direction);

void deallocateArray(int size, char **arrayPointer);
void initializeArray(int size, char **arrayPointer, FILE *filePointer);
void allocateArray(int size, char ***arrayPointer);
void solveMaze(int size, char **arrayPointer, int x, int y);

#endif

