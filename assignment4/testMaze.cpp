/*
** Anders Stadum
** Assignment 4
** 02/02/2014
**
*/


#include <iostream>  // needed
#include <fstream>   // needed to read from a file
#include "mymaze.hpp"

int main(int argc, const char *argv[]) {
	if( argc != 2 ) //checks for the input file name
	{
		std::cerr << "Error: no input file name" << std::endl;
		std::cerr << "Usage: ./" << argv[0] << " someinput.txt" << std::endl;
		return 1;
	}

	std::ifstream mazeInputFile ( argv[1] );	// open the input file
	int numberOfMazes = 0;
	mazeInputFile >> numberOfMazes; 			// read the number of mazes

	for (int currentMaze = 0; currentMaze < numberOfMazes; currentMaze++ ) {
		int mazeSize = 0;
		mazeInputFile >> mazeSize;				// read the maze size from the input file

		//std::cout << "size = " << mazeSize << std::endl;

		if (mazeSize < 10 || mazeSize > 30) {
			std::cerr << "Error: invalid maze size " << mazeSize << " read from " << argv[1] << std::endl;
			std::cerr << "     Maze sizes must be between 10 and 30" << std::endl;
			return 1;
		}

		Maze maze(mazeSize);
		maze.readFromFile(mazeInputFile);

		std::string dir[] = {"UP", "LEFT", "DOWN", "RIGHT"};
		std::cout << "ENTER" << std::endl;
		do {
			// std::cout << "ENTER" << std::endl;
			maze.step();
			std::cout << dir[maze.getDirection()] << std::endl;

		} while ( ! maze.atExit() );
		std::cout << "EXIT" << std::endl;
		std::cout << "***" << std::endl;
	}
}