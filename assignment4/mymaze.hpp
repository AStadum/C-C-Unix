/*
** Anders Stadum
** Assignment 4
** 02/02/2014
**
*/


#ifndef __MYMAZE_HPP_
#define __MYMAZE_HPP_
#include <fstream>

class Maze{
public: 
	Maze(int size);
	~Maze() {}
	int getStartRow();
	int getStartCol();
	int getEndRow();
	int getEndCol();
	void turnRight();
	void turnLeft();
	bool mazeMove();
	void move();
	void allocateMaze();
	int getDirection();
														//Required Functions
	bool atExit();										//Returns true if you are at the end.
	void readFromFile(std::ifstream &f);				//reads the input file and stores it in a 2D array
	void step();										//our solving function
	void getCurrentPosition(int &row, int &col);		//Gets current cords

private:
	int size;											//saves size of maze
	int direction;										//stores a direction 0-3
	char ** maze;										//2D char array that stores our input file
	int x;												//x cord
	int y;												//y cord
	int startCol;										//finds starting col
	int endRow;											//finds ending row
	int startRow;										//finds starting row
	int endCol;											//finds ending col
};

#endif
