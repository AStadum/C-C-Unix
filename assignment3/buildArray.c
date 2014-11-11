/* Anders Stadum
** CIS330
** Assignment 3 Part 1
** 01-27-2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocateArray(int size, char ***arrayPointer)
{
	char ** numbers;
	int i;
	* arrayPointer = (char**) malloc(sizeof(char*) * size);
	numbers =  *arrayPointer;
	for(i = 0; i < size; i++){
		numbers[i] = (char*) malloc(sizeof(char) * size);
	}
}

void initializeArray(int size, char **arrayPointer, FILE *filePointer)
{
	char mem;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j <= size; j++)
		{
			fscanf(filePointer, "%c", &mem);
			arrayPointer[i][j] = mem;
		}
	}
}

void deallocateArray(int size, char **arrayPointer)
{
	int i;
  	for (i = 0; i < size; i++) 
    	free((arrayPointer)[i]);
  	free(arrayPointer);
}



void move(int size, char **arrayPointer,int x, int y, int direction)
{
	if(direction == 0){
		x -= 1;    //UP
		printf("UP\n");
	}
	if(direction == 1){
		y -= 1;    //LEFT
		printf("LEFT\n");
	}
	if(direction == 2){
		x += 1;    //DOWN
		printf("DOWN\n");
	}
	if(direction == 3){
		y += 1;  	//RIGHT
		printf("RIGHT\n");
	}
}

int moveLeft(int direction)
{
	direction += 1;
	direction = direction % 4;
	return direction;
}

int moveRight(int direction)
{ 
	direction += 3;
	direction = direction % 4;
	return direction;
}

int canYouGo(int size, char **arrayPointer,int x, int y)
{
	if(y < size && arrayPointer[x][y+1] == '@') //check right
	{
		return 1;
	}
	if(y < size && arrayPointer[x][y] == '@')  //check right
	{
		return 1;
	}
	else 
		return 0;
	if(x >= 0 && arrayPointer[x-1][y] == '@') //check up
	{
		return 1;
	}
	else
		return 0;
	if(y >= 0 && arrayPointer[x][y-1] == '@') //check left
	{
		return 1;
	}
	else
		return 0;
	if(x < size && arrayPointer[x+1][y] == '@') //check down
	{
		return 1;
	}
	else
		return 0;
}

void solveMaze(int size, char **arrayPointer, int x, int y)
{	
	int finished = 0;
	int direction = 0;

	//while(finished != 1){
		direction = moveRight(direction);
		canYouGo(size, arrayPointer, x, y);
		
		//	direction = moveLeft(direction);
		
		move(size, arrayPointer, x, y,direction);
		if(x == 0 || y == 0)
			finished = 1;
		if(x == size - 1 || y == size - 1)
			finished = 1;
	//}

}

int * findEntrance(int size, char **arrayPointer){

	int *xy;
	xy = (int*) malloc(sizeof(int)*2);
	for(int i = 0; i < size; i++)
	{
		if(arrayPointer[0][i] == 'x')
		{
			xy[0] = i;
			xy[1] = 0;
		}
		if(arrayPointer[size - 1][x] == 'x'){
			xy[0] = x;
			xy[1] = size - 1;
		}
	}

	for(int j = 0; j < size; j++)
	{
		if(arrayPointer[j][0] == 'x')
		{
			xy[0] = 0;
			xy[1] = j;
		}
		if(arrayPointer[size - 1][j] == 'x'){
			xy[0] = size - 1;
			xy[1] = j;
		}
	}
}



int startRow(int size, char **arrayPointer)
{
	for(int i = 0; i < size; i++)
	{
		if(arrayPointer[i][0] == 'x')
		{
			return i;
		}
	}

	for(int i = 0; i < size; i++)
	{
		if(arrayPointer[i][size-1] == 'x')
		{
			return i;
		}
	}
	return -99;
}

int startCol(int size, char **arrayPointer)
{
	for(int i = 0; i < size; i++)
	{
		if(arrayPointer[0][i] == 'x')
		{
			return i;
		}
	}

	for(int i = 0; i < size; i++)
	{
		if(arrayPointer[size - 1][i] == 'x')
		{
			return i;
		}
	}
	return -99;
}

int endRow(int size, char **arrayPointer)
{
	for(int i = 0; i < size; i++)
	{
		if(arrayPointer[i][0] == '.')
		{
			return i;
		}
	}

	for(int i = 0; i < size; i++)
	{
		if(arrayPointer[size - 1][0] == '.')
		{
			return i;
		}
	}
	return -99;
}

int endCol(int size, char **arrayPointer)
{
	for(int i = 0; i < size; i++)
	{
		if(arrayPointer[0][i] == '.')
		{
			return i;
		}
	}

	for(int i = 0; i < size; i++)
	{
		if(arrayPointer[0][size - 1] == '.')
		{
			return i;
		}
	}
	return -99;
}