/*
 * utils.cpp
 *
 *  Created on: Jan 27, 2014
 *      Author: norris
 */

#include <fstream>
#include <iostream>
#include <string>
#include "utils.hpp"

Utils::Utils(int size, std::ifstream &f)
		: clearFirst(false), data(""), size(0), row(0), col(0) {
	std::streampos cPos = f.tellg();
	std::string theline;
	this->size = size;
	getline(f, theline);
	for (int i = 0; i < size; i++) {
		getline( f, theline );
		data += theline.substr(0,size);
	}
	// reset the file stream
	f.seekg(cPos);
}

void Utils::print(int row, int col) {
	if (clearFirst)
		std::cout << std::string( data.length() + size, '\b' );

	std::string tmpMaze = data;
	tmpMaze[row*size + col] = 'x';
	for (int i = 0; i < size; i++ )
		std::cout << tmpMaze.substr(i*size,size) << std::endl;
	clearFirst = true;
}

void Utils::reset() {
	clearFirst = false;
}
