/* Anders Stadum
** CIS330
** Assignment 3
** 01-27-2014
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "buildArray.h"

//void mazeSolve( char[][MAX_MAZE_SIZE], const int, const int, int, int, int );

int main(int argc, const char* argv[])
{
	if( argc != 2 ) //checks for the input file name
	{
		printf( "error; no input file name\n" );
		return 1;
	}

	FILE *filePointer;
	filePointer = fopen( argv[1], "r" );
	char **arrayPointer;


	//char maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE] = { 0 };

	int numberOfTestCases = 0;
	fscanf( filePointer, "%d\n", &numberOfTestCases );

	for( int testCaseNumber = 0; testCaseNumber < numberOfTestCases; testCaseNumber++ )
	{
        int size = 0;
		fscanf( filePointer, "%d\n", &size );
		
		printf( "ENTER\n" );

        allocateArray(size, &arrayPointer);
		initializeArray(size, arrayPointer, filePointer);
		 int x = startRow(size, arrayPointer);
		 int y = startCol(size, arrayPointer);
		 int endR = endRow(size, arrayPointer);
		 int endC = endCol(size, arrayPointer);
		 solveMaze(size, arrayPointer, x, y);
		// deallocateArray(size, arrayPointer);
		

		printf( "EXIT\n***\n" );		
	}

	fclose( filePointer );
	return 0;
}