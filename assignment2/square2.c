/* Anders Stadum
** CIS330
** Assignment 2 Part 2
** 01-20-2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocateNumberSquare(const int size, char ***square)
{
	char ** numbers;
	int i;
	*square = (char**) malloc(sizeof(char*) * size);
	numbers = * square;
	for(i = 0; i < size; i++){
		numbers[i] = (char*) malloc(sizeof(char) * size); //allocating memory for the use of our array
	}
}

void initializeNumberSquare(const int size, char **square)
{
	int i;
	for(i = 0; i < size; i++){
		memset(square[i], i, sizeof(char) * size); //populating array with values of i.
	}
}

void printNumberSquare(const int size, char **square) //basic array print
{
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%d ", square[j][i]); //assigning values into array matrix
		}
		printf("\n");
	}
}

void deallocateNumberSquare(const int size, char **square) //free memory the memory in our square array
{
	int i;
  	for (i = 0; i < size; i++) 
    	free((square)[i]);
  	free(square);
}
