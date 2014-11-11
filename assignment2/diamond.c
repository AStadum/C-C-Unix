/* Anders Stadum
** CIS330
** Assignment 2 Part 3
** 01-20-2014
*/

#include <stdio.h>
#include <stdlib.h>


void printNumberDiamond(const int size, char **square)
{
	int i, j, k, l , m, n, temp;

	temp = size; //globally assigning temp variable to size
	temp--; // decrement temp
	if((size%2) == 0) //if inputted number is even, decrement the size
	{
		temp--;
	}	

	for(k = 0; k < size; k+=2) //Start diamond with zero, print until it is the inputted size, increment by 2.
	{
		for(n = 0; n < size - k; n++) //Padding. Start triangle at 0, pad the difference between the size and our control loop k.
		{
			printf(" ");
		}

		for(l = 0; l <= k; l++) //assigns values to array then prints
		{
			printf("%d ", square[l][k]);
		}
		printf("\n");
	}

	if((size%2) != 0) //if inputted number is not even, decrement size by  two.
	{
		temp -= 2;
	}

	for(i = temp; i >= 0; i-=2) //first value will be initialized at the max size, then decrement max by 2.
	{
		for(m = 0; m < size - i; m++) //Padding. Start triangle at size, pad the difference between the size and our control loop i
		{
			printf(" ");
		}

		for(j = 0; j <= i; j++) //assign values to array then prints
		{
			printf("%d ", square[j][i]);
		}
		printf("\n");

	}
}