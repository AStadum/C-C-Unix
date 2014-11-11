/* Anders Stadum
** CIS330
** Assignment 2 Part 2
** 01-20-2014
*/
#include <stdio.h>
#include <stdlib.h>
#include "square2.h"
#include "square1.h"
#include "diamond.h"

int main()
{
	int byte = 128;
	char* input = (char*)malloc(128 + 1); //plus one for null terminator byte
	int inputD;
	char** square;

	 // Problem 1
  	printf("Problem 1 (a square of size 10):\n"); /* Fixed-size square */
  	print10Square();

	do
	{
		printf("Please enter the size of the square [2-10]: ");
		fgets(input,byte,stdin);
		inputD = atoi(input); //converts the string to integer so we dont get segfaults when letters are inputted.
	}
	while(inputD < 2 || inputD > 10); //test values between 2 and 10

	
	allocateNumberSquare((const int)inputD, &square); //cast correct data types
	initializeNumberSquare((const int)inputD, square);
	printNumberSquare((const int)inputD, square);
	printNumberDiamond((const int)inputD,square);
	deallocateNumberSquare((const int)inputD, square);
	free(input);
	return 0;
}
