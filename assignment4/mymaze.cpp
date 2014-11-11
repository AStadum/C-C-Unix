/*
** Anders Stadum
** Assignment 4
** 02/02/2014
**
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "mymaze.hpp"

Maze::Maze(int size) //maze constructor
:direction(0),size(size)
{
	allocateMaze();
}

void Maze::allocateMaze() //allocate memory for array
{
	maze = (char**) malloc(size * sizeof(char*));
	
	for (int i = 0; i < size; i++)
	{
		maze[i] = (char *) malloc(size * sizeof(char));
		memset(maze[i], 0, size * sizeof(char));
	}
}


int Maze::getStartRow()
{
	//left col -> start row
	for(int i = 0; i <size; i++) 
	 {
	 	if(maze[i][0] == 'x') 
	    	return i;
	 }
	 //last row -> start row
	 for(int j = 0; j < size-1; j++) 
	 {
	 	if(maze[size-1][j] == 'x') 
	    	return size - 1;
	 }
	 //right col -> start row
	 for(int k = size-1; k > 0; k--) 
	 {
	 	if(maze[k][size-1] == 'x') 
	    	return k;
	 }
	 //first row -> start row
	 for(int m = size-1; m > 0; m--) 
	 {
	 	if(maze[0][m] == 'x') 
	    	return 0;
	 }
	 return -1;		// no start point found 
}
/* Gets the column of the start point of the maze */
int Maze::getStartCol()
{
	//first col -> start col
	for(int i = 0; i <size; i++) 
	 {
	 	if(maze[i][0] == 'x') 
	    	return 0;
	 }
	 
	 //last row -> start col
	 for(int j = 0; j < size-1; j++) 
	 {
	 	if(maze[size-1][j] == 'x') 
	    	return j;
	 }
	 
	 //last col -> start col
	 for(int k = size-1; k > 0; k--) 
	 {
	 	if(maze[k][size-1] == 'x') 
	    	return size-1;
	 }
	 
	 //first row -> start col
	 for(int m = size-1; m > 0; m--) 
	 {
	 	if(maze[0][m] == 'x') 
	    	return m;
	 }
	 return -1;	// no start point
}
/* 	Gets the row of the end point */
int Maze::getEndRow()
{
	//left col -> end row
	for(int i = 0; i <size; i++) 
	 {
	 	if(maze[i][0] == '.') 
	    	return i;
	 }
	 
	 //bottom row -> end row
	 for(int j = 0; j < size-1; j++) 
	 {
	 	if(maze[size-1][j] == '.') 
	    	return size - 1;
	 }
	 //right col -> end row
	 for(int k = size-1; k > 0; k--) 
	 {
	 	if(maze[k][size-1] == '.') 
	    	return k;
	 }
	 //top row -> end row
	 for(int m = size-1; m > 0; m--) 
	 {
	 	if(maze[0][m] == '.') 
	    	return 0;
	 }
	 return -1;	// no exit point
}
/* Gets the end column */
int Maze::getEndCol()
{
	//left col -> end col
	for(int i = 0; i <size; i++) 
	 {
	 	if(maze[i][0] == '.') 
	    	return 0;
	 }
	 //bottom row -> end col
	 for(int j = 0; j < size-1; j++) 
	 {
	 	if(maze[size-1][j] == '.') 
	    	return j;
	 } 
	 //right col -> end col
	 for(int k = size-1; k > 0; k--) 
	 {
	 	if(maze[k][size-1] == '.') 
	    	return size-1;
	 }
	 //top row -> end col
	 for(int m = size-1; m > 0; m--) 
	 {
	 	if(maze[0][m] == '.') 
	    	return m;
	 }
	 return -1;	// no end point
}

void Maze::turnLeft()			// 0 =up 1 =left 2 =up 3 =right
{
	direction = (direction+1) % 4; 
}
/* turn direction to the right */
void Maze::turnRight()
{
	direction = (direction +3) % 4;	
}

bool Maze::mazeMove() //can you move?
{
	if (direction % 2 == 1)
	{
		if (y + direction -2 < size && maze[x][y+direction-2] != '@')//finds wall
			return 1;
		else
			return 0;
	}
	else
	{
		if (x + direction -1 < size && maze[x+direction-1][y] != '@')//finds wall
			return 1;
		else
			return 0;
	}
	return 0;	
}

void Maze::move()
{
	if (direction % 2 == 1)	
		y += (direction -2);	// move east or west 1 square
	else
		x += (direction -1);	// move north or south 1 square
}

bool Maze::atExit() //reaches the end of the array
{
	if (x == 0 || y == 0 || x == size - 1 || y == size - 1)
		return true;
	else
		return false;
}

void Maze::step()
{
	turnRight();
	while(!mazeMove())
		turnLeft();
	move();
}

void Maze::getCurrentPosition(int &row, int &col) //returns the current cords in maze
{
	row = this->x;
	col = this->y;
}

void Maze::readFromFile(std::ifstream &f)
{
	for (int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{

			f >> maze[i][j];
		}
	}
	x = getStartRow();
	y = getStartCol();
	startRow = getStartRow();
	startCol = getStartCol();
	endRow = getEndRow();
	endCol = getEndCol();
}

int Maze::getDirection()
{
	return direction;
}