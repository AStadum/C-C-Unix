/*
 * utils.hpp
 *
 *  Created on: Jan 27, 2014
 *      Author: norris
 */

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include "mymaze.hpp"

class Utils {
public:
	Utils(int,std::ifstream&);
	void print(int row, int col);
	void reset();

private:
	bool clearFirst;
	std::string data;
	int size;
	int row;
	int col;
};

#endif /* UTILS_HPP_ */