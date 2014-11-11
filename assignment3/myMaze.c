/* Anders Stadum
** CIS330
** Assignment 3
** 01-27-2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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



void move(int size, char **arrayPointer,int *x, int *y, int direction)
{
	if(direction == 0){
		*x -= 1;    //UP
		printf("UP\n");
	}
	else if(direction == 1){
		*y -= 1;    //LEFT
		printf("LEFT\n");
	}
	else if(direction == 2){
		*x += 1;    //DOWN
		printf("DOWN\n");
	}
	else if(direction == 3){
		*y += 1;  	//RIGHT
		printf("RIGHT\n");
	}
	else
		direction =-99;
}

int moveLeft(int direction)				//moves curser to the left
{
	direction += 1;
	direction = direction % 4;
	return direction;
}

int moveRight(int direction)			//moves curser to the right
{ 
	direction += 3;
	direction = direction % 4;
	return direction;
}

bool canYouGo(int size, char **arrayPointer,int x, int y, int direction)
{
	if(direction == 3) 									//if moved in right direction
		{if(y < size && arrayPointer[x][y+1] != '@') //check right
				{
					return 1;
				}
				else 
					return 0;}
	if(direction == 0)									//if moved in up direction
		{if(x >= 0 && arrayPointer[x-1][y] != '@') //check up
				{
					return 1;
				}
				else
					return 0;}
	if(direction == 1)									//if moved in left direction
		{if(y >= 0 && arrayPointer[x][y-1] != '@') //check left
				{
					return 1;
				}
				else
					return 0;}
	if(direction == 2)									//if moved in down direction
		{if(x < size && arrayPointer[x+1][y] != '@') //check down
				{
					return 1;
				}
				else
					return 0;}
	return -99;							//have to return something or I get an error
}

int * findEntrance(int size, char **arrayPointer) //find entrance into the maze... check for x, then assign cords
{

	int *xy;
	xy = (int*) malloc(sizeof(int)*2);
	for(int i = 0; i < size; i++)
	{
		if(arrayPointer[0][i] == 'x')
		{
			xy[0] = i;
			xy[1] = 0;
		}
		if(arrayPointer[size - 1][i] == 'x'){
			xy[0] = i;
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
	return xy;			//return cords
}

void solveMaze(int size, char **arrayPointer, int x, int y)
{	
	int finished = 0;
	int direction = 0;

	while(finished != 1) //while not finished with the maze, move right.
	{
		direction = moveRight(direction);

		while(!canYouGo(size, arrayPointer, x, y, direction)) //when you can't can't go in this direction, move left.
			direction = moveLeft(direction);
		

		move(size, arrayPointer, &x, &y,direction);
		if(x == 0 || y == 0) //you found the end
			finished = 1;
		if(x == size - 1 || y == size - 1) //you found the end
			finished = 1;
	}
}
